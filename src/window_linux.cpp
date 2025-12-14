#include <GLFW/glfw3.h>
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>

// Function for error behavior
void error_callback(int error, const char *description) {
  fprintf(stderr, "Error: %s\n", description);
}

// Function for key functions defenitions
void key_callback(GLFWwindow *window, int key, int scancode, int action,
                  int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    glfwWindowShouldClose(window);
  }
}

void setWindow(int with, int heigth, const char *title) {

  // Define glfw behavior on error ocurrence
  glfwSetErrorCallback(error_callback);

  // Initialize the library
  if (!glfwInit())
    exit(EXIT_FAILURE);

  // Create a windowed mode window and its OpenGL context
  GLFWwindow *window = glfwCreateWindow(with, heigth, title, NULL, NULL);
  if (!window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  // Define key behaviorS
  glfwSetKeyCallback(window, key_callback);
  // Make the window's context current
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);

  // Loop while window not destroyed
  while (!glfwWindowShouldClose(window)) {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    // Swap front and back buffers -- we write in back buffer and then move to
    // front buffer
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();
  }

  // Terminate and free resources
  glfwTerminate();
}
