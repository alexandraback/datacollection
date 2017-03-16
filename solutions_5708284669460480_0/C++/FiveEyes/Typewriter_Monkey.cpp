#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iterator>
#define FOR(i,a,n) for(int i = (a); i < (int)(n); ++i)
#define foreach(itr,c) for(decltype((c).begin()) itr=(c).begin(); itr != (c).end(); itr++)
#define mp(a,b) make_pair(a,b)

using namespace std;

//typedef __int64 ll;
//typedef unsigned __int64 ull;
typedef long long ll;
typedef unsigned long long ull;


template<typename T>
inline T ABS(T a) { return a > 0 ? a : -a; }
template<typename T>
inline T MIN(T a, T b) { return a < b ? a : b; }
template<typename T>
inline T MAX(T a, T b) { return a > b ? a : b; }
template<typename T>
inline T CHKMIN(T &a, T b) { if(a > b) a = b; return a; }
template<typename T>
inline T CHKMAX(T &a, T b) { if(a < b) a = b; return a; }
template<typename T>
inline void SWAP(T &a, T &b) { static T c; c = a; a = b; b = c; }

template<typename T, typename... T0>
T MAX(T a, T b, T0... c) { return a > b ? MAX(a, c...) : MAX(b, c...); }
template<typename T, typename... T0>
T MIN(T a, T b, T0... c) { return a < b ? MIN(a, c...) : MIN(b, c...); }

template<typename T>
void print(T a) { cout << a << ' '; }
template<typename T, typename... T0>
void print(T a, T0... b) { print(a); print(b...); }
template<typename T>
void println(T a) {cout << a << endl;}
template<typename T, typename... T0>
void println(T a, T0... b) { print(a); println(b...); }



int ac[110][26];

void init_AC(char *p) {
  int pi[110], k = -1, len = strlen(p);
  pi[0] = -1;
  memset(ac, 0, sizeof(ac));
  ac[0][*p - 'A'] = 1;
  for(int i = 1; i < len + 1; ++i) {
    while(k >= 0 && p[k + 1] != p[i]) k = pi[k];
    if(p[k + 1] == p[i]) ++k;
    pi[i] = k;
    memcpy(ac[i], ac[pi[i - 1] + 1], sizeof(ac[0]));
    if(i < len) ac[i][p[i] - 'A'] = i + 1;
  }
}

void print_AC(int len) {
  puts("---AC---");
  FOR(i, 0, len+1) {
    FOR(j, 0, 26) print(ac[i][j]);
    puts("");
  }
  puts("---AC END---");

}

int K, L, S;
char keys[200], target[200];
double prb[26], ex[110];
int dp[110][110], mk[110][110];
double ans;

double solve() {
  double ans = 0.0, tmp[110];
  
  memset(ex, 0, sizeof(ex));
  ex[0] = 1;
  
  memset(dp, 0, sizeof(dp));
  
  //FOR(l, 0, L + 1) print(ex[l]); puts("");

  FOR(i, 0, S) {
    memset(tmp, 0, sizeof(tmp));
    FOR(j, 0, L + 1) {
      if(ex[j] == 0) continue;
      if(j == L) dp[i][j]++;
      FOR(k, 0, 26) {
        if(prb[k] == 0) continue;
        tmp[ac[j][k]] += ex[j] * prb[k];
        
        CHKMAX(dp[i+1][ac[j][k]], dp[i][j]);
      }
    }
    memcpy(ex, tmp, sizeof(tmp));
    //FOR(l, 0, L + 1) print(ex[l]); puts("");
    ans += ex[L];
  }
  int max = ex[L] == 0.0 ? 0 : dp[S][L] + 1;
  FOR(i, 0, L) {
    CHKMAX(max, dp[S][i]);
  }
  //println("max", max);
  return max - ans;
}


#define FILEIO 
#define FILENAME "B-small-attempt0"

int main() {
#ifdef FILEIO
  freopen( FILENAME ".in", "r", stdin);
  freopen( FILENAME ".out", "w", stdout);
#endif

  int T;
  scanf("%d", &T);
  FOR(t, 0, T) {
    
    scanf("%d%d%d", &K, &L, &S);
    scanf("%s%s", keys, target);
    
    memset(prb, 0, sizeof(prb));
    FOR(i, 0, K) prb[keys[i] - 'A'] += 1.0 / K;
    //FOR(i, 0, 26) print(prb[i]); puts("");
    init_AC(target);
    //print_AC(L);
    ans = solve();
    printf("Case #%d: %lf\n", t + 1, ans);
  }
}
