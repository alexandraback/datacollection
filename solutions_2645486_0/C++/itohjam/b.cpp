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
static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
bool ISINT(double x){return fabs(x-(int)round(x))<EPS;}
bool ISEQ(double x,double y){return fabs(x-y)<EPS;}
string itos(ll x){stringstream ss;ss<<x;return ss.str();}
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define EREP(i,a,b) for(int i=a;i<=b;i++)
#define erep(i,n) EREP(i,0,n)
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin();itr!=c.end();itr++)

int e, r, n;
int t[12];
int dp[12][12];

int main(void){
  int T;
  cin >> T;

  for(int CASE = 1; CASE <= T; CASE++){
    cin >> e >> r >> n;

    for(int i = 0; i < n; i++){
      cin >> t[i];
    }

    memset(dp, -1, sizeof(dp));
    dp[0][e] = 0;

    for(int i = 0; i < n; i++){
      for(int j = 0; j <= e; j++){
        if(dp[i][j] == -1) continue;

        for(int k = 0; k <= j; k++){
          int ni = i + 1;
          int nj = min(e, j - k + r);

          dp[ni][nj] = max(dp[ni][nj], dp[i][j] + k * t[i]);
        }
      }
    }

    int ans = 0;

    for(int i = 0; i <= e; i++){
      ans = max(ans, dp[n][i]);
    }

    cout << "Case #" << CASE << ": " << ans << endl;
  }
}
