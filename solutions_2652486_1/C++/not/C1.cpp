#include<iostream>
#include<set>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

int main() {
  int t;
  cin >> t;
  cout << "Case #1:" << endl;
  int r, n, m, k;
  cin >> r >> n >> n >> k;
  rep (iii, r) {
    int v[k];
    rep (j, k) cin >> v[j];
    int three = 0, five = 0, seven = 0;
    rep (j, k) {
      int vv = v[j], tt = 0;
      while (vv % 3 == 0) {
	++tt;
	vv /= 3;
      }
      three = max(three, tt);
    }
    rep (j, k) {
      int vv = v[j], tt = 0;
      while (vv % 5 == 0) {
	++tt;
	vv /= 5;
      }
      five = max(five, tt);
    }
    rep (j, k) {
      int vv = v[j], tt = 0;
      while (vv % 7 == 0) {
	++tt;
	vv /= 7;
      }
      seven = max(seven, tt);
    }
    bool six = true;
    rep (i, k) if (v[i] % 3 == 0 && v[i] % 6 != 0) six = false;
    if (six) rep (i, three) cout << 6;
    else rep (i, three) cout << 3;
    rep (i, five) cout << 5;
    rep (i, seven) cout << 7;
    int two = 12 - three - five - seven;
    if (six) two -= three;
    int ttt = 0;
    rep (j, k) {
      int vv = v[j], tt = 0;
      while (vv % 2 == 0) {
	++tt;
	vv /= 2;
      }
      ttt = max(ttt, tt);
    }
    while (ttt > two * 2 && two > 0) {
      cout << 8;
      ttt -= 3;
      --two;
    }
    while (ttt > two && two > 0) {
      cout << 4;
      ttt -= 2;
      --two;
    }
    rep (i, two) cout << 2;
    cout << endl;
  }
  return 0;
}
