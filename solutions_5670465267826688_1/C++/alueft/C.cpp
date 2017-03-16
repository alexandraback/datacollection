#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;

struct q {
  char c;
  bool p;
  q() {}
  q(char cc, bool pp) : c(cc), p(pp) {}
  q operator*(const q& b) {
    bool P = !(p^b.p);
    char C = '-';
    if (c == '1')
      C = b.c;
    else if (b.c == '1')
      C = c;
    else if (c == b.c) {
      C = '1';
      P = !P;
    }
    else {
      if (c == 'i') {
        if (b.c == 'j')
          C = 'k';
        else {
          C = 'j';
          P = !P;
        }
      }
      else if (c == 'j') {
        if (b.c == 'i') {
          C = 'k';
          P = !P;
        }
        else
          C = 'i';
      }
      else {
        if (b.c == 'i')
          C = 'j';
        else {
          C = 'i';
          P = !P;
        }
      }
    }
    return q(C,P);
  }
};

int main() {
  ios::sync_with_stdio(0);
  int t; cin >> t;
  for (int T = 1; T <= t; T++) {
    ll l, x;
    string s;
    cin >> l >> x >> s;
    q qt(s[0],1), qt2, qi('1',1), qk('1',1);
    bool b = false, ic = false, kc = false;
    ll indi = 0, indk = l*x-1;
    if (l == 1 || l*x < 3)
      goto VELOCIRAPTOR;
    for (ll i = 1; i < l; i++)
      qt = q(qt.c,qt.p)*q(s[i],1);
    qt2 = qt;
    for (ll i = 0; i < ((x+3)%4); i++)
      qt2 = q(qt2.c,qt2.p)*qt;
    //cout << qt2.c << " " << qt2.p << endl;
    if (qt2.p || qt2.c != '1')
      goto VELOCIRAPTOR;
    while (indi < min(4*l,l*x)) {
      qi = q(qi.c,qi.p)*q(s[indi%l],1);
      if (qi.p && qi.c == 'i') {
        ic = true;
        break;
      }
      indi++;
    }
    while (indk >= max(0LL,l*x-4*l)) {
      qk = q(s[indk%l],1)*q(qk.c,qk.p);
      if (qk.p && qk.c == 'k') {
        kc = true;
        break;
      }
      indk--;
    }
    //cout << ic << " " << kc << " " << indi << " " << indk << endl;
    if (ic && kc && indi < indk-1)
      b = true;
    VELOCIRAPTOR:
    cout << "Case #" << T << ": " << (b ? "YES" : "NO") << "\n";
  }
  /*q qs[8];
  qs[0] = q('1',0);
  qs[1] = q('1',1);
  qs[2] = q('i',0);
  qs[3] = q('i',1);
  qs[4] = q('j',0);
  qs[5] = q('j',1);
  qs[6] = q('k',0);
  qs[7] = q('k',1);
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cout << "q1: ";
      if (!qs[i].p)
        cout << "-";
      cout << qs[i].c;
      cout << "\tq2: ";
      if (!qs[j].p)
        cout << "-";
      cout << qs[j].c;
      q q3 = qs[i]*qs[j];
      cout << "\tq3: ";
      if (!q3.p)
        cout << "-";
      cout << q3.c;
      cout << endl;
    }
  }*/
  return 0;
}
