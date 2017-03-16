#include <iostream>
#include <map>

int a[100];
int per;
int R, N, M, K;
int p[12];

bool generate(int n, int pos) {
  if (n == 0) {
    std::map<int, int> hash;
    for (int i = 0; i < per; ++i) {
      int tmp = i;
      int product = 1;
      int k = 0;

      while (tmp) {
        if (tmp & 1) product *= a[k];
        ++k;
        tmp >>= 1;
      }

      hash[product] = 1;
    }

    for (int i = 0; i < K; ++i) if (hash[p[i]] == 0) {
      return false;
    }
    for (int i = 0; i < N; ++i) std::cout << a[i];
    std::cout << std::endl;
    return true;
  }

  for (int i = 2; i <= M; ++i) { 
    a[pos] = i;
    if (generate(n - 1, pos + 1)) {
      return true;
    }
  }
  return false;
}

int main() {
  int T;
  std::cin >> T;

  std::cin >> R >> N >> M >> K;

  std::cout << "Case #1:" << std::endl;
  for (int r = 0; r < R; ++r) {
    for (int i = 0; i < K; ++i) std::cin >> p[i];
    per = 1 << K;
    generate(N, 0);
  }
}
