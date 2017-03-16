#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <numeric>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <cassert>
using namespace std;

typedef long long ll;
static const double EPS = 1e-6;
static const double PI = 4.0 * atan(1.0);
bool ISINT(double x){return fabs(x-(int)round(x))<EPS;}
bool ISEQ(double x,double y){return fabs(x-y)<EPS;}
string itos(ll x){stringstream ss;ss<<x;return ss.str();}
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define EREP(i,a,b) for(int i=a;i<=b;i++)
#define erep(i,n) EREP(i,0,n)
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin();itr!=c.end();itr++)


int main(void){
  const double PI = acos(-1);

  int T;
  cin >> T;

  for(int CASE = 1; CASE <= T; CASE++){
    cout << "Case #" << CASE << ": ";

    int ans = 0;
    bool flg = true;
    ll r, t;
    cin >> r >> t;

    while(t > EPS){
      if(!flg){
        flg = !flg;
        r += 1;
        continue;
      }

      ll need = (r + 1) * (r + 1) - r * r;
      if(need <= t){
        t -= need;
        ans++;
      }
      else{
        break;
      }

      r += 1;
      flg = !flg;
    }

    cout << ans << endl;
  }
}
