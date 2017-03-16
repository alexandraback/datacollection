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
#include <cassert>
#include <queue>
#include <cstring>
#include <limits>
using namespace std;

#define Loop(i,n) for (int i = 0; i < (int)(n); ++i)
#define Loopa(i,a,b) for (int i = (a); i <= (b); ++i)
#define Loopd(i,a,b) for (int i = (a); i >= (b); --i)
template <typename T, typename Q, typename S>
bool Bounded(const T& x, const Q& a, const S& b) { return a <= x && x <= b; }
#define db(x) #x << " = " << x
#define pdb(x) printf("#x = %d\n",x);
#define All(x) x.begin(),x.end()
template <typename T> int sz(const T& x) { return x.size(); }
template <typename T, typename Q>
bool mem(const T& s, const Q& x) { return s.find(x) != s.end(); }
typedef long double ld;
typedef long long int ll;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef pair<int,int> Pii;
typedef vector<Vi> Adj;
typedef vector<bool> Vb;
#define CI(x) x::const_iterator
#define II(x) x::iterator
#define Car(x) (x).first
#define Cdr(x) (x).second
#define Caar(x) (x).first.first
#define Cdar(x) (x).first.second
#define Cadr(x) (x).second.first
#define Cddr(x) (x).second.second
template <typename T>
struct leq_by {
  const vector<T>* v;
  leq_by(const vector<T>& v) : v(&v) { }
  bool operator()(int i, int j) { return v->at(i) < v->at(j); }
};
template <typename T> void read(vector<T>& x) { Loop(i,sz(x)) cin >> x[i]; }
template <typename T> vector<T> readn(int n) { vector<T> x(n); Loop(i,n) cin >> x[i]; return x; }
template <typename T> void umin(T& x, const T& y) { x = min(x, y); }
template <typename T> void umax(T& x, const T& y) { x = max(x, y); }

bool debug = true;
#define dprintf debug && printf
void show(string s, Vi x) {
  if (!debug) return; cout << s << ": "; Loop(i,sz(x)) cout << " " << x[i]; cout << endl;
}

void solve_correct(int casenum) {
  dprintf("==================================================% 3d\n", casenum);



  printf("Case #%d: \n", casenum);
  fflush(NULL);
}

bool ismine(vector<string> A, int i, int j) {
  return A[i][j] == '*';
}

int ismineBounded(vector<string> A, int i, int j) {
  return Bounded(i, 0, A.size()-1) && Bounded(j, 0, A[0].size()-1) && ismine(A,i,j);
}

int countMines(vector<string> A, int i, int j) {
  int dI[8] = {0, -1, -1, -1, 0, 1, 1, 1};
  int dJ[8] = {1, 1, 0, -1, -1, -1, 0, 1};
  int cnt = 0;
  for (int z = 0; z < 8; ++z) cnt += ismineBounded(A, i+dI[z], j+dJ[z]);
  return cnt;
}

