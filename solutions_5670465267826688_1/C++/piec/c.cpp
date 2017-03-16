#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <queue>
#include <bitset>
#include <utility>
#include <stack>
#include <complex>

using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
#define MP make_pair
#define FOR(v,p,k) for(int v=(p);v<=(k);++v)
#define FORD(v,p,k) for(int v=(p);v>=(k);--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()

#define ODD(x) ((x)%2)
#define EVEN(x) (!(ODD(x)))


enum VAL { ONE=0, I, J, K, MINUS_ONE, MINUS_I, MINUS_J, MINUS_K};

static VAL quat_mul[][8] = {
//ONE
{ONE, I, J, K, MINUS_ONE, MINUS_I, MINUS_J, MINUS_K},
//I
{I, MINUS_ONE, K, MINUS_J, MINUS_I, ONE, MINUS_K, J},
//J
{J, MINUS_K, MINUS_ONE, I, MINUS_J, K, ONE, MINUS_I},
//K
{K, J, MINUS_I, MINUS_ONE, MINUS_K, MINUS_J, I, ONE},
//MINUS_ONE
{MINUS_ONE, MINUS_I, MINUS_J, MINUS_K, ONE, I, J, K},
//MINUS_I
{MINUS_I, ONE, MINUS_K, J, I, MINUS_ONE, K, MINUS_J},
//MINUS_J
{MINUS_J, K, ONE, MINUS_I, J, MINUS_K, MINUS_ONE, I},
//MINUS_K
{MINUS_K, MINUS_J, I, ONE, K, J, MINUS_I, MINUS_ONE}
};

class quat {
  VAL v;

public:
  quat(VAL v_) : v(v_) {}
  quat(const quat& rhs) : v(rhs.v) {}

  quat& operator= (const quat& rhs) { this->v=rhs.v; return *this; }
  quat& operator*= (const quat& rhs) { 
    this->v = quat_mul[this->v][rhs.v];
    return *this;
  }

  quat& operator-() {
    *this *= MINUS_ONE;
    return *this;
  }

  quat& pow(LL exponent) {
    exponent %= 4;
    quat& self = *this;
    switch (exponent) {
      case 0: self = ONE; break;
      case 1: break;
      case 2: self*=self; break;
      case 3: self*=self*self; break; 
      default: assert(false);
    }
    return *this; 
  }

  friend quat operator* (const quat& lhs, const quat& rhs) {
    quat q(lhs);
    q*=rhs;
    return q;
  }
  friend bool operator== (const quat& lhs, const quat& rhs) { return lhs.v == rhs.v; }
  friend bool operator!= (const quat& lhs, const quat& rhs) { return lhs.v != rhs.v; }
};

static int NOT_FOUND=-1;

int find_pos(const vector<quat> &tab, const quat &x, const quat &init, bool normal = true) {
  quat pref = init;
  REP(i, tab.size()) {
    if (normal) {
      pref*=tab[i];
    } else {
      pref = tab[i]*pref;
    }
    if (x == pref) return i;
  }
  return NOT_FOUND;
}

int multi_find_pos(const vector<quat> &tab, const quat &x, const quat &mult, int reps, bool normal = true) {
  quat init = ONE;
  int iteration_nr = 0;
  while (reps--) {
    int x_pos = find_pos(tab, x, init, normal);
    if (x_pos != NOT_FOUND) {
      return x_pos + tab.size() * iteration_nr;
    }
    ++iteration_nr;
    init *= mult;
  }
  return NOT_FOUND;
}

int main() {
  int T;
  cin >> T;

  vector<quat> tab;
  tab.reserve(50000);

  FOR(Ti,1,T) {
    int L;
    LL X;
    cin >> L >> X;
    string s;
    cin >> s;
    
    tab.clear();
    REP(i, L) {
      switch (s[i]) {
        case 'i': tab.PB(I); break;
        case 'j': tab.PB(J); break;
        case 'k': tab.PB(K); break;
        default: assert(false);
      }
    }

    bool res = true;
    quat mult(ONE);
    REP(i,L) mult*=tab[i];

    quat powered = mult;
    powered.pow(X);
    if (powered != MINUS_ONE) { //ijk
      res = false;
    } else {
      int reps = min(4LL, X);
      int i_pos = multi_find_pos(tab, I, mult, reps);
      if (i_pos == NOT_FOUND) {
        res = false;
      } else {
        reverse(ALL(tab));
        int k_pos = multi_find_pos(tab, K, mult, reps, false);
        if (k_pos == NOT_FOUND) {
          res = false;
        } else {
          res = ((LL)(i_pos+1 + k_pos+1)) < (X*L);
        }
      }
    }

    printf("Case #%d: %s\n", Ti, res ? "YES" : "NO");
  }
  return 0;
}

