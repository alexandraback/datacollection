#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <bitset>
#include <iterator>
#include <valarray>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <tuple>
#include <initializer_list>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(c) (c).begin(),(c).end()
#define mt make_tuple
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef tuple<int, int> tii;
template<typename T> ostream &operator<<(ostream &os, set<T> const &s);template<typename T, typename U> ostream &operator<<(ostream &os, map<T, U> const &mp);template<typename T> ostream &operator<<(ostream &os, vector<T> const &v);template<typename... Types> ostream& operator<<(ostream &os, tuple<Types...> const &v);template<typename T> ostream &operator<<(ostream &os, set<T> const &s);
template<typename T> ostream &operator<<(ostream &os, set<T> const &s) { if (s.size() == 0) return os << "{}"; os << "{"; decltype(s.begin()) iter; for (iter = s.begin(), ++iter; iter != s.end(); ++iter) { --iter; os << *iter << ", "; ++iter; } --iter; os << *iter << '}'; return os; }
template<typename T, typename U> ostream &operator<<(ostream &os, map<T, U> const &mp) { if (mp.size() == 0) return os << "{}"; os << "{" << endl; decltype(mp.begin()) iter; for (iter = mp.begin(), ++iter; iter != mp.end(); ++iter) { --iter; os << "  {" << iter->first << ", " << iter->second << "}," << endl; ++iter; } --iter; os << "  {" << iter->first << ", " << iter->second << "}" << endl << '}'; return os; }
template<typename T> ostream &operator<<(ostream &os, vector<T> const &v) { os << '['; rep(i, v.size()-1) os << v[i] << ", "; if (v.size() > 0) os << v[v.size()-1]; cerr << ']'; return os; }
template<typename T, unsigned N, unsigned Last> struct TuplePrinter { static void print(ostream &os, T const& v) { os << std::get<N>(v) << ", "; TuplePrinter<T, N + 1, Last>::print(os, v); } };
template<typename T, unsigned N> struct TuplePrinter<T, N, N> { static void print(ostream &os, T const &v) { os << std::get<N>(v); } };
template<typename... Types> ostream& operator<<(ostream &os, tuple<Types...> const &v) { os << "("; TuplePrinter<tuple<Types...>, 0, sizeof...(Types) - 1>::print(os, v); os << ")"; return os; }
template<typename T> void _dbg(T const &t) { cerr << t << endl; }
template<typename T, typename... Args> void _dbg(T const &t, Args... args) { cerr << t << " "; _dbg(args...); }
template<typename... Args> void __dbg(const char *fn, int l, Args... args) { cerr << "[" << fn << ":" << l << "] "; _dbg(args...); }
#define dbg(...) __dbg(__func__, __LINE__, __VA_ARGS__)

const ll infty = 1223372036854775807;
const double eps = 1e-8;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};


struct Solver {

int n, m, k;
char board[20][20]; // 0 : unvisited, 1 : stone, 2 : undetermined, 3 : enclosed, 4 : unenclosed

void printBoard() {
  rep(i, n) {
    rep(j, m) cerr << board[i][j];
    cerr << endl;
  }
  cerr << endl;
}

void dfs_visit(int x, int y) {
  if (board[x][y] == '*') return;
  board[x][y] = '^';
  rep(i, 4) {
    int newX = x + dx[i], newY = y + dy[i];
    if ((newX < 0 || newX > n-1 || newY < 0 || newY > m-1) || board[newX][newY] == '*') {
      continue;
    }
    if (board[newX][newY] == ' ') {
      dfs_visit(newX, newY);
    }
  }
}

bool chk(int state) {
  rep(i, n) rep(j, m) {
    int idx = i * m + j;
    board[i][j] = (((state >> idx) & 1) != 0) ? '*' : ' ';
  }
  rep(i, n) dfs_visit(i, 0);
  rep(i, n) dfs_visit(i, m-1);
  rep(j, m) dfs_visit(0, j);
  rep(j, m) dfs_visit(n-1, j);
  int cnt = 0;
  rep(i, n) rep(j, m) if (board[i][j] == ' ' || board[i][j] == '*') ++cnt;
  /*
  if (cnt > __builtin_popcount(state)) {
    printBoard();
  }
  */
  return cnt >= k;
}

ll solve() {
  cin >> n >> m >> k;
  int num = n * m;
  int ans = k+1;
  rep(state, (1 << num)) if (__builtin_popcount(state) < ans) {
    if (chk(state)) {
      ans = min(ans, __builtin_popcount(state));
    }
  }
  return ans;
}

};

int main(int argc, char *argv[]) {
  // cin.tie(0); cout.sync_with_stdio(false);
  int TT;
  cin >> TT;
  rep(I, TT) {
    cout << "Case #" << I+1 << ": " << Solver().solve() << endl;
    //printf("Case #%d: %.10f\n", I+1, solve());
    //cout << "Case #" << I+1 << ": "; solve(); cout << endl;
  }
  return 0;
}
