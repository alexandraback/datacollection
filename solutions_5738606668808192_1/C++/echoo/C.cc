#include <cstdio>
#include <cstring>
#include <vector>

// bool not_prime[20000000];
// int factor[20000000];

int main() {
  int base[] = {10011111, 10110111, 10111101, 11001111,
                11011011, 11100111, 11101101, 11110011};
  int divisor[] = {3, 2, 3, 2, 7, 2, 3, 2, 3};

  int T = 0;
  scanf("%d", &T);
  int N, J;
  scanf("%d %d", &N, &J);

  printf("Case #1:\n");
  if (N == 16) {
    int cnt = 0;
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        ++cnt;
        if (cnt <= J) {
          printf("%d%d", base[i], base[j]);
          for (int k = 0; k < 9; ++k) {
            printf(" %d", divisor[k]);
          }
          printf("\n");
        }
      }
    }
  } else {
    int cnt = 0;
    for (int i1 = 0; i1 < 8; ++i1) {
      for (int i2 = 0; i2 < 8; ++i2) {
        for (int i3 = 0; i3 < 8; ++i3) {
          for (int i4 = 0; i4 < 8; ++i4) {
            ++cnt;
            if (cnt <= J) {
              printf("%d%d%d%d", base[i1], base[i2], base[i3], base[i4]);
              for (int k = 0; k < 9; ++k) {
                printf(" %d", divisor[k]);
              }
              printf("\n");
            }
          }
        }
      }
    }
  }
  /*
  printf("prime\n");
  memset(not_prime, 0, sizeof(not_prime));
  not_prime[0] = not_prime[1] = true;
  for (int i = 2; i < 20000000; ++i) {
    if (not_prime[i] == false) {
      for (int j = i + i; j < 20000000; j += i) {
        if (not_prime[j] == false) {
          factor[j] = i;
        }
        not_prime[j] = true;
      }
    }
  }
  printf("done\n");
  const int N = 8;
  int C = 0;
  for (int i = (1 << (N - 1)); i < (1 << N); i += 2) {
    std::vector<int> v;
    for (int b = 2; b <= 10; ++b) {
      int n = i + 1;
      int bb = 1;
      int m = 0;
      while (n != 0) {
        m += n % 2 * bb;
        bb *= b;
        n /= 2;
      }
      v.push_back(m);
    }
    bool sat = true;
    for (int i = 0; i < v.size(); ++i) {
      if (not_prime[v[i]] == false) {
        sat = false;
        break;
      }
    }
    if (sat) {
      printf("%d: ", ++C);
      int m = (1 << (N - 1));
      int n = i + 1;
      while (n != 0) {
        if (n >= m) {
          printf("1");
          n -= m;
        } else {
          printf("0");
        }
        m /= 2;
      }
      for (int i = 0; i < v.size(); ++i) {
        printf(" %d", factor[v[i]]);
      }
      printf("\n");
    }
  }
  */
}
