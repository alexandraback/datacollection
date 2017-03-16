#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
typedef long long i64;

typedef i64 nkr_int;

typedef pair<i64, i64> pi;

typedef vector<nkr_int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define iter(T) T::iterator
#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define REP(s, e, n)  for(n = (s); n < (e); ++n)

typedef unsigned long long ui64;

struct qt {
  qt(char c) {
    sign = 1;
    switch(c) {
    case '1': ijk1 = QT_1; break;
    case 'i': ijk1 = QT_i; break;
    case 'j': ijk1 = QT_j; break;
    case 'k': ijk1 = QT_k; break;
    default: cout << "error" << endl; break;
    }
  }
  qt(const qt &q0) : sign(q0.sign), ijk1(q0.ijk1) {}
  int sign;
  int ijk1;
  enum {
    QT_1,
    QT_i,
    QT_j,
    QT_k,
  };

  const qt operator*(const qt &rhs) {
    qt ret('1');
    ret.sign = sign * rhs.sign;
    switch(ijk1) {
    case QT_1:
      switch(rhs.ijk1) {
      case QT_1: ret.ijk1 = QT_1; break;
      case QT_i: ret.ijk1 = QT_i; break;
      case QT_j: ret.ijk1 = QT_j; break;
      case QT_k: ret.ijk1 = QT_k; break;
      }
      break;
    case QT_i:
      switch(rhs.ijk1) {
      case QT_1: ret.ijk1 = QT_i; break;
      case QT_i: ret.ijk1 = QT_1; ret.sign *= -1; break;
      case QT_j: ret.ijk1 = QT_k; break;
      case QT_k: ret.ijk1 = QT_j; ret.sign *= -1; break;
      }
      break;
    case QT_j:
      switch(rhs.ijk1) {
      case QT_1: ret.ijk1 = QT_j; break;
      case QT_i: ret.ijk1 = QT_k; ret.sign *= -1; break;
      case QT_j: ret.ijk1 = QT_1; ret.sign *= -1; break;
      case QT_k: ret.ijk1 = QT_i; break;
      }
      break;
    case QT_k:
      switch(rhs.ijk1) {
      case QT_1: ret.ijk1 = QT_k; break;
      case QT_i: ret.ijk1 = QT_j; break;
      case QT_j: ret.ijk1 = QT_i; ret.sign *= -1; break;
      case QT_k: ret.ijk1 = QT_1; ret.sign *= -1; break;
      }
      break;
    }
    return ret;
  }

  friend ostream& operator<<(ostream &os, const qt &q) {
    if(q.sign == -1) {
      os << "-";
    }
    switch(q.ijk1) {
    case QT_i: os << "i"; break;
    case QT_j: os << "j"; break;
    case QT_k: os << "k"; break;
    case QT_1: os << "1"; break;
    }
    return os;
  }
};

class Solver {
public:
  Solver() {}
  ~Solver() {}

  void solve();
};

void Solver::solve() {

  i64 L, X;
  cin >> L >> X;
  string line;
  getchar();
  getline(cin, line);

  i64 i;
  qt q1('1');
  REP(0, L, i) {
    q1 = q1 * qt(line[i]);
  }

  //cout << q1.ijk1 << " " << q1.sign << endl;

  i64 X0 = X;
  qt qa('1');
  qt q2(q1);
  while(X0 != 0) {
    if(X0 % 2 == 1) {
      qa = qa * q2;
    }

    q2 = q2 * q2;
    X0 /= 2;
  }

  //cout << qa.ijk1 << " " << qa.sign << endl;
  if(qa.ijk1 != qt::QT_1 || qa.sign != -1) {
    cout << "NO" << endl;
    return;
  }

  i64 i_len = -1, k_len = -1;
  qt qi('1'), qk('1');
  REP(0, L * 16, i) {
    qi = qi * qt(line[i % L]);
    if(qi.ijk1 == qt::QT_i && qi.sign == 1) {
      i_len = i + 1;
      break;
    }
  }

  REP(0, L * 16, i) {
    qk = qt(line[(L - 1) - (i % L)]) * qk;
    if(qk.ijk1 == qt::QT_k && qk.sign == 1) {
      k_len = i + 1;
      break;
    }
  }

  //cout << i_len << " " << k_len << endl;
  if(i_len > 0 && k_len > 0 && i_len + k_len < L * X) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}

int main(int argc, char *argv[]){
  i64 N;
  cin >> N;
  i64 n;

  Solver s;

  REP(0, N, n) {
    cout << "Case #" << n + 1 << ": ";

    s.solve();
  }

  return 0;
}

