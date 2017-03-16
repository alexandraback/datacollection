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

int digit(int x) {
  int res = 0;
  while(x) x/=10,res++;
  return res;
}
pair<int, bool> cshift(int x, int d) {
  return make_pair(x/10 + (x%10) * pow(10,d-1), x%10!=0);
}

int main() {
  int T;
  cin >> T;
  REP(t,T) {
    int a,b;
    cin >> a >> b;
    int ans = 0;
    set<pii> se;
    for (int i=a; i<b; ++i) {
      int d = digit(i);
      int x = i;
      REP(j, d-1) {
        pair<int,bool> p = cshift(x, d);
        x = p.first;
        if (p.second) {
          if (x>i && x>=a && x<=b) {
            ans++;
            //if (se.count(pii(i,x))) cout << i << " " << x << endl;
            se.insert(pii(i,x));
            //printf("%d -> %d\n", i,x);
          }
        }
      }
    }
    printf("Case #%d: %d\n", t+1, (int)se.size());
  }
}
