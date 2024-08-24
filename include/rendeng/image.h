#ifndef IMAGE_H
#define IMAGE_H

#define MAX_IMAGE_WIDTH 1000
#define MAX_IMAGE_HEIGHT 1000

typedef struct RGB_COLOR {
  float r;
  float g;
  float b;
} rgb_color;

// RGB color
typedef struct COLOR {
  unsigned char r;
  unsigned char g;
  unsigned char b;
} color;

// a 2d array of pixels with a given width and height
typedef struct IMAGE {
  int width;
  int height;
  color* pixels; // array of size width * height
} image;

// creates a new image with the given width and height. the caller must free
// the image with free_image
extern image* new_image(int width, int height);

// frees the memory of the given image
extern void free_image(image* img);

// sets the pixel at the given x and y coordinates to the given color
extern void set_image_pixel(image* img, int x, int y, color c);

// gets the pixel at the given x and y coordinates
extern color get_image_pixel(image* img, int x, int y);

// writes the given image to the given file in the PPM format
extern void save_image(image* img, const char* filename);

#endif
