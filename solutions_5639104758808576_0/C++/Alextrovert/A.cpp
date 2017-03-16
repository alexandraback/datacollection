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

int T, N, cnt[1005];
string smax;

int main() {
  if (DEBUG) Open("A-small-attempt0.in", "A-small-attempt0.out");
  cin >> T;
  for (int test = 1; test <= T; test++) {
    int clapped = 0, ans = 0;
    cin >> N >> smax;
    for (int i = 0; i <= N; i++) {
      cnt[i] = (int)(smax[i] - '0');
      if (i <= clapped) {
        clapped += cnt[i];
      } else {
        int friends = i - clapped;
        ans += friends;
        clapped += friends + cnt[i];
      }
    }
    cout << "Case #" << test << ": " << ans << endl;
  }
  return 0;
}
