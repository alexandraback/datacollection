#include <iostream>
#include <vector>

using namespace std;

bool sgn_mul[4][4] = {
  {0, 0, 0, 0},
  {0, 1, 0, 1},
  {0, 1, 1, 0},
  {0, 0, 1, 1}
};

int q_mul[4][4] = {
  {0, 1, 2, 3},
  {1, 0, 3, 2},
  {2, 3, 0, 1},
  {3, 2, 1, 0}
};

struct quad {
  quad() : s(false), q(0) {
  }

  quad(char ch) {
    s = false;
    switch (ch) {
      case 'i': q = 1; break;
      case 'j': q = 2; break;
      case 'k': q = 3; break;
      default: q = 0;
    }
  }

  quad operator*(const quad& x) const {
    quad r;
    r.q = q_mul[q][x.q];
    r.s = sgn_mul[q][x.q] ^ s ^ x.s;
    return r;
  }

  bool operator==(const quad& x) const {
    return s == x.s && q == x.q;
  }

  bool s;
  int q;
};

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    long long L, X;
    string SS;
    cin >> L >> X;
    cin >> SS;

    if (X > 12) {
      X %= 12;
      X += 12;
    }

    string S;
    for (int i = 0; i < X; i++) {
      S += SS;
    }

    int N = S.size();

    bool ok1 = false;
    bool ok2 = false;

    quad q = 1;
    for (int i = 0; i < N; i++) {
      q = q * quad(S[i]);
      if (q == quad('i')) {
        ok1 = true;
      } else if (ok1 && q == quad('i') * quad('j')) {
        ok2 = true;
      }
    }

    cout << "Case #" << t << ": ";
    if (ok1 && ok2 && q == quad('i') * quad('j') * quad('k')) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
