#include <iostream>

#define FLIP_ONE_PANCAKE(x) (((x) == '+') ? '-' : '+')

void flipPancakes(std::string& pancakes, int nPancakeFromTop) {
  for (int i = 0; i < (nPancakeFromTop >> 1); i++) {
    int indexToSwap = nPancakeFromTop - i - 1;
    char tmp = pancakes[indexToSwap];
    pancakes[indexToSwap] = FLIP_ONE_PANCAKE(pancakes[i]);
    pancakes[i] = FLIP_ONE_PANCAKE(tmp);
  }

  if (nPancakeFromTop & 1) {
    int centerIndex = (nPancakeFromTop >> 1);
    pancakes[centerIndex] = FLIP_ONE_PANCAKE(pancakes[centerIndex]);
  }
  /*
  std::cout << "fliped first " << nPancakeFromTop << " pancakes:" << pancakes
            << std::endl;
  */
}

int main(int argc, char** argv) {
  int T;
  std::cin >> T;
  for (int i = 0; i < T; i++) {
    std::string pancakes;
    std::cin >> pancakes;

    int len = pancakes.length();

    // std::cout << pancakes << std::endl;

    bool done = false;
    int nFlip = 0;
    while (!done) {
      if (pancakes[0] != pancakes[len - 1]) {
        int j = len - 2;
        for (; j >= 0; j--) {
          if (pancakes[j] == pancakes[0]) {
            break;
          }
        }
        flipPancakes(pancakes, j + 1);
        nFlip++;
      } else {
        int j = 1;
        for (; j < len; j++) {
          if (pancakes[0] != pancakes[j]) {
            break;
          }
        }
        if (j == len) {
          nFlip += (pancakes[0] == '+') ? 0 : 1;
          done = true;
        } else {
          flipPancakes(pancakes, j);
          nFlip++;
        }
      }
    }
    std::cout << "Case #" << i + 1 << ": " << nFlip << std::endl;
  }
  return 0;
}
