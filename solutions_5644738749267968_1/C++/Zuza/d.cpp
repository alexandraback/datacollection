#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

int main(void)
{
  int ntc; scanf("%d", &ntc);
  REP(tc, ntc) {
    int ans_a = 0, ans_b = 0;
    int n_one; scanf("%d", &n_one);

    struct W { double w; int idx; };
    static vector<W> all; all.clear();
    static vector<double> A, B; A.clear(); B.clear();

    REP(p, 2) {
      REP(i, n_one) {
        double w; scanf("%lf", &w);
        all.push_back({w, p});
        if (p == 0) A.push_back(w);
        else B.push_back(w);
      }
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(all.begin(), all.end(), [](const W& a, const W& b) {
        return a.w < b.w;
      });
    { int a = 0, b = 0;
      for (int i = all.size() - 1; i >= 0; --i) {
        if (all[i].idx == 0) { // prvi igrac
          if (b > 0) { --b; }
          else ++a;
        } else { // drugi
          ++b;
        }
      }
      ans_b = a;
    }

    { int b_ptr = 0;
      ans_a = 0;
      REP(i, n_one) {
        if (A[i] > B[b_ptr]) {
          ++ans_a;
          ++b_ptr;
        }
      }
    }

    printf("Case #%d: %d %d\n", tc+1, ans_a, ans_b);
    fflush(stdout);
  }
  return 0;
}
