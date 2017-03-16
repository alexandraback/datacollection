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

char plusminus(char x) {
  if (x == '-') return '+';
  if (x == '+') return '-';
  assert(false);
  return 'X';
}

string flip(string s, int k) {
  string p = s;
  int i;
  for (i = 0; i < k-i-1; ++i) {
    char t = p[i];
    p[i] = plusminus(p[k-i-1]);
    p[k-i-1] = plusminus(t);
  }
  if (i == k-i-1) p[i] = plusminus(p[i]);
  return p;
}

void solve(ll casenum, ofstream& outfile) {
  dprintf("==================================================% 3lld\n", casenum);

  assert(flip("-", 0) == "-");
  assert(flip("-", 1) == "+");
  assert(flip("--+-", 3) == string("-++-"));

  string s; cin >> s;
  int n = (int)s.size();
  assert(n >= 1);
  ll count = 0;

  // cout << s << endl;

  while (true) {
    int k;
    for (k = 1; k < n && s[k] == s[0]; ++k);
    if (k == n && s[0] == '-') ++count;
    if (k == n) break;
    ++count;
    s = flip(s, k);
    // cout << s << endl;
  }

  cout << "Case #" << casenum << ": " << count << endl;
  outfile << "Case #" << casenum << ": " << count << endl;

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
// compile-command: "c++ -std=c++11 -Wall -Wextra -g -o B B.cc"
// End:
