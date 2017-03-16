#include <algorithm>
#include <cassert>
#include <cstdio>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define ASSERT_ for (;;) {}
#define PII pair<long long, long long>

using namespace std;

long long ile(vector<PII> &v, int typ, int begin, int end) {
  long long res = 0;
  for (long long i = begin; i < end; i++) {
    if (v[i].second == typ)
      res += v[i].first;
  }
  return res;
}

int main() {
  long long ntestcase;
  scanf("%lld\n", &ntestcase);
  for (long long test_id = 1; test_id <= ntestcase; test_id++) {
    long long res;
    long long n, m;
    scanf("%lld", &n);
    scanf("%lld", &m);
    vector<PII> A;
    vector<PII> B;
    long long x, y;
    for (int i = 0; i < n; i++) {
      scanf("%lld %lld", &x, &y);
      if (i > 0 && A[i-1].second == y) {
        A[i-1].first += x;
     //   prlong longf("%d %d\n", A[i-1].first, A[i-1].second);
      }
      else {
        A.push_back(PII(x, y));
    //    prlong longf("%d %d\n", A[i].first, A[i].second);
      }
    }
    for (int i = 0; i < m; i++) {
      scanf("%lld %lld", &x, &y);
      B.push_back(PII(x, y));
      //prlong longf("%d %d\n", B[i].first, B[i].second);
    }
    n = A.size();
    res = 0;
    if (n >= 1) {
      res = max(res, (long long)min(ile(B, A[0].second, 0, B.size()), A[0].first));
    }
    if (n >= 2) {
      for (int i = 0; i < B.size(); i++) {
        res = max(res,
            (long long)min(ile(B, A[0].second, 0, i), A[0].first) + min(ile(B, A[1].second, i, B.size()), A[1].first)
            );
      }
    }
    if (n >= 3) {
      for (int i = 0; i < B.size(); i++) {
        for (int j = i; j < B.size(); j++) {
          res = max(res,
            (long long)min(ile(B, A[0].second, 0, i), A[0].first) + 
            (long long)min(ile(B, A[1].second, i, j), A[1].first) + 
            (long long)min(ile(B, A[2].second, j, B.size()), A[2].first)
            );
        }
      }
      if (A[0].second == A[2].second) {
        res = max(res, (long long)min(A[0].first + A[2].first, ile(B, A[0].second, 0, B.size())));
      }
    }

    printf("Case #%lld: %lld\n", test_id, res);
  }

  return 0;
}
