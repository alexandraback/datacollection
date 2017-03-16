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

typedef pair<int, pii> piii;
struct P {
  int a, id, b;
  P() {}
  P(int a,int id,int b):a(a),id(id),b(b) {}
};
bool operator<(const P &a, const P&b) {
  return a.a!=b.a ? a.a > b.a : a.b != b.b ? a.b < b.b : a.id < b.id;
}
int main() {
  int T;
  cin >> T;
  REP(t,T) {
    int n;
    cin >> n;
    priority_queue<P> Q;
    vector<pii> v;
    REP(i,n) {
      cin >> a[i] >> b[i];
      Q.push(P(a[i], i, b[i]));
      v.push_back(pii(b[i], i));
    }
    sort(ALL(v));
    int now = 0;
    bool dame = 0;
    int ans = 0;
    memset(flag,0,sizeof(flag));
    REP(i,n) {
      //cout << now << " " << v[i].first << " " << v[i].second << " ;" << ans << endl;
      while (now < v[i].first) {
        if (Q.size()) {
          P p = Q.top(); Q.pop();
          if (now < p.a) {
            dame = 1;
            break;
          }
          if (!flag[p.id]) {
            ans++;
            now += 1;
            flag[p.id] = 1;
            //cout << " " << p.first << " "<< ans << endl;
          }
        } else {
          dame = 1;
          break;
        }
      }
      if (dame) break;
      if (flag[v[i].second]) now++;
      else now += 2;
      flag[v[i].second] = 1;
      ans++;
    }
    printf("Case #%d: ", t+1);
    if (dame) cout << "Too Bad" << endl;
    else cout << ans << endl;
  }
}
