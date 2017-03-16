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


const int N = 4;

void solve() {
  int n;
  vector<double> a, b;
  cin >> n;
  rep(i, n) {
    double tmp; cin >> tmp;
    a.pb(tmp);
  }
  rep(i, n) {
    double tmp; cin >> tmp;
    b.pb(tmp);
  }
  sort(all(a)); sort(all(b));
  //dbg("A:", a); dbg("B:", b);
  vector<int> perm(n);
  rep(i, n) perm[i] = i;
  // war
  int war_score = 0;
  vector<double> cb(b);
  rep(i, n) {
    double crit = a[i];
    int bidx = -1;
    rep(j, n) if (cb[j] > crit) {
      bidx = j; break;
    }
    if (bidx < 0) { // not found
      rep(j, n) if (cb[j] > 0) {
        cb[j] = -1;
        ++war_score;
        break;
      }
    } else {
      cb[bidx] = -1;
    }
  }
  // deciteful war
  rep(i, n) cb[i] = b[i];
  int decwar_score = 0;
  rep(i, n) {
    double b_mn, b_mx = -1;
    int b_mni = -1, b_mxi = -1;
    rep(i, n) if (cb[i] > 0) {
      if (b_mni < 0 || cb[i] < b_mn) {
        b_mn = cb[i];
        b_mni = i;
      }
      if (cb[i] > b_mx) {
        b_mx = cb[i];
        b_mxi = i;
      }
    }
    if (a[i] > b_mn) {
      cb[b_mni] = -1;
      ++decwar_score;
    } else {
      cb[b_mxi] = -1;
    }
  }
  cout << decwar_score << " " << war_score;
}

int main(int argc, char *argv[]) {
  // cin.tie(0); cout.sync_with_stdio(false);
  int TT;
  cin >> TT;
  rep(I, TT) {
    cout << "Case #" << I+1 << ": "; solve(); cout << endl;
  }
  return 0;
}
