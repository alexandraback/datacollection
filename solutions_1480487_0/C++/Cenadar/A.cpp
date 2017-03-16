#pragma comment (linker, "/STACK:16777216")
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define rep(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define repd(i,n) for (int (i) = n; (i)--; )
#define fe(i,a) for (int (i) = 0; (i) < int((a).size()); ++(i))
#define mem(a, val) memset((a),val,sizeof(a))
#define inf 1000000000
#define pb push_back
#define ppb pop_back
#define all(c) (c).begin(), (c).end()
#define pi acos(-1.0)
#define sqr(a) ((a)*(a))
#define mp(a,b) make_pair((a), (b))
#define xx first
#define yy second
#define MOD 1000000007LL

typedef vector<int> vint;
typedef vector< pair<int, int> > vpii;
typedef long long LL;
typedef pair<int, int> pii;

vpii a;
int sum, n;
double res;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

  int T, cur;
  scanf("%d", &T);
  rep(test, T) {
    sum = 0;
    res = 0;
    a.clear();
    scanf("%d", &n);
    rep(i, n) {
      scanf("%d", &cur);
      sum += cur;
      a.pb(mp(cur, i));
    }
    sort(a.begin(), a.end());
    double left = sum;
    int supp = 0;
    res = a[0].xx;
    FOR(i, 0, n-1) {
      supp = i + 1;
      if (supp == a.size()) {
        res += left / supp;
      } else {
        double delta = min(left / supp, double(a[i + 1].xx) - res);
        res += delta;
        left -= delta * supp;
      }
//      printf("%lf\n", res);
    }
//      printf("\n", res);

    rep(i, n)
      swap(a[i].xx, a[i].yy);
    sort(a.begin(), a.end());

    printf("Case #%d:", test + 1);
    rep(i, n) {
      if (res >= a[i].yy)
        printf(" %.10lf", (res - a[i].yy) * 100.0 / sum);
      else
        printf(" 0.0");
    }
    printf("\n");
  }

  return 0;
}
