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
template<typename T> void dbg(T const &t) { cerr << t << endl; }
template<typename T, typename... Args> void dbg(T const &t, Args... args) { cerr << t << " "; dbg(args...); }

const ll infty = 1223372036854775807;
const double eps = 1e-8;


int R, C, mines;

int printMat(ostream &os, vector<int> width) {
  vector<vector<char>> mat(R+1, vector<char>(C+1, '*')); // guard for +1
  rep(i, R) {
    rep(j, width[i]) {
      mat[i][j] = mat[i][j+1] = mat[i+1][j] = mat[i+1][j+1] = '.';
    }
  }
  mat[0][0] = 'c';
  rep(i, R) {
    rep(j, C) os << mat[i][j];
    os << endl;
  }
  int res = 0;
  rep(i, R) rep(j, C) if (mat[i][j] == '.' || mat[i][j] == 'c') ++res;
  return res;
}

void solve() {
  cin >> R >> C >> mines;
  dbg(R, C, mines, R*C-mines);
  if (R == 1) {
    cout << 'c';
    rep(_, C - mines - 1) cout << '.';
    rep(_, mines) cout << '*';
    cout << endl;
    return;
  }
  if (C == 1) {
    cout << 'c' << endl;
    rep(_, R - mines - 1) cout << '.' << endl;
    rep(_, mines) cout << '*' << endl;
    return;
  }
  assert(R > 1 && C > 1);
  int left = R * C - mines;
  if (left == 1) {
    cout << 'c';
    rep(_, C - 1) cout << '*'; cout << endl;
    rep(_, R-1) {
      rep(__, C) cout << '*'; cout << endl;
    }
    return;
  }
  if (left < 4) {
    cout << "Impossible" << endl;
    return;
  }
  vector<int> width(R, 0);
  rep(i, R-1) {
    if (i == 0) {
      if (left % 2 == 0 && left / 2 <= C) { // ぴったり
        width[i] = left / 2 - 1;
        left = 0;
        break;
      }
      // 1だけ余るのは最悪だから，2以上残せる中でなるべく最大の数を選ぶ
      width[i] = min(C-1, (left - 2) / 2 - 1);
      if (width[i] > 0) {
        left -= (2 * width[i] + 2);
      }
    } else { // i > 0
      if (left == 1) {
        // impossible
        break;
      }
      int mx = width[i-1];
      // 1だけ余るのは最悪だから，2以上残せる中でなるべく最大の数を選ぶ
      width[i] = min(mx, left-1);
      if (left - (width[i] + 1) == 1) --width[i];
      //dbg("step:", i, "left:", left, "width:", width[i]);
      if (width[i] > 0) {
        left -= (width[i] + 1);
        if (left == 0) break;
      }
    }
  }
  dbg(width);
  if (left == 0) {
    int num = printMat(cout, width);
    if (num != R*C-mines) {
      dbg("WRONG!!!!!!!!!!!!!!");
    }
  } else {
    cout << "Impossible" << endl;
  }
}

int main(int argc, char *argv[]) {
  // cin.tie(0); cout.sync_with_stdio(false);
  int TT;
  cin >> TT;
  rep(I, TT) {
    cout << "Case #" << I+1 << ":" << endl;
    solve();
  }
  return 0;
}
