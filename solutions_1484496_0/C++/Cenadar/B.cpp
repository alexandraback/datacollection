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

int sum;
int prev[4000100];
bool used[4000100];
const int add = 2000001;
int a[510];

int main() {
/*  freopen("C-small-attempt0.in", "r", stdin);
  freopen("output.txt", "w", stdout);*/

  int T, cur;
  scanf("%d", &T);
  rep(test, T) {
    sum = 0;
    int n;
    scanf("%d", &n);
    rep(i, n) {
      scanf("%d", &a[i + 1]);
    }

    mem(used, 0);
    FOR(i, 1, n) {
      FOR(j, 0, 4000100) {
        if ((used[j] && abs(prev[j]) != i) || j == add) {
          if (!used[j + a[i]]) {
            used[j + a[i]] = true;
            prev[j + a[i]] = +i;
          }
          if (!used[j - a[i]]) {
            used[j - a[i]] = true;
            prev[j - a[i]] = -i;
          }
        }
      }
    }

    printf("Case #%d:\n", test + 1);
    if (!used[add]) {
      printf("Impossible\n");
    } else {
      vint aa, bb;
      int cur = add;
      int delta;
      do {
        delta = prev[cur];
        if (delta > 0) {
          aa.pb(a[delta]);
          cur -= a[delta];
        } else {
          bb.pb(a[-delta]);
          cur += a[-delta];
        }
      } while (cur != add);
      fe(i, aa) printf("%d%c", aa[i], i + 1 != aa.size() ? ' ' : '\n');
      fe(i, bb) printf("%d%c", bb[i], i + 1 != bb.size() ? ' ' : '\n');
    }
  }

  return 0;
}
