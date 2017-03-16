#include <algorithm>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
using namespace std;

const int MAXN = 10;

int memo1[1<<MAXN][1<<MAXN];
int memo2[1<<MAXN][1<<MAXN];
int A[MAXN], B[MAXN];
int N;

int read_mass() {
  double x; scanf("%lf", &x);
  return static_cast<int>(1e5*x + 1e-9);
}

int pick(int s, int x) {
  int res = -1;
  for (int i = 0; i < N; ++i) {
    if ((s >> i) & 1) continue;

    if (res == -1) res = i;
    if (B[i] > x) return i;
  }

  return res;
}

int f(int s1 = 0, int s2 = 0) {
  int& res = memo1[s1][s2];
  if (res != -1) return res;

  res = 0;
  for (int i = 0; i < N; ++i) {
    if ((s1 >> i) & 1) continue;

    for (int j = N-1; j >= 0; --j) {
      int k = pick(s2, B[j]);

      bool win1 = A[i] > B[k];
      bool win2 = B[j] > B[k];

      if (win1 == win2) {
        res = max(res, win1 + f(s1 | (1 << i), s2 | (1 << k)));
      }
    }

    int k2 = pick(s2, A[i]);
    res = max(res, (A[i] > B[k2]) + f(s1 | (1 << i), s2 | (1 << k2)));
  }

  return res;
}

int g(int s1 = 0, int s2 = 0) {
  int& res = memo2[s1][s2];
  if (res != -1) return res;

  res = 0;
  for (int i = 0; i < N; ++i) {
    if ((s1 >> i) & 1) continue;

    int k = pick(s2, A[i]);
    res = max(res, (A[i] > B[k]) + g(s1 | (1 << i), s2 | (1 << k)));
  }

  return res;
}

int main() {
  int T; scanf("%d", &T);
  for (int tc = 1; tc <= T; ++tc) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) A[i] = read_mass();
    for (int i = 0; i < N; ++i) B[i] = read_mass();

    sort(A, A+N);
    sort(B, B+N);

    memset(memo1, -1, sizeof(memo1));
    memset(memo2, -1, sizeof(memo2));
    printf("Case #%d: %d %d\n", tc, f(), g());
  }
  return EXIT_SUCCESS;
}
