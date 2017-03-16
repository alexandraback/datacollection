#include <boost/multiprecision/gmp.hpp>
#include <boost/multiprecision/miller_rabin.hpp>
typedef boost::multiprecision::mpz_int Integer;
namespace MP = boost::multiprecision;

// {{{ Includes and utilities
#include <fstream>
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

#define Loop(i,n) for (ll i = 0; i < static_cast<ll>(n); ++i)
#define Loopa(i,a,b) for (ll i = (a); i <= (b); ++i)
#define Loopd(i,a,b) for (ll i = (a); i >= (b); --i)

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

template <typename T> int sign(const T& x) { return x == 0 ? 0 : x > 0 ? 1 : -1; }
template <typename T> T square(const T& x) { return x*x; }

template <typename T, typename S>
T& Car(pair<T,S>& p) { return p.first; }
template <typename T, typename S> S& Car(pair<T,S>& p) { return p.second; }
template <typename T, typename S, typename Q> T& Caar(pair<pair<T, S>, Q>& p) { return p.first.first; }
template <typename T, typename S, typename Q> S& Cdar(pair<pair<T, S>, Q>& p) { return p.first.second; }
template <typename T, typename S, typename Q> T& Cadr(pair<Q, pair<T, S> >& p) { return p.second.first; }
template <typename T, typename S, typename Q> S& Cddr(pair<Q, pair<T, S> >& p) { return p.second.second; }

template <typename T>
struct leq_by {
  const vector<T>* v;
  leq_by(const vector<T>& v_) : v(&v_) { }
  bool operator()(int i, int j) { return v->at(i) < v->at(j); }
};

template <typename T> void read(T& cnt) { for (auto& x : cnt) { cin >> x; } }
template <typename T> void read(int n, T& it) { Loop(i,n) { cin >> *it++; } }
template <typename T> void umin(T& x, const T& y) { x = min(x, y); }
template <typename T> void umax(T& x, const T& y) { x = max(x, y); }

static bool debug = true;
#define dprintf debug && printf
template <typename Cnt>
void show(string s, const Cnt& container) {
  if (!debug) return;
  cout << s << ":";
  for (const auto& elt : container) cout << " " << elt;
  cout << endl;
}

// }}}

void solve_correct(ll casenum, ofstream& outfile);
void solve(ll casenum, ofstream& outfile);

// {{{ Solver known to be correct

void solve_correct(ll casenum, ofstream& outfile) {
  dprintf("==================================================% 3lld\n", casenum);
  assert(false);
  fflush(NULL);
}

// }}}

string expandOnce(int K, string s0, string s) {
  ostringstream out;
  for (char c : s) {
    if (c == 'L') {
      out << s0;
    } else {
      out << string(K, c);
    }
  }
  return out.str();
}

string expand(int K, int C, string s0) {
  string s = s0;
  for (int i = 2; i <= C; ++i) {
    s = expandOnce(K, s0, s);
  }
  return s;
}

string fromBinary(int K, unsigned long X) {
  string s(K, 'L');
  for (int i = 0; i < K; ++i) {
    if (X&(1<<i))
      s[K-i-1] = 'G';
  }
  return s;
}

string labelGS(string s) {
  int i;
  char c;
  string r = s;
  for (i = 0, c = 'a'; i < s.size(); ++i, ++c) {
    if (r[i] == 'G')
      r[i] = c;
  }
  return r;
}

Integer toBinary(string s) {
  int n = s.size();
  Integer r = 0;
  Loop(k,n) r = 2*r + (s[n-1-k] == 'G');
  return r;
}

Integer ipow(Integer a, int b) {
  assert(b >= 0);
  if (b == 0) return 1;
  if (b == 1) return a;
  Integer r = ipow(a*a, b/2);
  if (b%2 == 0) return r;
  return r*a;
}

void solve(ll casenum, ofstream& outfile) {
  dprintf("==================================================% 3lld\n", casenum);

  assert(expandOnce(3, "LGL", "L") == "LGL");
  assert(expandOnce(3, "LGL", "LGL") == "LGLGGGLGL");
  assert(expandOnce(3, "LGL", "LGLGGGLGL") == "LGLGGGLGLGGGGGGGGGLGLGGGLGL");
  assert(fromBinary(3, 3) == "LGG");
  assert(fromBinary(3, 4) == "GLL");

  int K, C, S; cin >> K >> C >> S;
  vector<Integer> results;
  vector<int> digits(K);
  Loop(i, K) digits[i] = K-i-1;

  Integer x = 0, Kpow = 1;
  for (int i = 0; i < K; ++i) {
    x += digits[i] * Kpow;
    Kpow *= K;
    if ((i+1)%C == 0 || i == K-1) {
      results.push_back(x+1);
      Kpow = 1;
      x = 0;
    }
  }
  sort(All(results));
  for (Integer k : results) {
    assert(k <= ipow(K, C));
  }

  if (results.size() > S) {
    cout << "Case #" << casenum << ": IMPOSSIBLE" << endl;
    outfile << "Case #" << casenum << ": IMPOSSIBLE" << endl;
  } else {
    cout << "Case #" << casenum << ":";
    outfile << "Case #" << casenum << ":";
    for (Integer ans : results) {
      cout << " " << ans;
      outfile << " " << ans;
    }
    cout << endl;
    outfile << endl;
  }
}

int main(int argc, char** argv) {
  debug = getenv("NODEBUG") == NULL;

  string fnIn, fnOut, fnTest;
  shared_ptr<ofstream> outfile;
  if (argc > 1) {
    fnIn = string(argv[1]);
    ostringstream s; s << fnIn << ".out";
    fnOut = s.str();
    if (fnIn.substr(fnIn.size()-3) == ".in") {
      ostringstream t; t << fnIn.substr(0, fnIn.size()-2) << "out";
      fnTest = t.str();
    }
    fprintf(stderr, "Using input file %s, output file %s, testing file %s.\n", fnIn.c_str(), fnOut.c_str(), fnTest.c_str());

    freopen(fnIn.c_str(), "r", stdin);
    outfile = make_shared<ofstream>(fnOut);
  } else {
    outfile = make_shared<ofstream>("last.out");
  }

  ll T; cin >> T;
  if (getenv("CORRECT") != NULL) {
    Loop(i,T) solve_correct(i+1, *outfile);
  } else {
    Loop(i,T) solve(i+1, *outfile);
  }

  if (fnTest.size() > 0) {
    ostringstream s; s << "diff \"" << fnOut << "\" \"" << fnTest << "\"";
    string cmd = s.str();
    FILE* test_file = fopen(fnTest.c_str(), "r");
    if (test_file) {
      fprintf(stderr, "Diff command: %s\n", cmd.c_str());
      int ret = system(cmd.c_str());
      fprintf(stderr, "Diff result: %d\n", ret);
    } else {
      fprintf(stderr, "Diff file missing: %s\n", fnTest.c_str());
    }
  }

  return 0;
}

// Local variables:
// compile-command: "c++ -I/opt/brew/include -L/opt/brew/lib -std=c++11 -Wall -Wextra -g -o D D.cc -lgmp"
// End:
