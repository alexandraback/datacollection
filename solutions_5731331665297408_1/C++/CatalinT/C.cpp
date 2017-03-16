/*
 Catalin-Stefan Tiseanu
 Pre-written code is assembled from various sources found online.
 Big thanks to the community for that !
 */
// Pre-written code below

using namespace std;

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#include <unordered_map>
#include <unordered_set>

//START_CLEAN
// always remove

//START:mandatory
#define DEBUG

#ifndef NDEBUG
#   define assert_msg(condition, message) \
do { \
if (! (condition)) { \
std::cerr << "Assertion `" #condition "` failed in " << __FILE__ \
<< " line " << __LINE__ << ": " << message << std::endl; \
std::exit(EXIT_FAILURE); \
} \
} while (false)
#else
#   define ASSERT(condition, message) do { } while (false)
#endif

#ifdef DEBUG
#define debug(args...)            {dbg,args; cerr<<endl;}
#else
#define debug(args...)              // Just strip off all debug tokens
#endif

template<class T> std::ostream&  operator <<(std::ostream& stream, const vector<T> & v) {
  for (auto el : v)
    stream << el << " ";
  return stream;
}

template<class T> std::ostream&  operator <<(std::ostream& stream, const vector<vector<T>> & v) {
  for (auto line : v) {
    for (auto el : line)
      stream << el << " ";
    stream << endl;
  }
  return stream;
}

template<class T, class U> std::ostream&  operator <<(std::ostream& stream, const pair<U, T> & p) {
  stream << "( " << p.first << ", " << p.second << " )";
  return stream;
}

class debugger {
public:
  template<class T> void output (const T& v) {
    cerr << v << " ";
  }
  
  template<class T> debugger& operator , (const T& v) {
    output(v);
    return *this;
  }
} dbg;
//END:mandatory

////////////////
// templates  //
////////////////

// general
//template size
template<typename T> int size(const T& c) { return int(c.size()); }
//template abs
template<typename T> T abs(T x) { return x < 0 ? -x : x; }
//template sqr
template<typename T> T sqr(T x) { return x*x; }
//template remin
template<typename T> bool remin(T& x, T y) { if (x <= y) return false; x = y; return true; }
//template remax
template<typename T> bool remax(T& x, T y) { if (x >= y) return false; x = y; return true; }
//template factorize
template<class T> inline vector<pair<T,int> > factorize(T n) {vector<pair<T,int> > R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));} i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
//template toStr
template<typename T> string toStr(T x) { stringstream ss; ss << x; return ss.str(); }

// other
string maskToStr(long long x, int len) {stringstream ss; for (int i = 0; i < len; ++i) if (x >> i & 1) ss << "1"; else ss << "0"; return ss.str();}

// misc
#define EPS             1e-5

// types
//template int64
typedef long long            int64 ;
//template uint64
typedef unsigned long long   uint64 ;

// shortcuts
#define all(_xx)             _xx.begin(), _xx.end()

#define pb                   push_back
#define vi                   vector<int>
#define vs                   vector<string>
#define vvi                  vector<vector<int>>
#define vd                   vector<double>
#define vpii                 vector<pair<int,int> >
#define vpdd                 vector<pair<double,double> >

#define pii                  pair<int,int>
#define pll                  pair<long long, long long>
#define pdd                  pair<double, double>
#define mp(XX, YY)           make_pair(XX, YY)
#define fi                   first
#define se                   second

#define ll                   long long
#define SS                   stringstream

// for loops
#define re(II, NN)           for (int II(0), _NN(NN); (II) < (NN); ++(II))
#define fod(II, XX, YY)      for (int II(XX), _YY(YY); (II) >= (_YY); --(II))
#define fo(II, XX, YY)       for (int II(XX), _YY(YY); (II) <= (_YY); ++(II))
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

// Useful hardware instructions
#define bitcount             __builtin_popcount
#define gcd                  __gcd

