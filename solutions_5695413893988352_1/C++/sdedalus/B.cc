// {{{ Includes

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wall"
#pragma clang diagnostic ignored "-Wextra"
#include <boost/multiprecision/gmp.hpp>
#pragma clang diagnostic pop

#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wunused-macros"
#pragma clang diagnostic ignored "-Wmissing-prototypes"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wsign-compare"

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
#include <chrono>
using namespace std;

static bool debug = true;

// }}}
// {{{ Utilities

#define Loop(i, n) for (int i = 0; i < int(n); ++i)
#define Loopa(i, a, b) for (int i = (a); i <= (b); ++i)
#define Loopd(i, a, b) for (int i = (a); i >= (b); --i)

template <typename T, typename Q, typename S>
bool Bounded(const T &x, const Q &a, const S &b) {
  return a <= x && x <= b;
}

#define db(x) #x << "=" << x
#define pdb(x) printf("#x = %d\n", x);
#define All(x) x.begin(), x.end()
template <typename T> int sz(const T &x) { return x.size(); }
template <typename T, typename Q> bool mem(const T &s, const Q &x) {
  return s.find(x) != s.end();
}
typedef long double ld;
typedef long long int ll;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
typedef vector<Vi> Adj;
typedef vector<bool> Vb;
#define CI(x) x::const_iterator
#define II(x) x::iterator

template <typename T> int sign(const T &x) {
  return x == 0 ? 0 : x > 0 ? 1 : -1;
}
template <typename T> T square(const T &x) { return x * x; }

template <typename T, typename S> T &Car(pair<T, S> &p) { return p.first; }
template <typename T, typename S> S &Cdr(pair<T, S> &p) { return p.second; }
template <typename T, typename S> const T &Car(const pair<T, S> &p) { return p.first; }
template <typename T, typename S> const S &Cdr(const pair<T, S> &p) { return p.second; }
template <typename T, typename S, typename Q> T &Caar(pair<pair<T, S>, Q> &p) {
  return p.first.first;
}
template <typename T, typename S, typename Q> S &Cdar(pair<pair<T, S>, Q> &p) {
  return p.first.second;
}
template <typename T, typename S, typename Q> T &Cadr(pair<Q, pair<T, S>> &p) {
  return p.second.first;
}
template <typename T, typename S, typename Q> S &Cddr(pair<Q, pair<T, S>> &p) {
  return p.second.second;
}

template <typename T> struct leq_by {
  const vector<T> *v;
  leq_by(const vector<T> &v_) : v(&v_) {}
  bool operator()(int i, int j) { return v->at(i) < v->at(j); }
};

template <typename S, typename T>
istream& operator>>(istream& in, pair<S, T>& p) {
  return in >> Car(p) >> Cdr(p);
}
template <typename S, typename T>
ostream& operator<<(ostream& out, const pair<S, T>& p) {
  return out << "{" << Car(p) << ", " << Cdr(p) << "}";
}

template <typename T> void read(T &cnt) {
  for (auto &x : cnt) {
    cin >> x;
  }
}
template <typename T> void read(int n, T &it) {
  Loop(i, n) { cin >> *it++; }
}
template <typename T> void umin(T &x, const T &y) { x = min(x, y); }
template <typename T> void umax(T &x, const T &y) { x = max(x, y); }

template <typename T, typename F, typename... Types>
T &Update(T &x, F fun, Types... args) {
  return x = fun(x, args...);
}

// }}}
// {{{ Output

template <typename T> struct show_container {
  const T &container;
  show_container(const T &container_) : container(container_) {}
};
template <typename T>
ostream &operator<<(ostream &o, const show_container<T> &thing) {
  bool first = true;
  o << "{";
  for (const auto &x : thing.container) {
    if (!first)
      o << ", ";
    first = false;
    o << x;
  }
  o << "}";
  return o;
}

template <typename T> show_container<T> show(const T &container) {
  return show_container<T>(container);
}

struct outboth {
  ostream &a;
  ostream &b;
  outboth(ostream &a_, ostream &b_) : a(a_), b(b_) {}
};
template <typename T> outboth &operator<<(outboth &both, const T &thing) {
  both.a << thing;
  both.b << thing;
  return both;
}
outboth &operator<<(outboth &both, ostream &(*thing)(ostream &)) {
  both.a << thing;
  both.b << thing;
  return both;
}

// }}}
// {{{ Common algorithms

template <typename T, typename F>
T isearch(T low, T high, F pred) {
  assert(low < high);
  assert(!pred(low));
  assert(pred(high));
  while (high >= low + 2) {
    T m = sign(low) == sign(high)
      ? low + (high - low) / 2
      : (high + low) / 2;
    if (pred(m)) high = m;
    else low = m;
  }
  return low;
}

// }}}
// {{{ Solver known to be correct

bool checkdigits(int x, string digits) {
  int n = sz(digits);
  Loop(i, n) {
    if (digits[n-1-i] != '?') {
      if (digits[n-1-i] != '0' + (x%10)) {
        return false;
      }
    }
    x /= 10;
  }
  return true;
}

void solve_correct(int casenum, outboth rout) {
  printf("==================================================% 3d\n", casenum);
  auto startTime = std::chrono::steady_clock::now();

  string C, J; cin >> C >> J;
  int N = sz(C);

  int minAbs = numeric_limits<int>::max();
  int upper = int(pow(10.0, N));
  int resultC = -1, resultJ = -1;

  Loop(c, upper) {
    if (!checkdigits(c, C)) continue;
    Loop(j, upper) {
      if (!checkdigits(j, J)) continue;

      if (minAbs > abs(c-j)) {
        minAbs = abs(c-j);
        resultC = c;
        resultJ = j;
      }
    }
  }


  rout << "Case #" << casenum << ": "
       << setfill('0') << setw(N) << resultC
       << " "
       << setfill('0') << setw(N) << resultJ << endl;

  std::chrono::duration<double> elapsed = std::chrono::steady_clock::now() - startTime;
  cout << "Elapsed: " << elapsed.count() << endl;
}

// }}}
// {{{ Solver

ll fromDigits(string digits) {
  int n = sz(digits);
  ll r = 0;
  Loop(i, n) {
    r = 10*r + (digits[i] - '0');
  }
  return r;
}

ll ipow(ll a, int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b%2 != 1) return a * ipow(a*a, b/2);
  return ipow(a*a, b/2);
}

void make(string& C, string& J, int eqpos) {
  // cout << "Make(" << eqpos << "): " << C << " " << J << endl;

  int N = sz(C);
  Loop(i, N) {
    // cout << "(" << i << "/" << eqpos << ", " << C[i] << ", " << J[i] << ")" << endl;
    if (C[i] == '?' && J[i] == '?') {
      if (i < eqpos) {
        C[i] = J[i] = '0';
      } else if (i == eqpos) {
        C[i] = '1';
        J[i] = '0';
      } else {
        C[i] = '0';
        J[i] = '9';
      }
    } else if (C[i] == '?') {
      if (i < eqpos) {
        C[i] = J[i];
      } else if (i == eqpos && J[i] < '9') {
        C[i] = J[i] + 1;
      } else {
        C[i] = '0';
      }
    } else if (J[i] == '?') {
      if (i < eqpos) {
        J[i] = C[i];
      } else if (i == eqpos && C[i] > '0') {
        J[i] = C[i]-1;
      } else {
        J[i] = '9';
      }
    }
    // cout <<  C << " " << J << endl;
  }

  // cout << "Make(" << eqpos << "): " << C << " " << J << endl;
}

void solve(int casenum, outboth rout) {
  printf("==================================================% 3d\n", casenum);
  auto startTime = std::chrono::steady_clock::now();

  assert(fromDigits("123456789123456789") == 123456789123456789ll);

  string C, J; cin >> C >> J;
  string C0 = C, J0 = J;
  int N = sz(C);
  cout << C << " " << J << endl;

  ll result = numeric_limits<ll>::max(), cResult = -1, jResult = -1;

  for (int eqpos = 0; eqpos <= N+1; ++eqpos) {
    string C1 = C, J1 = J;
    make(C1, J1, eqpos);
    ll cval = fromDigits(C1), jval = fromDigits(J1);

    if (abs(cval - jval) < result
      || (abs(cval - jval) == result
        && (cval < cResult || (cval == cResult && jval < jResult)))) {
      result = abs(cval - jval);
      cResult = cval;
      jResult = jval;
    }

    C1 = J, J1 = C;
    make(C1, J1, eqpos);
    swap(C1, J1);
    cval = fromDigits(C1), jval = fromDigits(J1);
    if (abs(cval - jval) < result
      || (abs(cval - jval) == result
        && (cval < cResult || (cval == cResult && jval < jResult)))) {
      result = abs(cval - jval);
      cResult = cval;
      jResult = jval;
    }
  }

  // string C1 = C, J1 = J;
  // bool failed = false;
  // Loop(i, N) {
  //   if (C1[i] == '?' && J1[i] == '?') {
  //     C1[i] = J1[i] = '0';
  //   } else if (C1[i] == '?') {
  //     C1[i] = J1[i];
  //   } else if (J1[i] == '?') {
  //     J1[i] = C1[i];
  //   } else if (C1[i] != J1[i]) {
  //     failed = true;
  //   }
  // }
  // cout << C1 << " " << J1 << endl;
  // if (!failed) {
  //   cResult = fromDigits(C1);
  //   jResult = fromDigits(J1);
  // }

  // cout << "Result: " << cResult << " " << jResult << endl;

  // string C2 = C, J2 = J;
  // bool doneFirst = false;
  // int firstPos = -1;
  // Loop(i, N) {
  //   if (C2[i] == '?' || J2[i] == '?')
  //     firstPos++;
  // }
  // failed = false;
  // Loop(i, N) {
  //   if (C2[i] == '?' && J2[i] == '?') {
  //     if (i < firstPos) {
  //       C2[i] = J2[i] = '0';
  //     } else if (!doneFirst) {
  //       C2[i] = '1';
  //       J2[i] = '0';
  //     } else {
  //       C2[i] = '0';
  //       J2[i] = '9';
  //     }
  //   } else if (C2[i] == '?') {
  //     if (!doneFirst) {
  //       if (J2[i] == '9') failed = true;
  //       C2[i] = J2[i]+1;
  //     } else {
  //       C2[i] = J2[i];
  //     }
  //   } else if (J2[i] == '?') {
  //     if (!doneFirst) {
  //       if (C2[i] == '0') failed = true;
  //       J2[i] = C2[i] - 1;
  //     } else {
  //       J2[i] = C2[i];
  //     }
  //   } else if (C2[i] != J2[i]) {

  //   }
  //   doneFirst = true;
  // }
  // cout << C2 << " " << J2 << endl;
  // ll c2Result = fromDigits(C2), j2Result = fromDigits(J2);

  // if (!failed && c2Result > j2Result) {
  //   if (cResult < 0 ||
  //     abs(fromDigits(C2) - fromDigits(J2)) < abs(cResult - jResult)
  //     || (abs(fromDigits(C2) - fromDigits(J2)) == abs(cResult - jResult)
  //       && (fromDigits(C2) < cResult || (fromDigits(C2) == cResult && fromDigits(J2) == jResult)))) {
  //     cResult = fromDigits(C2);
  //     jResult = fromDigits(J2);
  //   }
  // }
  // cout << "Result: " << cResult << " " << jResult << endl;

  // C2 = J, J2 = C;
  // doneFirst = false;
  // firstPos = -1;
  // Loop(i, N) {
  //   if (C2[i] == '?' || J2[i] == '?')
  //     firstPos++;
  // }
  // failed = false;
  // Loop(i, N) {
  //   if (C2[i] == '?' && J2[i] == '?') {
  //     if (i < firstPos) {
  //       C2[i] = J2[i] = '0';
  //     } if (!doneFirst) {
  //       C2[i] = '1';
  //       J2[i] = '0';
  //     } else {
  //       C2[i] = '0';
  //       J2[i] = '9';
  //     }
  //   } else if (C2[i] == '?') {
  //     if (!doneFirst) {
  //       if (J2[i] == '9') failed = true;
  //       C2[i] = J2[i]+1;
  //     } else {
  //       C2[i] = J2[i];
  //     }
  //   } else if (J2[i] == '?') {
  //     if (!doneFirst) {
  //       if (C2[i] == '0') failed = true;
  //       J2[i] = C2[i] - 1;
  //     } else {
  //       J2[i] = C2[i];
  //     }
  //   } else if (C2[i] != J2[i]) {

  //   }
  //   doneFirst = true;
  // }
  // swap(C2, J2);
  // cout << C2 << " " << J2 << endl;
  // c2Result = fromDigits(C2), j2Result = fromDigits(J2);

  // if (!failed && c2Result < j2Result) {
  //   if (cResult < 0 ||
  //     abs(fromDigits(C2) - fromDigits(J2)) < abs(cResult - jResult)
  //     || (abs(fromDigits(C2) - fromDigits(J2)) == abs(cResult - jResult)
  //       && (fromDigits(C2) < cResult || (fromDigits(C2) == cResult && fromDigits(J2) == jResult)))) {
  //     cResult = fromDigits(C2);
  //     jResult = fromDigits(J2);
  //   }
  // }
  // cout << "Result: " << cResult << " " << jResult << endl;

  // Loop(i, N) {
  //   if (C[i] != '?' && J[i] != '?' && J[i] - C[i] >= 6) {
  //     if (i > 0 && C[i-1] != '?') {
  //       if (J[i-1] == '?') {
  //         J[i-1] = '0';
  //         C[i-1] = '1';
  //       } else {
  //         C[i-1] = J[i-1] + 1;
  //       }
  //     }
  //   }
  // }

  // Loop(i, N) {

  //   if (C[i] == '?' && J[i] == '?') {
  //     if (above) {
  //       C[i] = '0';
  //       J[i] = '9';
  //     } else if (below) {
  //       C[i] = '9';
  //       J[i] = '0';
  //     } else {
  //       C[i] = J[i] = '0';
  //     }
  //   } else if (C[i] == '?') {
  //     if (above) {
  //       C[i] = '0';
  //     } else if (below) {
  //       C[i] = '9';
  //     } else {
  //       C[i] = J[i];
  //     }
  //   } else if (J[i] == '?') {
  //     if (above) {
  //       J[i] = '9';
  //     } else if (below) {
  //       J[i] = '0';
  //     } else {
  //       J[i] = C[i];
  //     }
  //   } else {
  //     if (!(above || below)) {
  //       above = C[i] > J[i];
  //       below = C[i] < J[i];
  //     }
  //   }

  // }

  // long long c = fromDigits(C), j = fromDigits(J);
  // cout << C << " " << J << endl;
  // ll result = abs(c - j), cResult = c, jResult = j;
  // for (int i = N-1; i >= 0; --i) {
  //   ll ten = ipow(10, N-1-i);
  //   if (J0[i] == '?' && J[i] != '9' && abs(c - j - ten) < result) {
  //     jResult += ten;
  //     result = abs(c - j - ten);
  //   }
  //   if (C0[i] == '?' && C[i] != '0' && abs(c - j - ten) <= result) {
  //     cResult -= ten;
  //     result = abs(c - j - ten);
  //   }
  //   if (C0[i] == '?' && C[i] != '9' && abs(c - j + ten) < result) {
  //     cResult += ten;
  //     result = abs(c - j + ten);
  //   }
  //   if (J0[i] == '?' && J[i] != '0' && abs(c - j + ten) <= result) {
  //     jResult -= ten;
  //     result = abs(c - j + ten);
  //   }
  // }

  // Loop(i, N) {

  //   if (C[i] == '?' && J[i] == '?') {
  //     continue;
  //     // if (above) {
  //     //   C[i] = '0';
  //     //   J[i] = '9';
  //     // } else if (below) {
  //     //   C[i] = '9';
  //     //   J[i] = '0';
  //     // } else if (i < N-1 && J[i+1] != '?' && C[i+1] != '?' && J[i+1] - C[i+1] >= 6) {
  //     //   C[i] = '1';
  //     //   J[i] = '0';
  //     // } else if (i < N-1 && J[i+1] != '?' && C[i+1] != '?' && C[i+1] - J[i+1] >= 6) {
  //     //   C[i] = '0';
  //     //   J[i] = '1';
  //     // } else {
  //     //   C[i] = J[i] = '0';
  //     // }
  //   } else if (C[i] == '?') {
  //     if (above) {
  //       C[i] = '0';
  //     } else if (below) {
  //       C[i] = '9';
  //     } else if (i < N-1 && J[i+1] != '?' && C[i+1] != '?' && J[i+1] - C[i+1] >= 6) {
  //       C[i] = '1';
  //     } else if (i < N-1 && J[i+1] != '?' && C[i+1] != '?' && C[i+1] - J[i+1] >= 6) {
  //       C[i] = '0';
  //     } else {
  //       C[i] = J[i];
  //     }
  //   } else if (J[i] == '?') {
  //     if (above) {
  //       J[i] = '9';
  //     } else if (below) {
  //       J[i] = '0';
  //     } else if (i < N-1 && J[i+1] != '?' && C[i+1] != '?' && J[i+1] - C[i+1] >= 6) {
  //       J[i] = '0';
  //     } else if (i < N-1 && J[i+1] != '?' && C[i+1] != '?' && C[i+1] - J[i+1] >= 6) {
  //       J[i] = '1';
  //     } else {
  //       J[i] = C[i];
  //     }
  //   } else {
  //     if (!(above || below)) {
  //       above = C[i] > J[i];
  //       below = C[i] < J[i];
  //     }
  //   }

  // }

  rout << "Case #" << casenum << ": "
       << setfill('0') << setw(sz(C)) << cResult
       << " "
       << setfill('0') << setw(sz(C)) << jResult << endl;

  std::chrono::duration<double> elapsed = std::chrono::steady_clock::now() - startTime;
  cout << "Elapsed: " << elapsed.count() << endl;
}

// }}}
// {{{ Main

int main(int argc, char **argv) {
  debug = getenv("NODEBUG") == NULL;

  string fnIn, fnOut, fnTest;
  shared_ptr<ofstream> outfile;
  if (argc > 1) {
    fnIn = string(argv[1]);
    if (fnIn.substr(fnIn.size() - 3) == ".in") {
      fnOut = fnIn.substr(0, fnIn.size() - 3) + ".last";
      fnTest = fnIn.substr(0, fnIn.size() - 3) + ".out";
    } else {
      fnOut = fnIn + ".last";
      fnTest = fnIn + ".out";
    }
    cout << "Input file " << fnIn << endl
         << "Output file " << fnOut << endl
         << "Testing file " << fnTest << endl;

    freopen(fnIn.c_str(), "r", stdin);
    outfile = make_shared<ofstream>(fnOut);
  } else {
    outfile = make_shared<ofstream>("B.out.last");
  }

  auto startTime = std::chrono::steady_clock::now();

  int T = 0;
  cin >> T;
  assert(!!cin);
  if (getenv("CORRECT") != NULL) {
    Loop(i, T) solve_correct(i + 1, outboth(cout, *outfile));
  } else {
    Loop(i, T) solve(i + 1, outboth(cout, *outfile));
  }

  std::chrono::duration<double> elapsed = std::chrono::steady_clock::now() - startTime;
  cout << "Time taken: " << elapsed.count() << endl;

  int exitcode = 0;

  string cmd = "diff \"" + fnOut + "\" \"" + fnTest + "\"";
  if (access(fnTest.c_str(), F_OK) != -1) {
    cout << "Diff command: " << cmd << endl;
    int ret = system(cmd.c_str());
    cout << "Diff result: " << ret << endl;
    if (ret)
      cout << "OUTPUT FILE DIFFERS FROM TEST FILE" << endl;
    exitcode = ret;
  } else {
    cout << "Diff file missing: " << fnTest << endl;
  }

  return exitcode;
}

// }}}

// clang-format off
// Local variables:
// compile-command: "c++ -fmodules -std=c++11 -Wall -Wextra -g -I/opt/brew/include -L/opt/brew/lib -o B B.cc -lgmp && ./B B.test.in"
// irony-additional-clang-options: ("-std=c++11" "-Wall" "-Wextra" "-I/opt/brew/include" "-I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1")
// End:
