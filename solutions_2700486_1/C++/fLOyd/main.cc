#include <iostream>
#include <iomanip>
#include <cstdlib>

#define debug(x) std::cerr << #x << " = " << (x) << "\n"

double f[2][100000];

double solve() {
  memset(f, 0, sizeof(f));
  int N, X, Y;
  std::cin >> N >> X >> Y;
  if (Y < 0) return 0;
  if (abs(X) % 2 != Y % 2) return 0;

  int layer = 1, ds = 1, ds0 = 0;
  while (N > ds) {
    layer++;
    ds0 = ds;
    ds += layer * 2 - 1 + layer * 2 - 2;
  }
  int query_layer = (abs(Y) + abs(X)) / 2 + 1;
  if (query_layer < layer) return 1;
  if (query_layer > layer) return 0;

  if (X == 0) return (N == ds);
  if (N == ds) return 1;

  N = N - ds0;
  int full = layer * 2 - 2, current, last;


  //debug(full);
  //debug(N);

  int height = abs(Y) + 1;

  double res = 0;

  f[0][0] = 1;
  for (int i = 1; i <= N; ++i) {
    current = i & 1;
    last = 1 - current;
    for (int left = 0; left <= i && left <= full; ++left) {
      if (i - left <= full) {
        if (left > 0) {
          if (i - 1 - (left - 1) < full) {
            f[current][left] = f[last][left - 1] / 2;
          } else {
            f[current][left] = f[last][left - 1];
          }
        } else {
          f[current][left] = 0;
        }

        if (left < full) {
          f[current][left] += f[last][left] / 2;
        } else {
          f[current][left] += f[last][left];
        }

      } else {
        f[current][left] = 0;
      }
      //std::cout << i << ", " << left << " = " << f[current][left] << std::endl;
    }
  }
  for (int left = height; left <= full && left <= N; ++left) {
    res += f[current][left];
  }
  return res;
}

int main(int argc, char *argv[]) {
  int T;
  std::cin >> T;
  for (int i = 1; i <= T; ++i) {
    std::cout << "Case #" << i << ": " << std::setprecision(9) << solve() << std::endl;
  }
  return 0;
}
