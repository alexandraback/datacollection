#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    long long A;
    int N;
    scanf("%lld%d", &A, &N);
    vector<long long> S(N);
    for (int i = 0; i < N; i++) scanf("%lld", &S[i]);
    sort(S.rbegin(), S.rend());
    while (S.size() && S.back() < A) {
      A += S.back();
      S.pop_back();
    }
    int best = S.size();
    if (A > 1) {
      int ops = 0;
      for (int i = 0; i < 30; i++) {
        ops++;
        A += A-1;
        while (S.size() && S.back() < A) {
          A += S.back();
          S.pop_back();
        }
//        fprintf(stderr, "%lld %d %d\n", A, ops, (int)S.size());
        if (ops + S.size() < best) best = ops + S.size();
//        best = min(best, (int)(ops + S.size()));
      }
    }
    printf("Case #%d: %d\n", tc, best);
  }
}
