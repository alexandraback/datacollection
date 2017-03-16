#ifdef ONLINE_JUDGE
  #define DEBUG 0
  #define NDEBUG
#else
  #define DEBUG 1
#endif

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

#define Rep(i,N)   for(int i= 0 , _##i=(N); i< _##i; ++i)  /*  0  ==> N-1 */
#define For(i,L,H) for(int i=(L), _##i=(H); i<=_##i; ++i)  /*  L  ==>  H  */
#define Rev(i,N)   for(int i=(N); --i>= 0; )               /* N-1 ==>  0  */
#define Dwn(i,H,L) for(int i=(H), _##i=(L); i>=_##i; --i)  /*  H  ==>  L  */
#define All(a)     (a).begin(), (a).end()
#define Sz(a)      int((a).size())
#define Mem(a,b)   memset((a),(b),sizeof(a))
#define Fill(a,b)  fill((a),(a)+sizeof(a)/sizeof((a)[0]),(b))
#define Fill2(a,b) fill(&(a)[0][0],&(a)[0][0]+sizeof(a)/sizeof((a)[0][0]),(b))
#define ToStr(i)   static_cast<ostringstream*>(&(ostringstream()<<(i)))->str()
#define ToInt(s)   ({ int i; istringstream SS(s); if (!(SS >> i)) i = 0; i; })
#define Rng(x,a,b) ({ (x) >= (a) && (x) <= (b); })
#define Min(a,b)   ({ (a) < (b) ? (a) : (b); })
#define Max(a,b)   ({ (a) > (b) ? (a) : (b); })
#define Defl(a,b)  ({ (a) > (b) ? (a) = (b) : a; })
#define Infl(a,b)  ({ (a) < (b) ? (a) = (b) : a; })
#define Rd(x...)   ({ RD , x; }) /* Rd(a,b, ...) is equivalent to cin>>a>>b>> ... */
#define Ru(x...)   ({ RU , x; }) /* Only reads whitespace-separated unsigned ints */
#define Pr(x...)   ({ if (DEBUG) { cout << "Debug["; DB, x, "]\n"; } })
#define Db(x...)   ({ if (DEBUG) { cout << "Debug["; DB, #x, ":", x, "]\n"; } })
#define Open(I,O)  ({ if (*I) freopen(I,"r",stdin); if (*O) freopen(O,"w",stdout); })
#define Unsync()   ({ ios_base::sync_with_stdio(false); cin.tie(0); })
#define pb         push_back
#define mp         make_pair
#define x          first
#define y          second

#ifndef _WIN32
  #define getchar  getchar_unlocked
  #define fgetc    fgetc_unlocked
  #define fgets    fgets_unlocked
#endif

template<class T> inline void ruint(T & a) {
  while ((a = getchar() - '0') < 0);
  for (register char c; (c = getchar() - '0') >= 0; )
    a = (a << 3) + (a << 1) + c;
}

struct Reader { template<class T> Reader& operator ,
  (T & v) { cin >> v; return *this; } } RD;
struct ReaderU { template<class T> ReaderU& operator ,
  (T & v) { ruint(v); return *this; } } RU;
struct Debugger { template<class T> Debugger& operator ,
  (const T & v) { cout << " " << v << flush; return *this; } } DB;
struct classcomp { template<class T> bool operator ()
  (const T & a, const T & b) const { return a > b; } };

/* Print range [lo, hi) with iterators. e.g. Dbrng(A, A + N) */
template<class T> void Dbrng(T lo, T hi, string note = "", int w = 0) {
  if (DEBUG) {
    cout << "Debug[ ";
    if (!note.empty()) cout << setw(3) << note << " : ";
    for (; lo != hi; ++lo) cout << setw(w) << *lo << " ";
    cout << "]" << endl;
  }
}

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int INF = 0x3F3F3F3F;

/********************************** END OF TEMPLATE *********************************/

int T, x, r, c;

int fit() {
  if (x == 1) return 1;
  if (r == 1) return (x == 2) && (c == 2 || c == 4);
  if (r == 2) return (x == 2) || (x == 3 && c == 3);
  if (r == 3) return (c == 4) || (x == 3 && c == 3);
  return x == 2 || x == 4;
}

int main() {
  if (DEBUG) Open("D-small-attempt3.in", "D-small-attempt3.out");
  Unsync();
  cin >> T;
  for (int test = 1; test <= T; test++) {
    cin >> x >> r >> c;
    if (r > c) swap(r, c);
    cout << "Case #" << test << ": ";
    cout << (fit() ? "GABRIEL" : "RICHARD") << endl;
  }
  return 0;
}
