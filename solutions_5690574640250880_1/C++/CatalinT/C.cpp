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
#define EPS             1e-7

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

template<class T, class U>
class MincostMaxflow {
public:
  class edge {
  public:
    int source, destination;
    T capacity, residue;
    U cost;
    edge(int s, int d, T cap, T res, U cost)
    : source(s), destination(d), capacity(cap), residue(res), cost(cost) { }
  };
  
  vector< vector<int> > V;
  vector<edge> E;
  void clear();
  void addArc(int source, int destination, T capacity, U cost);
  pair<T,U> getFlow(int source, int sink);
};

template<class T, class U> void MincostMaxflow<T,U>::clear() { V.clear(); E.clear(); }

template<class T, class U>
void MincostMaxflow<T,U>::addArc(int source, int destination, T capacity, U cost) {
  // cout << "addArc " << source << " " << destination << " " << capacity << " " << cost << endl;
  int e = E.size();
  if (source >= int(V.size())) V.resize(source+1);
  if (destination >= int(V.size())) V.resize(destination+1);
  V[source].push_back( e );
  V[destination].push_back( e+1 );
  E.push_back(edge(source,destination,capacity,capacity,cost));
  E.push_back(edge(destination,source,capacity,0,-cost));
}

template<class T, class U>
pair<T,U> MincostMaxflow<T,U>::getFlow(int source, int sink) {
  if (source >= int(V.size())) V.resize(source+1);
  if (sink >= int(V.size())) V.resize(sink+1);
  
  int N = V.size(), M = E.size();
  T flowSize = 0;
  U flowCost = 0;
  T Tinfinity = 1; while (2*Tinfinity > Tinfinity) Tinfinity *= 2;
  U Uinfinity = 1; while (2*Uinfinity > Uinfinity) Uinfinity *= 2;
  U Uepsilon = 1; for (int i=0; i<30; i++) Uepsilon /= 2;
  vector<T> flow(M,0);
  vector<U> potential(N,0);
  while (1) {
    // use dijkstra to find an augmenting path
    vector<int> from(N,-1);
    vector<U> dist(N,Uinfinity);
    
    priority_queue< pair<U,int>, vector<pair<U,int> >, greater<pair<U,int> > > Q;
    Q.push(make_pair(0,source));
    from[source]=-2;
    dist[source] = 0;
    
    while (!Q.empty()) {
      U howFar = Q.top().first;
      int where = Q.top().second;
      Q.pop();
      if (dist[where] < howFar) continue;
      
      for (int i=0; i<int(V[where].size()); i++) {
        if (E[ V[where][i] ].residue == 0) continue;
        int dest = E[ V[where][i] ].destination;
        U cost = E[ V[where][i] ].cost;
        if (dist[dest] > dist[where] + potential[where] - potential[dest] + cost + Uepsilon) {
          dist[dest] = dist[where] + potential[where] - potential[dest] + cost;
          from[dest] = V[where][i];
          Q.push( make_pair( dist[dest],dest ));
        }
      }
    }
    
    // update vertex potentials
    for (int i=0; i<N; i++) {
      if (dist[i]==Uinfinity) potential[i] = Uinfinity;
      else if (potential[i]<Uinfinity) potential[i] += dist[i];
    }
    
    // if there is no path, we are done
    if (from[sink] == -1) return make_pair(flowSize,flowCost);
    
    // construct an augmenting path
    T canPush = Tinfinity;
    int where = sink;
    
    while (1) {
      if (from[where]==-2) break;
      canPush = min(canPush, E[ from[where] ].residue );
      where = E[ from[where] ].source;
    }
    
    // update along the path
    where = sink;
    while (1) {
      if (from[where]==-2) break;
      E[ from[where] ].residue -= canPush;
      E[ from[where]^1 ].residue += canPush;
      flowCost += canPush * E[ from[where] ].cost;
      where = E[ from[where] ].source;
    }
    flowSize += canPush;
  }
  return make_pair(-1,47);
};

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dir = 8;

int N, M, X, A[5][5], B[5][5], U[5][5];

inline bool inside(int x, int y) {return x>=0 && x<N && y>=0 && y<M;}

bool check() {
  fill (B, 0);
  re (i, N) {
    re (j, M) {
      if (A[i][j]) {
        B[i][j] = 1;
        re (k, dir) {
          int nx = i + dx[k];
          int ny = j + dy[k];
          if (inside(nx, ny))
            B[nx][ny] = 1;
        }
      }
    }
  }
  
  pii zero;
  int nr_zero = 0;
  
  fill(U, 0);
  re (i, N) re (j, M) U[i][j] = 1;
  
  re (i, N) {
    re (j, M) {
      if (!B[i][j]) {
        zero = mp(i, j);
        U[i][j] = 0;
        ++nr_zero;
        re (k, dir) {
          int nx = i + dx[k];
          int ny = j + dy[k];
          if (inside(nx, ny))
            U[nx][ny] = 0;
        }
      }
    }
  }
  
  //debug("nr_zero:", nr_zero, "tot_sum:", accumulate(*U, *U + 25, 0));
  
  if (!nr_zero) {
    return false;
  }
  
  if (accumulate(*U, *U + 25, 0) != X)
    return false;
  
  
  int nr_found = 0;
  queue<pii> q;
  
  for (q.push(zero); !q.empty(); q.pop()) {
    pii el = q.front();
    U[el.fi][el.se] = 1;
    ++nr_found;
    re (k, dir) {
      int nx = el.fi + dx[k];
      int ny = el.se + dy[k];
      if (inside(nx, ny) && B[nx][ny] == 0 && !U[nx][ny]) {
        U[nx][ny] = 1;
        q.push(mp(nx, ny));
      }
    }
  }
  
  //debug("nr_found:", nr_found);
  
  return nr_zero == nr_found;
}

