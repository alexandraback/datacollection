#include <algorithm>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
using namespace std;

const int MAXN = 1024;

int memo[MAXN][MAXN];
int A[MAXN], B[MAXN];
int N;

int read_mass() {
  double x; scanf("%lf", &x);
  return static_cast<int>(1e5*x + 1e-9);
}

int g(set<int> S, int lo = 0) {
  int res = 0;

  for (int i = N-1; i >= lo; --i) {
    assert(S.size() > 0);

    auto it = S.lower_bound(A[i]+1);
    if (it == S.end()) it = S.begin();

    res += A[i] > *it;
    S.erase(it);
  }
  return res;
}

int f(int p, int q) {
  if (p > q) return 0;

  int& res = memo[p][q];
  if (res != -1) return res;

  res = 0;
  int i = N-(q-p+1);

  if (A[i] > B[p]) res = max(res, 1 + f(p+1, q));
  if (A[i] < B[q]) res = max(res, f(p, q-1));

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

    memset(memo, -1, sizeof(memo));
    printf("Case #%d: %d %d\n", tc, f(0, N-1), g(set<int>(B, B+N)));
    fflush(stdout);
  }
  return EXIT_SUCCESS;
}
