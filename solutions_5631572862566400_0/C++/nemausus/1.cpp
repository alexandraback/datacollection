//author Naresh
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

#define all(a) a.begin(),a.end()
#define rep(i, a, b) for(int i=(a); i<(b); ++i)
#define irep(i, a, b) for(int i=(a); i>=(b); --i)
#define iter(i,v) for(auto &i : (v))

typedef long long ll;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;

typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
typedef pair<string, string> pss;

typedef map<int, int> mii;
typedef map<int, string> mis;
typedef map<string, int> msi;
typedef map<string, string> mss;

// fast input
#define gc getchar_unlocked
template<class T> inline T readnum() { int i=gc(),f=1; for(;i<'0'||i>'9';i=gc()) if(i=='-') { f=-1;i=gc();break; } T ret = 0; for(;i>='0'&&i<='9';i=gc()) { ret = ret*10 + (i-'0'); } return f*ret; }
inline int si() { return readnum<int>(); }
inline ll sll() { return readnum<ll>(); }
inline string ss() { string i=""; int c=gc(); while(c<'a'||c>'z') c=gc(); while(c>='a'&&c<='z') { i+=(char)c; c=gc(); } return i; }

// read and write
inline void svector(vector<int>& v, int n) { v.reserve(n); rep(i,0,n) v.push_back(si()); }
inline void sarray(int* v, int n) { rep(i,0,n) v[i] = si(); }
template<class T> inline void println(T t) { cout << t << endl; }
template<class T> inline void prints(T t, string s = " ") { cout << t << s; }
template<class T> inline void print(T t) { cout << t; }
template<class T> inline void printlist(T l) { iter(i,l) prints(i); cout << endl; }
template<class T> inline void printlist(T *l, int n) { rep(i,0,n) prints(*(l+i)); cout << endl; }
template<class T> inline void printmap(T m) { iter(i,m) { prints(i.first); prints(i.second); } cout << endl; }

// general utils
template<class T> inline void setmax(T &a, T b) { if(b > a) a = b; }
template<class T> inline void setmin(T &a, T b) { if(b < a) a = b; }
template<class T> inline bool isInGrid(T i, T j, T n) { return i>=0 && i<n && j>=0 && j<n; }
template<class T> inline bool isInside(T a, T b, T c) { return a > b && a < c; }
template<class T> inline T reverse(T n) { T r = 0; while (n != 0) { r = r*10; r = r+n%10; n = n/10; } return r; }
template<class T> inline int firstdigit(T n) { int r = 0; while (n != 0) { r = n%10; n = n/10; } return r; }
template<class T> inline int digits(T n) { int r = 0; while (n != 0) { ++r; n /= 10; } return r; }
inline int frequency(string& s, char c) { int r = 0; rep(i,0,s.length()) if (s[i] == c) ++r; return r; }

// math utils
extern int MOD;
ll factorial(int x) { return (x < 2) ? 1 : x*factorial(x-1); }
ll getNcr(int n, int r) { return factorial(n)/(factorial(r) * factorial(n-r)); }
inline ll ipow(ll a, ll b, ll c = MOD) { ll r = 1; while(b) { if(b & 1) r = r*a % MOD; a = a*a % MOD; b >>= 1; } return r; }
inline ll inver(ll a,ll c = MOD) { ll ans = ipow(a,MOD-2); return ans; }
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }
inline bool almost_equal(double x, double y, int ulp) { return std::abs(x-y) < std::numeric_limits<double>::epsilon() * std::abs(x+y) * ulp || std::abs(x-y) < std::numeric_limits<double>::min(); }

class PascalTriagle {
  public:
    PascalTriagle(int N) {
      ncr = new int*[N];
      for (int i = 0; i < N; ++i) {
        ncr[i] = new int[N];
      }
      // maybe need init
      rep(i, 0, N)
        rep(j, 0, i+1) {
          if (j==0 || j==i)
            ncr[i][j] = 1;
          else ncr[i][j] = (ncr[i-1][j-1] + (ll)ncr[i-1][j]) % MOD;
        }
    }

  public:
    int** ncr;
};

class SieveOfEratosthenes {
  public:
    SieveOfEratosthenes(int N) {
      v = new bool[N];
      memset(v, 0, N);
      sp = new int[N];
      // Pierre Dusart showed that if N > 598 then
      int maxPrimes = N/log(N)*(1 + 1.2762/log(N));
      primes = new int[maxPrimes];
      count = 0;
      primes[count++] = 2;
      sp[1] = 1;
      sp[2] = 2;
      for (int i = 4; i < N; i += 2) {
        v[i] = true;
        sp[i] = 2;
      }
      for (int i = 3; i < N; i += 2) {
        if (v[i] == false) { // found new prime
          primes[count++] = i;
          sp[i] = i;
          for (ll j = i; (j*i) < N; j += 2) {
            if (v[j*i] == false) {
              v[j*i] = true;
              sp[j*i] = i;
            }
          }
        }
      }
    }

    vector<pii> factors(int n) {
      vector<pii> v;
      int x = sp[n];
      int count = 1;
      n = n/x;
      while (x > 1) {
        int y = sp[n];
        if (y != x) {
          v.push_back(make_pair(x, count));
          count = 0;
        }
        ++count;
        x = y;
        n = n/x;
      }
      return v;
    }

  public:
    bool* v; // is composite
    int* sp; // smallest prime
    int* primes;
    int count; // number of primes
};

// constants
const double PI = 3.14159265358979323846;
const int MAX_INF = (1LL << 31) - 1;
const int MIN_INF = (1LL << 31);
int MOD = 1E+7 + 7;

#define N 10

int graph[N+1][N+1];       /* Assumed to be populated earlier.  -1 means "no edge". */
int visited[N+1];   /* DP matrix.  -2 means "unknown". */

int start  = -1;
int visited_sol[N+1];
int gans = 0;
int solve(int i, int n, int d) {
		if (d > gans) {
    	gans = d;
			memcpy(visited_sol, visited, 4*11);
    }
		int best = 0;
		bool hasAny = false;
		rep(x, 0, n) {
			if (graph[i][x] == 1 && visited[x] == 0) {
				hasAny = true;
				visited[x] = 1;
				//cout << "check " << i << " " << x << endl;
				int curr = solve(x, n, d+1);
				best = curr > best ? curr : best;
				visited[x] = 0;
			}
    }
		return best + 1;
}

int main() {
  int tests = si();
  int c = 1;
  while(tests--) {
    int n;
    cin >> n;
    auto bff = new int[n+1];
    memset(bff, 0, 4*(n+1));
		rep(x, 0, N) rep(y,0,N) graph[x][y] = 0;
    rep(i, 0, n) {
      int next;
      cin >> next;
      bff[i+1] = next;
			graph[next][i+1] = 1;
    }

    int ans = 0;
	  rep(i, 0, n+1) {
			for (int b = 0; b < N+1; ++b) {
				visited[b] = 0;
			}
		  visited[i] = 1;
			start = i;
			//cout << "###########################" << endl;
      gans = 0;
			int curr = solve(i, n, 1);
      memcpy(visited, visited_sol, 11*4);
      gans = 0;
      curr += solve(i, n, 1) - 1;
			ans = curr > ans ? curr : ans;
			//cout << i << " ans " << gans << endl;
		}
    cout << "Case #" << c++ << ": " << ans << endl;
  }
  return 0;
}

