#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <ctime>

#define FOR(i, m, n) for (int i=m; i<n; i++)
typedef long long ll;

using namespace std;

int N, M, W, H;
ll a[1000]; ll b[1000];
int A[1000]; int B[1000];
int limit[100];
ll ret = 0;

void zkus_limit(int k) {
  if (k==N) {
    //FOR (i, 0, N) printf("l%d ", limit[i]);
    //printf("\n");
    // Kolik dostanu
    ll res = 0;
    int o = 0;
    FOR (i, 0, N) {
      ll beru = 0;
      while (o<limit[i]) {
        if (A[i]==B[o]) {
          beru += b[o];
        }
        o++;
      }
      res += min(beru, a[i]);
    }
    ret = max(ret, res);
    return ;
  }
  else {
    int q = (k>0)?limit[k-1]:0;
    FOR (i, q, M+1) {
      limit[k] = i;
      zkus_limit(k+1);
    }
  }
}

void solve() {
  ret = 0;
  scanf("%d%d", &N, &M);
  FOR (i, 0, N) {
    ll x; int X;
    scanf("%lld%d", &x, &X);
    if (i>0 && X==A[i-1]) {
      a[i-1] += x;
      N--; i--;
    }
    else { a[i] = x; A[i] = X; }
  }
  FOR (i, 0, M) {
    ll x; int X;
    scanf("%lld%d", &x, &X);
    if (i>0 && X==B[i-1]) {
      b[i-1] += x;
      M--; i--;
    }
    else { b[i] = x; B[i] = X; }
  }
  //printf("q%d %d\n", N, M);
  zkus_limit(0);
  if (A[0]==A[2]) {
    ll beru = 0;
    FOR (i, 0, M) {
      if (B[i]==A[0]) beru += b[i];
    }
    ret = max(ret, min(beru, a[0]+a[2]));
  }
  printf("%lld\n", ret);
}

int main()
{
  int t; scanf("%d", &t);
  FOR (i, 0, t) {
    printf("Case #%d: ", i+1);
    solve();
  }
  return 0;
}
