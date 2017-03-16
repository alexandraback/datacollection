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


int C, D, V, coins[200];



#define FILEIO 
#define FILENAME "C-small-attempt0"

int main() {
#ifdef FILEIO
  freopen( FILENAME ".in", "r", stdin);
  freopen( FILENAME ".out", "w", stdout);
#endif
  
  int T;
  scanf("%d", &T);
  FOR(t, 0, T) {
    scanf("%d%d%d", &C, &D, &V);
    FOR(i, 0, D) scanf("%d", coins + i);
    sort(coins, coins + D);
    int i = 0, ans = 0, max = 0;
    while(i < D) {
      //println("i", i, max, coins[i]);
      if(max >= V) break;
      if(max < coins[i] - 1) {
        ++ans;
        //println("new", max + 1);
        max = (max + 1) * C + max;
      } else {
        max = coins[i] * C + max;
        ++i;
      }
    }
    while(max < V) {
      ++ans;
      //println("new", max + 1);
      max = (max + 1) * C + max;
    }
    printf("Case #%d: %d\n", t + 1, ans);
  }
  


}
