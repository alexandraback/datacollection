#define DEBUG 1

#if !DEBUG
  #define NDEBUG
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
#define RepI(i,a)  for(typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i;++i)
#define RevI(i,a)  for(typeof((a).rbegin())i=(a).rbegin(),_##i=(a).rend();i!=_##i;++i)
#define All(a)     (a).begin(), (a).end()
#define Sz(a)      int((a).size())
#define Mem(a,b)   memset((a),(b),sizeof(a))
#define Fill(a,b)  fill((a),(a)+sizeof(a)/sizeof((a)[0]),(b))
#define Fill2(a,b) fill(&(a)[0][0],&(a)[0][0]+sizeof(a)/sizeof((a)[0][0]),(b))
#define ToStr(i)   static_cast<ostringstream*>(&(ostringstream()<<(i)))->str()
#define ToInt(s)   ({ int i; istringstream SS(s); if (!(SS >> i)) i = 0; i; })
#define Rng(x,a,b) ({ typeof(x) _X = (x); (_X) >= (a) && (_X) <= (b); })
#define Min(a,b)   ({ typeof(a) _A = (a); typeof(b) _B = (b); _A < _B ? _A : _B; })
#define Max(a,b)   ({ typeof(a) _A = (a); typeof(b) _B = (b); _A > _B ? _A : _B; })
#define Defl(a,b)  ({ typeof(b) _B = (b); a > _B ? a = _B : a; })
#define Infl(a,b)  ({ typeof(b) _B = (b); a < _B ? a = _B : a; })
#define Rd(x...)   ({ RD , x; }) /* Rd(a,b, ...) is equivalent to cin>>a>>b>> ... */
#define Ru(x...)   ({ RU , x; }) /* Only reads whitespace-separated unsigned ints */
#define Pr(x...)   ({ if (DEBUG) { cerr << "Debug["; DB, x, "]\n"; } })
#define Db(x...)   ({ if (DEBUG) { cerr << "Debug["; DB, #x, ":", x, "]\n"; } })
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
  (const T & v) { cerr << " " << v << flush; return *this; } } DB;
struct classcomp { template<class T> bool operator ()
  (const T & a, const T & b) const { return a > b; } };

/* Print range [lo, hi) with iterators. e.g. Dbrng(A, A + N) */
template<class T> void Dbrng(T lo, T hi, string note = "", int w = 0) {
  if (DEBUG) {  
    cerr << "Debug[ ";
    if (!note.empty()) cerr << setw(3) << note << " : ";
    for (; lo != hi; ++lo) cerr << setw(w) << *lo << " ";
    cerr << "]" << endl;
  }
}

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int INF = 0x3F3F3F3F;

/********************************** END OF TEMPLATE *********************************/

int T, K, L, S, w[256];
string keyb, dest, cur;
double tot, avg, maxi;

int instances() {
  int occurrences = 0;
  string::size_type start = 0;
  while ((start = cur.find(dest, start)) != string::npos) {
    ++occurrences;
    start++;
  }
  return occurrences;
}

void go(int n) {
  if (n == S) {
    int cnt = instances();
    Infl(maxi, cnt);
    avg += cnt;
    tot += 1;
    return;
  }
  For(ch,'A','Z') {
    Rep(i,w[ch]) {
      cur += (char)ch;
      go(n + 1);
      cur.erase(cur.size() - 1);
    }
  }
}

int main() {
  Open("B-small-attempt0.in", "");
 Open("", "B-small-attempt0.out");
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    Mem(w, 0);
    cin >> K >> L >> S >> keyb >> dest;
    Rep(i,keyb.size()) w[keyb[i]]++;
    tot = avg = maxi = 0;
    cur = "";
    go(0);
    cout.precision(9);
    cout << "Case #" << tt << ": ";
    cout << fixed << maxi - avg/tot << endl;
  }
  return 0;
}
