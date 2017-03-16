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



Integer interpret(long N, ll X, ll B) {
  assert((X&1) != 0);
  assert((X&(1l<<(N-1))) != 0);
  Integer result = 0;
  Integer M = 1;
  for (ll k = 0; k < N; ++k) {
    result += M * ((X&(1ll<<k)) != 0);
    M *= B;
  }
  return result;
}

Integer smallestFactor(Integer X) {
  for (Integer k = 2; k*k <= X; k += 1) {
    if (X%k == 0) return k;
  }
  assert(false);
  return 0;
}

void solve(ll casenum, ofstream& outfile) {
  dprintf("==================================================% 3lld\n", casenum);

  assert(interpret(4, 0b1001, 2) == 9);
  assert(interpret(4, 0b1001, 3) == 28);
  assert(interpret(4, 0b1001, 4) == 65);
  assert(interpret(4, 0b1001, 5) == 126);
  assert(interpret(4, 0b1001, 6) == 217);
  assert(interpret(4, 0b1001, 7) == 344);
  assert(interpret(4, 0b1001, 8) == 513);
  assert(interpret(4, 0b1001, 9) == 730);
  assert(interpret(4, 0b1001, 10) == 1001);

  ll N, J; cin >> N >> J;
  vector<ll> results;

  ll X = (1<<(N-1)) + 1;
  for (ll itCount = 0; itCount < 1e6; ++itCount) {
    bool success = true;
    for (ll B = 2; B <= 10; ++B) {
      Integer maybePrime = interpret(N, X, B);
      bool isPrime = MP::miller_rabin_test(maybePrime, 25);
      if (isPrime) success = false;
    }
    if (success) {
      cout << "Found " << X << endl;
      results.push_back(X);
      if (results.size() == J) {
        break;
      }
    }
    X += 2;
  }

  cout << "Case #" << casenum << ":" << endl;
  for (ll ans : results) {
    cout << interpret(N, ans, 10);
    for (ll B = 2; B <= 10; ++B) {
      cout << " " << smallestFactor(interpret(N, ans, B));
    }
    cout << endl;
  }


  outfile << "Case #" << casenum << ":" << endl;
  for (ll ans : results) {
    outfile << interpret(N, ans, 10);
    for (ll B = 2; B <= 10; ++B) {
      outfile << " " << smallestFactor(interpret(N, ans, B));
    }
    outfile << endl;
  }

  fflush(NULL);
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
// compile-command: "c++ -I/opt/brew/include -L/opt/brew/lib -std=c++11 -Wall -Wextra -g -o C C.cc -lgmp"
// End:
