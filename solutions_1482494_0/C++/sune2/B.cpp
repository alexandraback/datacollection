#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

int a[1001];
int b[1001];
bool flag[1001];

int main() {
  int T;
  cin >> T;
  REP(t,T) {
    int n;
    cin >> n;
    priority_queue<pii,vector<pii>,greater<pii> > Q;
    vector<pii> v;
    REP(i,n) {
      cin >> a[i] >> b[i];
      Q.push(pii(a[i], i));
      v.push_back(pii(b[i], i));
    }
    sort(ALL(v));
    int now = 0;
    bool dame = 0;
    int ans = 0;
    memset(flag,0,sizeof(flag));
    REP(i,n) {
      while (now < v[i].first) {
        if (Q.size()) {
          pii p = Q.top(); Q.pop();
          if (now < p.first) {
            dame = 1;
            break;
          }
          if (!flag[p.second]) {
            ans++;
            now += 1;
            flag[p.second] = 1;
          }
        } else {
          dame = 1;
          break;
        }
      }
      if (dame) break;
      if (flag[v[i].second]) now++;
      else now += 2;
      ans++;
    }
    printf("Case #%d: ", t+1);
    if (dame) cout << "Too Bad" << endl;
    else cout << ans << endl;
  }
}
