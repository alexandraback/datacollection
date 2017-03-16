#include <cstdlib>
#include <iostream>
#include <tr1/memory>
#include <vector>
#include <map>

typedef std::vector<unsigned int> Row;
typedef std::vector<Row> Table;

int main (int argc, char** argv) {

  int T;
  std::cin >> T;

  for (unsigned int t = 0; t < T; ++t) {
    int N, M;
    std::cin >> N >> M;
    Table table(N, Row(M));
    for (unsigned int n = 0; n < N; ++n) {
      for (unsigned int m = 0; m < M; ++m) {
        std::cin >> table[n][m];
      }
    }

    Table check(N, Row(M, false));
    for (unsigned int n = 0; n < N; ++n) {
      unsigned int max = 0;
      for (unsigned int m = 0; m < M; ++m) {
        if (table[n][m] > max) {
          max = table[n][m];
        }
      }
      for (unsigned int m = 0; m < M; ++m) {
        if (table[n][m] == max) {
          check[n][m] = true;
        }
      }
    }
    for (unsigned int m = 0; m < M; ++m) {
      unsigned int max = 0;
      for (unsigned int n = 0; n < N; ++n) {
        if (table[n][m] > max) {
          max = table[n][m];
        }
      }
      for (unsigned int n = 0; n < N; ++n) {
        if (table[n][m] == max) {
          check[n][m] = true;
        }
      }
    }

    std::cout << "Case #" << t + 1 << ": ";
    bool result = true;
    for (unsigned int n = 0; n < N; ++n) {
      for (unsigned int m = 0; m < M; ++m) {
        if (!check[n][m]) {
          result = false;
        }
      }
    }
    std::cout << (result ? "YES" : "NO") << std::endl;
  }

  return EXIT_SUCCESS;
}