void print_sol(int msk, int x, int y) {
  vs sol(N, string(M, '.'));
  re (i, N) {
    re (j, M) {
      if (checkbit(msk, (i * M + j))) {
        sol[i][j] = '*';
      } else {
        if (i == x && j == y) {
          sol[i][j] = 'c';
        } else {
          sol[i][j] = '.';
        }
      }
    }
  }
  re (i, N) cout << sol[i] << "\n";
}

void solve_small(int test) {
  if (X == N * M - 1) {
    print_sol((1<<(N*M)) - 2, 0, 0);
    return;
  }

  re (msk, (1<<(N*M))) {
    if (bitcount(msk) != X)
      continue;
    
    re (i, N)
      re (j, M)
        A[i][j] = checkbit(msk, (i * M + j));
    
    if (check()) {
      re (i, N) re (j, M) {
        if (!B[i][j]) {
          print_sol(msk, i, j);
          return;
        }
      }
    }
  }
  
  cout << "Impossible\n";
}

char is_possible[52][52][2502];
char prev_down[52][52][2502];
char prev_up[52][52][2502];
short prev_sum[52][52][2502];

inline char frontier_column(char down, char up) {
  return (up + 1 < N) + (down - 1 >= 0);
}

inline char right_frontier(int column, char down, char up) {
  if (column == M - 1) return 0;
  return up - down + 1 + frontier_column(down, up);
}

inline bool inside_segment(char x, char down, char up) {
  return x >= down && x <= up;
}

int rec(char column, char up, int sum) {
  if (sum < 0) return 0;
  
  if (column == -1)
    return sum == 0;
  
  char & pos = is_possible[column][up][sum];
  if (pos != -1) return pos;
  
  pos = 0;
  char down = 0;
  
  char cur_col = frontier_column(down, up) + (up - down + 1);
  char new_down = 0;
  
    for (char new_up = 0; new_up <= up; ++new_up) {
      char over_extend = 0;
      over_extend += right_frontier(0, 0, up) -
                     frontier_column(new_down, new_up) - (new_up - new_down + 1);
      
      if (column == 0) over_extend = 0;
      
      if (rec(column - 1, new_up, sum - cur_col - over_extend)) {
        prev_down[column][up][sum] = new_down;
        prev_up[column][up][sum] = new_up;
        prev_sum[column][up][sum] = sum - cur_col - over_extend;
        return pos = 1;
      }
    }
  
  return pos;
}

void construct_and_print(char column, char down, char up, int sum) {
  vs sol (N, string(M, '*'));
  
  char cur_char = 'a';
  
  while (column >= 0) {
    debug("step by step:", (int)column, (int)down, (int)up, sum);
    
    fo (k, down, up)
      sol[k][column] = '.';
    char new_down = prev_down[column][up][sum];
    char new_up = prev_up[column][up][sum];
    
    //assert(new_down >= 0 && new_up >= 0);
    //assert(new_up >= new_down);
    
    sum = prev_sum[column][up][sum];
    //assert(sum >= 0);
    
    down = new_down;
    up = new_up;
    
    --column;
    ++cur_char;
  }
  
  vs new_sol = sol;
  
  debug("debug special");
  re (i, N) cerr << sol[i] << "\n";
  debug("debug special");
  
  re (i, N) {
    re (j, M) {
      if (sol[i][j] == '*') continue;
      new_sol[i][j] = '.';
      re (k, dir) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (inside(nx, ny))
          new_sol[nx][ny] = '.';
      }
    }
  }
  
  int free = 0;
  re (i, N) free += count(all(new_sol[i]), '.');
  assert(free + X == N * M);
  
  re (i, N) {
    re (j, M) {
      if (new_sol[i][j] == '.') {
        new_sol[i][j] = 'c';
        re (line, N) cout << new_sol[line] << "\n";
        return;
      }
    }
  }
  
}

void solve_large(int test) {
  int sum = N * M - X;
  
  if (sum == 1) {
    vs ret (N, string(M, '*'));
    ret[0][0] = 'c';
    re (i, N) cout << ret[i] << "\n";
    return;
  }
  
  fill (is_possible, -1);
  fill (prev_down, 0);
  fill (prev_up, -1);
  
  re (column, M) {
    re (up, N) {
      char down = 0;
      if (rec(column, up, sum - right_frontier(column, down, up))) {
        debug("found solution:", column, down, up, sum - right_frontier(column, down, up));
        debug("-> ", sum, (int)right_frontier(column, down, up));
        construct_and_print(column, down, up, sum - right_frontier(column, down, up));
        return;
      }
    }
  }
  
  cout << "Impossible\n";
}

int main() {
  int T;
  cin >> T;
  
  fo (test, 1, T) {
    cin >> N >> M >> X;
    printf("Case #%d:\n", test);
    //if (N <= 5 && M <= 5) {
    //  solve_small(test);
    //} else {
    solve_large(test);
    //}
  }
  
  return 0;
}