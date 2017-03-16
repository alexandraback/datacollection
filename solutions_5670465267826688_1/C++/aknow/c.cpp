#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en)  for(int i=(st); i<=(int)(en); i++)
#define Forn(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
template <class _T> inline istream& operator << (istream& is, const _T& a) { is.putback(a); return is; }

// Types
typedef long double ld;
typedef signed   long long i64;
typedef signed   long long ll;
typedef unsigned long long u64;
typedef unsigned long long ull;
typedef set < int > SI;
typedef vector < ld > VD;
typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < string > VS;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

//#define debug(...)
#define debug printf

int L;
string pattern;
u64 X;

enum Symbol {
  ONE,
  I,
  J,
  K,
};

class Quaternions {
public:
  Quaternions(): num(ONE), sign(true) {}

  Quaternions(char ch): sign(true) {
    switch (ch) {
      case 'i': num = I; break;
      case 'j': num = J; break;
      case 'k': num = K; break;
    }
  }

  Quaternions(Symbol num, bool sign = true): num(num), sign(sign) {}

  Quaternions(const Quaternions& q): num(q.num), sign(q.sign) {}

  Quaternions operator*(const Quaternions& q) const {
    bool t_sign = sign == q.sign;
    Symbol t_num;
    switch (num) {
      case ONE:
        t_num = q.num;
        break;
      case I:
        switch (q.num) {
          case ONE:
            t_num = I;
            break;
          case I:
            t_num = ONE;
            t_sign = !t_sign;
            break;
          case J:
            t_num = K;
            break;
          case K:
            t_num = J;
            t_sign = !t_sign;
            break;
        }
        break;
      case J:
        switch (q.num) {
          case ONE:
            t_num = J;
            break;
          case I:
            t_num = K;
            t_sign = !t_sign;
            break;
          case J:
            t_num = ONE;
            t_sign = !t_sign;
            break;
          case K:
            t_num = I;
            break;
        }
        break;
      case K:
        switch (q.num) {
          case ONE:
            t_num = K;
            break;
          case I:
            t_num = J;
            break;
          case J:
            t_num = I;
            t_sign = !t_sign;
            break;
          case K:
            t_num = ONE;
            t_sign = !t_sign;
            break;
        }
        break;
    }

    return Quaternions(t_num, t_sign);
  }

  Quaternions power(u64 times) const {
    if (times == 0) return Quaternions(ONE);
    else if (times == 1) return Quaternions(*this);
    else if (times % 2) {
      Quaternions q = Quaternions(*this);
      return q * q.power(times - 1);
    } else {
      Quaternions q = Quaternions(*this);
      Quaternions q2 = q.power(times / 2);
      return q2 * q2;
    }
  }

  bool operator==(const Quaternions& q) const {
    return num == q.num && sign == q.sign;
  }

  bool operator!=(const Quaternions& q) const {
    return !this->operator==(q);
  }

  friend ostream& operator<<(ostream& os, const Quaternions& q) {
    os << (!q.sign ? "-" : "");
    switch (q.num) {
      case ONE: os << 1; break;
      case I: os << "i"; break;
      case J: os << "j"; break;
      case K: os << "k"; break;
    }
    return os;
  }

  Symbol num;
  bool sign;
};

const Quaternions Q_I = Quaternions(I);
const Quaternions Q_J = Quaternions(J);
const Quaternions Q_K = Quaternions(K);
const Quaternions Q_MINUS_ONE = Quaternions(ONE, false);

vector<Quaternions> from_left, from_right;

bool run() {
  if (X * L < 3) return false;

  from_left.clear();
  Quaternions current;
  for (int i = 0; i < L; ++i) {
    Quaternions next = Quaternions(pattern[i]);
    current = current * next;
    from_left.push_back(current);
  }

  from_right.clear();
  current = Quaternions(ONE);
  for (int i = 0; i < L; ++i) {
    Quaternions next = Quaternions(pattern[L-i-1]);
    current = next * current;
    from_right.push_back(current);
  }

  Quaternions total = from_left[L-1].power(X);
  if (total != Q_MINUS_ONE) return false;

  // find first i
  vector<Quaternions> current_left = from_left;
  int i_times;
  int i_pos = -1;
  bool found = false;
  for (u64 times = 0; times < X; ++times) {
    for (int i = 0; i < L; ++i) {
      if (current_left[i] == Q_I) {
        i_pos = i;
        i_times = times;
        found = true;
        break;
      }
    }
    if (found) break;

    for (int i = 0; i < L; ++i) {
      current_left[i] = from_left[L-1] * current_left[i];
    }

    // repeat.
    if (current_left[0] == from_left[0]) {
      return false;
    }
  }

  // find last k
  vector<Quaternions> current_right = from_right;
  int k_times;
  int k_pos = -1;
  found = false;
  for (u64 times = 0; times < X; ++times) {
    for (int i = 0; i < L; ++i) {
      if (current_right[i] == Q_K) {
        k_pos = i;
        k_times = times;
        found = true;
        break;
      }
    }
    if (found) break;

    for (int i = 0; i < L; ++i) {
      current_right[i] = current_right[i] * from_right[L-1];
    }

    // repeat.
    if (current_right[0] == from_right[0]) {
      return false;
    }
  }
  u64 i_total_pos = (u64)i_times * L + i_pos + 1;
  u64 k_total_pos = (u64)k_times * L + k_pos + 1;
  return i_total_pos + k_total_pos + 1 <= X * L;
}

int main() {
    int caseN;
    scanf("%d", &caseN);

    for (int cc = 1; cc <= caseN; ++cc) {
        printf("Case #%d: ", cc);

        cin >> L >> X;
        cin >> pattern;

        cout << (run() ? "YES" : "NO");

        printf("\n");
    }

    return 0;
}
