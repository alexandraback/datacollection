#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
 
// Constants
const int INF = 0X3F3F3F3F;
const double PI = acos(-1.0);//3.1415926535897932384626433832795;
const double EPS = 1e-11;
const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}; //4 direction
//const int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[] = {-1, 0, 1, 1, 1, 0, -1, -1}; //8 direction
//const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1}; //Knight direction
//const int dx[] = {0, 1, 1, 0, -1, -1}, dy[] = {1, 1, 0, -1, -1, 0}; //Hexagonal direction(col x row y)
 
// Definitions
#define PB push_back
#define MP make_pair
#define SZ size()
 
#define FOR(i, s, e) for (int i = (s); i <= (int)(e); ++i)
#define FORD(i, s, e) for (int i = (s);i >= (int)(e); --i)
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define REPD(i, n) for (int i = (n) - 1; i >= 0; --i)
#define FIT(it, x) for (typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define FITD(it, x) for (typeof((x).rbegin()) it = (x).rbegin(); it != (x).rend(); it++)
 
#define LET(a, b) typeof(b) a(b)
#define ALL(x) (x).begin(), (x).end()
#define CLR(x) memset((x), 0, sizeof(x))
#define SET(a, b) memset((a), b, sizeof(a))
#define EXIST(a, b) (find(all(a), b)!=a.end())
#define SORT(x) sort(ALL(x))
#define GSORT(x) sort(ALL(x), greater<typeof((x).begin())>())
#define gsort(a, b) sort(a, b, greater<typeof(*a)>())
#define OUT(x) cerr << #x << ":" << x << '@' << endl
#define PRV(v) REP(vi, v.SZ) cout << v[vi] << ' '; cout << endl
 
// Types
typedef long long LL;
typedef double DB;
typedef stringstream SS;
typedef set<int> SI;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
typedef vector<string> VS;
typedef vector<PII> VPII;
typedef map<string, int> MSI;
typedef map<int, int> MII;
typedef map<LL, int> MLLI;
typedef priority_queue<int> pq;
typedef priority_queue<int, vector<int>, greater<int> > pqg;
 
//Functions
inline int sgn(double x) { return x < -EPS ? -1 : x > EPS ? 1 : 0; }
template<class T> inline T sqr(const T& x) { return x * x; }
template<class T> inline int toint(const T& x){ SS ss; ss << x; int r; ss >> r; return r; }
template<class T> inline int todouble(const T& x){ SS ss; ss << x; double r; ss >> r; return r; }
template<class T> inline string tostr(const T& x) { SS ss; ss << x; return ss.str(); }
inline string tolower(string s){ REP(i, s.SZ) s[i] = tolower(s[i]); return s; }
inline string toupper(string s){ REP(i, s.SZ) s[i] = toupper(s[i]); return s; }
 
template<class T> vector<T> split(string s, char c = ' ') { SS ss(s); vector<T> res; T t; while (ss >> t) { res.PB(t); if(ss.peek() == c) ss.ignore(); } return res; }
template<class T> vector<T> stov(string s) { vector<T> vi; SS ss(s); T v; while (ss >> v) vi.PB(v); return vi; }
template<class T> string vtos(const vector<T>& vi) { SS ss; REP(i, vi.SZ) { if (i > 0) ss << ' '; ss << vi[i]; } return ss.str(); }
 
// Maths
template<class T> inline T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> inline vector<pair<T, int> > factorize(T n) { vector<pair<T, int> > R; for (T i = 2; n > 1; ) { if (n % i == 0) {
int C = 0; while (n % i == 0) C++, n /= i; R.PB(MP(i, C)); } i++; if (i > n / i) i = n; } if (n > 1) R.PB(MP(n, 1)); return R; }
template<class T> inline bool isprime(T n) { if (n < 2) return false; for (T i = 2; i * i <= n; i++) if (n % i == 0) return false; return true; }
template<class T> inline T phi(T n) { vector<pair<T, int> > R = factorize(n); T r = n; REP(i, R.SZ) r = r / R[i].first * (R[i].first - 1); return r; }


int r, c, n;
const int N = 1000000;
int dp[N + 10];

int reversenumber(int n) {
  int s = 0;
  while(n > 0) {
    s = s * 10 + n % 10;
    n /= 10;
  }
  return s;
}

int main() {
  int t, r;
  dp[1] = 1;
  for(int i = 2; i <= N + 1; ++i) {
    dp[i] = dp[i - 1] + 1;
    r = reversenumber(i);
    if (i % 10 && r < i) 
      dp[i] = min(dp[i], dp[r] + 1);
  }
  cin>>t;
  REP(i, t) {
    cin>>n;    
    cout<<"Case #"<<i+1<<": "<<dp[n]<<endl;    
  }    
  return 0;
}