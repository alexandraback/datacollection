#include <iostream>


int main () {
  int T;

  std::cin >> T;
  while (std::cin.get() != '\n');

  for (int t = 1; t <= T; ++t) {
    int lastState = std::cin.get();
    int flips = 0;

    for (int state; (state = std::cin.get()) != '\n'; ) {
      if (lastState != state) {
        lastState = state;
        flips += 1;
      }
    }

    flips += (lastState == '-');

    std::cout << "Case #" << t << ": " << flips << '\n';
  }
}
