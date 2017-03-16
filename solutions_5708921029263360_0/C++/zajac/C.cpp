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

struct triple { 
  int a, b, c; 
  bool operator < (const triple& other) const {
    return a < other.a ||
      (a == other.a && b < other.b) ||
      (a == other.a && b == other.b && c < other.c);
  }
};

/*************************************************************************/

int main() {
  ios_base::sync_with_stdio(0);
  srand(time(0));

  int T;
  cin >> T;
  FOR(cas, 1, T) {
    cout << "Case #" << cas << ": ";
    
    int j, p, s, k;
    cin >> j >> p >> s >> k;
    k = min(k, s);
    
    
    int ans = 0;
    vector<triple> sol;

    const int ITER = 10000;
    
    REP(_, ITER) {
      int left[j + 1][p + 1][s + 1];
      set<triple> possible;
      FOR(a,1,j) FOR(b,1,p) FOR(c,1,s) possible.insert({a,b,c});
      FOR(a,0,j) FOR(b,0,p) FOR(c,0,s) left[a][b][c] = k;
      vector<triple> curSol;
      while(true) {
        int bRes = 1;
        vector<triple> bVec;
        for (const auto& t : possible) {
          int propo = min({ left[0][t.b][t.c], left[t.a][0][t.c], left[t.a][t.b][0] });
          if (propo > bRes) {
            bRes = propo;
            bVec = { t };
          } else if (propo == bRes) {
            bVec.pb(t);
          }
        }
        
        if (bVec.empty()) break;
        auto newElm = bVec[rand() % SIZE(bVec)];
        curSol.pb(newElm);
        possible.erase(newElm);
        left[0][newElm.b][newElm.c]--;
        left[newElm.a][0][newElm.c]--;
        left[newElm.a][newElm.b][0]--;
      }
      if (SIZE(curSol) > ans) {
        ans = SIZE(curSol);
        sol = curSol;
      }
    }
    
    cout << ans << '\n';
    for (const auto& t : sol) {
      cout << t.a << ' ' << t.b << ' ' << t.c << '\n';
    }
    
  }
  

  return 0;
}

/*************************************************************************/
