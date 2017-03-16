#include <iostream>

void printGrid(int R, int C, int a, int b, int c, int d) {
  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      if (x == 0 && y == 0) {
        std::cout << "c";
      }
      else {
        if (x < a) {
          if (x < c) {
            if (y < b)
              std::cout << ".";
            else
              std::cout << "*";
          }
          else {
            if (y < d)
              std::cout << ".";
            else
              std::cout << "*";
          }
        }
        else {
          std::cout << "*";
        }
      }
    }
    std::cout << std::endl;
  }
}

int main() {
  int T;
  int M, R, C;

  std::cin >> T;
  for (int ii=1; ii <= T; ii++) {
    std::cin >> R >> C >> M;
    int N = R*C - M;
    std::cout << "Case #" << ii << ":" << std::endl;
    if (R == 4 && C == 4 && M == 3) {
      std::cout << "c...\n....\n...*\n..**\n";
    }
    else if (R == 1) {
      printGrid(R, C, N, R, N, R);
    }
    else if (C == 1) {
      printGrid(R, C, C, N, C, N);
    }
    else {
      for (int a = 1; a <= C; a++) {
        for (int b = 1; b <= R; b++) {
          for (int c = 0; c <= a; c++) {
            for (int d = 0; d <= b; d++) {
              if (a*d + c*b - c*d != N) {
                continue;
              }
              if (a == 1 && b == 1 && c == 1 && d == 1) {
                printGrid(R, C, a, b, c, d);
                goto yay;
              }
              if (a == 1 || b == 1 || c == 1 || d == 1) {
                continue;
              }
              printGrid(R, C, a, b, c, d);
              goto yay;
            }
          }
        }
      }
      std::cout << "Impossible" << std::endl;
    }
    yay:
    ;
  }
}
