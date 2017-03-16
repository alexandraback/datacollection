#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=(b); i <= (e); ++i)
#define FORD(i,b,e) for(int i=(b); i >= (e); --i)
#define REP(i,n) for(int i=0; i < (n); ++i)
#define SIZE(c) (int) (c).size()
#define ALL(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
#define FWD(i,a,b) for (int i=(a); i<(b); ++i)
#define BCK(i,a,b) for (int i=(a); i>(b); --i)
#define PI acos(-1.0)
#define pb push_back
#define mp make_pair
#define st first
#define nd second

using namespace std;

typedef long long int LLI;
typedef pair < int , int > PII;
typedef pair < LLI , LLI > PLL;

typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < PII > VP;
typedef vector < LLI > VL;
typedef vector < PLL > VPL;

typedef vector < VI > VVI;
typedef vector < VL > VVL;
typedef vector < VB > VVB;
typedef vector < VP > VVP;

typedef long double K;

/*************************************************************************/

typedef pair <int, char> party;

int main() {
  ios_base::sync_with_stdio(0);

  int T;
  cin >> T;
  FOR(cas, 1, T) {
    cout << "Case #" << cas << ": ";
    
    int n;
    LLI dest;
    cin >> n >> dest;
    
    if (dest > (1ll << (max(0, n - 2)))) {
      cout << "IMPOSSIBLE\n";
      continue;
    }
    
    cout << "POSSIBLE\n";
    
    vector<string> out(n, string(n, '0'));
    
    REP(i, n - 1) {
      FOR(j, i + 1, n - 2) {
        out[i][j] = '1';
      }
    }
    
    int start = 0;
    while ((1ll << start) <= dest && start < n - 2) start++;
    FORD(i, start, 0) {
      LLI pos = 1ll << (max(0, i - 1));
      if (pos <= dest) {
        dest -= pos;
        out[i][n-1] = '1';
      } 
    }
    
    for (const auto& line : out) cout << line << '\n';
  }
  

  return 0;
}

/*************************************************************************/