// Useful all around
#define checkbit(n,b)        ( (n >> b) & 1)
#define DREP(a)              sort(a.begin(), a.end());a.erase(unique(a.begin(), a.end()),a.end())
#define INDEX(arr,ind)       (lower_bound(arr.begin(), arr.end(),ind)-arr.begin())
#define PAUSE cerr << "Press any key to continue ..."; char xxxx; scanf("%c", &xxxx);
#define fill(xx,val) memset(xx, val, sizeof(xx))

struct Scanner {
  char* curPos;
  
  const static int BUF_SIZE = (2000000);
  char input[BUF_SIZE];
  
  FILE * fin;
  
  void init(FILE * _fin) {
    fin = _fin;
    fread(input, 1, sizeof(input), fin);
    curPos = input;
  }
  
  Scanner() {;}
  
  inline void ensureCapacity() {
    int size = input + BUF_SIZE - curPos;
    if (size < 100) {
      memcpy(input, curPos, size);
      fread(input + size, 1, BUF_SIZE - size, fin);
      curPos = input;
    }
  }
  
  inline int nextInt() {
    ensureCapacity();
    while (!isdigit(*curPos) && *curPos != '-')
      ++curPos;
    int res = 0;
    int sign = 1;
    
    if (*curPos == '-')
      sign = -1,
      ++curPos;
    
    while (*curPos >= '0' && *curPos <= '9')
      res = res * 10 + (*(curPos++) & 15);
    return sign * res;
  }
} Sc;

// code here

#define MAX_N 55

int N, M;
vvi adj;
vi zip, used, parent;

string make_solution(vi solution)
{
  SS ss;
  re (i, N)
    ss << zip[solution[i]];
  return ss.str();
}

bool can_do(int x)
{
  queue<int> Q;
  vi seen = used;
  
  int y = x;
  while (y != -1) {
    Q.push(y);
    seen[y] = 1;
    y = parent[y];
  }
  
  while(!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    
    //if (seen[cur])
    //  continue;
    
    seen[cur] = 1;
    
    re (i, size(adj[cur]))
      if (!used[adj[cur][i]] && !seen[adj[cur][i]])
      Q.push(adj[cur][i]);
  }
  
  debug("tried:", x, seen);
  
  re (i, N)
    if (!seen[i])
      return false;
  
  return true;
}

vi solve()
{
  vi sol;
  int root = -1;
  int min_zip = (1<<20);
  
  parent.assign(N, -1);
  used.assign(N, 0);
  
  re (i, N)
    if (zip[i] < min_zip)
      min_zip = zip[i],
      root = i;
  
  // grow the tree greedily
  sol.pb(root);
  used[root] = 1;
  
  re (steps, N - 1) {
    vector < pair <int, pii> > candidates;
    
    re (i, size(sol))
      re (j, size(adj[sol[i]]))
        if (!used[adj[sol[i]][j]])
          candidates.pb(mp(zip[adj[sol[i]][j]], mp(adj[sol[i]][j], sol[i])));
  
    sort(all(candidates));
    
    re (i, size(candidates)) {
      //debug("considering:", candidates[i].fi, candidates[i].se);
    
      int cur = candidates[i].se.fi;
      int par = candidates[i].se.se;
      
      // I can only use vertices par to cur for my bf
      
      parent[cur] = par;
      assert(used[par]);
      
      if (can_do(cur)) {
        sol.pb(cur);
        used[cur] = 1;
        
        vi ok (N, 0);
        
        for (int y = cur; y != -1; y = parent[y])
          ok[y] = 1;
        
        re (j, size(sol))
        if (!ok[sol[j]]) {
          adj[sol[j]].clear();
          //debug("clearing:", sol[j]);
        }
        break;
      }
      
      parent[cur] = -1;
    }
  }
  
  debug("sol =", sol);
  
  assert(size(sol) == N);
  
  return sol;
}

int main() {
  int T;
  scanf("%d", &T);
  
  fo (test, 1, T) {
    cin >> N >> M;
    zip.resize(N);
    adj.assign(N, vi());
    
    re (i, N)
      cin >> zip[i];
    re (i, M) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      adj[x].pb(y), adj[y].pb(x);
    }
    printf("Case #%d: %s\n", test,  make_solution(solve()).c_str());
  
    // HACK
    //if (test >= 1) break;
  }
  
  return 0;
}