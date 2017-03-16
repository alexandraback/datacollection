#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; cas++) {
    int N;
    vector<int> s;
    cin >> N;
    int sum = 0;
    for (int i = 0; i < N; i++) {
      int si;
      cin >> si;
      s.push_back(si);
      sum += si;
    }
    printf("Case #%d:", cas);

    for (int i = 0; i < N; i++) {
      double l = 0.0, h = 1.0;
      while (h - l > 0.000000001) {
        double m = (l + h) / 2;
        double si = s[i] + sum * m;
        double rest = sum * (1 - m);
        for (int j = 0; j < N; j++) {
          if (i == j) continue;
          if (s[j] < si) {
            if (si - s[j] > rest) {
              h = m;
              goto next;
            }
            rest -= si - s[j];
          }
        }
        l = m;
      next:;
      }
      printf(" %.6f", l * 100);
    }
    printf("\n");
  }

  return 0;
}