// {{{ Greedy
void solve(int casenum) {
  dprintf("==================================================% 3d\n", casenum);

  int rows, cols, mines;
  cin >> rows >> cols >> mines;
  int mineCount = mines;

  vector<string> A(rows, string(cols, '.'));
  A[0][0] = 'c';

  int subrows = rows, subcols = cols;

  while (mines >= subrows || mines >= subcols) {
    if (mines >= subrows) {
      Loop(i, subrows) A[i][subcols-1] = '*', --mines;
      subcols--;
    }
    if (mines >= subcols) {
      Loop(i, subcols) A[subrows-1][i] = '*', --mines;
      subrows--;
    }
  }

  for (int d = subrows + subcols - 2; d >= 1 && mines > 0; --d) {
    int k, j, dir;
    if (subcols > subrows) {
      k = subrows - 1;
      j = d - k;
      dir = -1;
    } else {
      j = subcols - 1;
      k = d - j;
      dir = +1;
    }
    for (;
         0 <= k && k <= subrows - 1 && 0 <= j && j <= subcols-1 && mines > 0;
         k += dir, j -= dir) {
      assert(A[k][j] == '.');
      A[k][j] = '*', --mines;
    }
  }

  queue<Pii> bfs; bfs.push(Pii(0,0));
  vector<Vb> revealed(rows, Vb(cols, false));
  revealed[0][0] = true;
  vector<Vb> visited(rows, Vb(cols, false));

  while (!bfs.empty()) {
    Pii p = bfs.front();
    bfs.pop();
    assert(revealed[p.first][p.second]);
    if (visited[p.first][p.second]) continue;
    visited[p.first][p.second] = true;
    int dR[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dC[8] = {1, 1, 0, -1, -1, -1, 0, 1};

    assert(!ismine(A,p.first,p.second));
    if (countMines(A, p.first, p.second) > 0) continue;

    for (int i = 0; i < 8; ++i) {
      int j = p.first + dR[i], k = p.second + dC[i];
      if (!Bounded(j, 0, rows-1) || !Bounded(k, 0, cols-1)) continue;
      assert(!ismine(A, j, k));
      revealed[j][k] = true;
      if (visited[j][k]) continue;
      if (countMines(A, j, k) == 0) bfs.push(Pii(j,k));
    }
  }

  int cntRevealed = 0; for (Vb i : revealed) cntRevealed += count(All(i), true);

  if (mines > 0) goto fail;
  // dprintf("cntRevealed: %d, %d, %d\n", cntRevealed, mineCount, rows * cols);
  if (cntRevealed + mineCount < rows * cols) goto fail;

  printf("Case #%d:\n", casenum);
  for (string s : A) cout << s << endl;
  fflush(NULL);
  return;

 fail:
  printf("Case #%d:\nImpossible\n", casenum);
  // if (debug) {
  //   for (string s : A) cout << s << endl;
  // }
  // dprintf("Mines left: %d\n", mines);
  fflush(NULL);
  return;
}
// }}}

// {{{ Brute force

int bitcount(int i) {
  if (i < 0) return bitcount(-i);
  int s = 0;
  while (i != 0) s += i&1, i >>= 1;
  return s;
}

int countRevealed(vector<string> A, Pii start) {
  int rows = A.size(), cols = A[0].size();

  queue<Pii> bfs; bfs.push(start);
  vector<Vb> visited(rows, Vb(cols, false));
  vector<Vb> revealed(rows, Vb(cols, false));

  while (!bfs.empty()) {
    Pii p = bfs.front(); bfs.pop();
    visited[p.first][p.second] = revealed[p.first][p.second] = true;
    assert (!ismine(A, p.first, p.second));
    if (countMines(A, p.first, p.second) == 0) {
      int dR[8] = {0, -1, -1, -1, 0, 1, 1, 1};
      int dC[8] = {1, 1, 0, -1, -1, -1, 0, 1};
      for (int i = 0; i < 8; ++i) {
        int j = p.first + dR[i], k = p.second + dC[i];
        if (!Bounded(j, 0, rows-1) || !Bounded(k, 0, cols-1)) continue;
        assert(!ismine(A, j, k));
        revealed[j][k] = true;
        if (countMines(A, j, k) == 0 && !visited[j][k]) bfs.push(Pii(j,k));
      }
    }
  }

  int cnt = 0;
  for (const Vb& v : revealed) cnt += count(All(v), true);
  return cnt;
}

void solve2(int casenum) {
  dprintf("==================================================% 3d\n", casenum);

  int rows, cols, mines;
  cin >> rows >> cols >> mines;
  int mineCount = mines;

  printf("Case #%d:\n", casenum);

  for (int places = 0; places < (1<<(rows*cols)); ++places) {
    if (bitcount(places) != mines) continue;
    vector<string> A(rows, string(cols, '.'));
    for (int i = 0; i < rows*cols; ++i) {
      if ((1<<i) & places) A[i/cols][i%cols] = '*';
    }
    int cnt = 0;
    for (string v : A) cnt += count(All(v), '*');
    assert(cnt == mines);
    for (int cI = 0; cI < rows; ++cI) {
      for (int cJ = 0; cJ < cols; ++cJ) {
        if (A[cI][cJ] == '*') continue;
        if (mines + countRevealed(A, Pii(cI, cJ)) == rows * cols) {
          A[cI][cJ] = 'c';
          for (string s : A) cout << s << endl;
          goto success;
        }
      }
    }
  }

  printf("Impossible\n");
  return;

 success:
  return;
}

// }}}

int main(int argc, char** argv) {
  if (getenv("NODEBUG") != NULL) debug = false;
  int T; cin >> T;
  if (getenv("CORRECT") != NULL) {
    Loop(i,T) solve_correct(i+1);
  } else {
    //Loop(i,T) solve(i+1);
    Loop(i,T) solve2(i+1);
  }
  return 0;
}

// Local variables:
// compile-command: "g++ -Wall -g -o C C.cc"
// End:
