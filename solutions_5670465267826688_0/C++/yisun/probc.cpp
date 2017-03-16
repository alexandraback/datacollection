#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

fstream in, out;

int T;
int L;
int X;

string word;

vector<vector<int>> VAL = {{0, 1, 2, 3}, {1, 0, 3, 2}, {2, 3, 0, 1}, {3, 2, 1, 0}};
vector<vector<int>> VAL_SIGN = {{1, 1, 1, 1}, {1, -1, 1, -1}, {1, -1, -1, 1}, {1, 1, -1, -1}};

class Quat {
public:
  Quat(int sign, int val) : sign_(sign), val_(val) {}

  int sign_;
  int val_;  // 0 = 1, 1 = i, 2 = j, 3 = k
};

Quat operator*(const Quat & a, const Quat & b) {
  return Quat(a.sign_ * b.sign_ * VAL_SIGN[a.val_][b.val_], VAL[a.val_][b.val_]);
}

vector<Quat> quats;

Quat qpow(Quat a, int exp) {
  Quat ret(1, 0);
  for (int i = 0; i < exp % 4; ++i) {
    ret = ret * a;
  }
  return ret;
}

int main() {
  in.open("C-small-attempt0.in", fstream::in);
  out.open("probc-small.out", fstream::out);

  string ans;
  in >> T;
  for (int i = 0; i < T; i++) {
    in >> L >> X;
    in >> word;
    quats.clear();
    for (int j = 0; j < L; ++j) {
      if (word[j] == 'i') {
	quats.push_back(Quat(1, 1));
      } else if (word[j] == 'j') {
	quats.push_back(Quat(1, 2));
      } else if (word[j] == 'k') {
	quats.push_back(Quat(1, 3));
      }
    }

    Quat prod = Quat(1, 0);
    for (int j = 0; j < L; ++j) {
      prod = prod * quats[j];
    }
    prod = qpow(prod, X);

    cout << "i " << i << " prod.val " << prod.val_ << " prod.sign " << prod.sign_ << endl;

    int i_loc = -1;
    int k_loc = -1;
    if (prod.val_ != 0 || prod.sign_ != -1) {
      ans = "NO";
    } else {
      prod = Quat(1, 0);
      for (int j = 0; j < 5 * L; ++j) {
	prod = prod * quats[j % L];
	if (prod.val_ == 1 && prod.sign_ == 1) {
	  i_loc = j;
	  break;
	}
      }

      prod = Quat(1, 0);
      for (int j = 5 * L - 1; j >= 0; --j) {
	prod = quats[j % L] * prod;
	if (prod.val_ == 3 && prod.sign_ == 1) {
	  k_loc = 5 * L - 1 - j;
	  break;
	}
      }

      long long L_big = L;
      long long X_big = X;
      long long total = L_big * X_big;
      long long i_loc_big = i_loc;
      long long k_loc_big = k_loc;

      cout << "i " << i <<  " qL " << L_big << " X " << X << " total " << total << " i_loc " << i_loc_big << " k_loc " << k_loc_big << endl;
      if (i_loc != -1 && k_loc != -1 && i_loc_big < total - k_loc_big) {
	ans = "YES";
      } else {
	ans = "NO";
      }
    }
    out << "Case #" << i + 1 << ": " << ans << endl;
  }
    
  in.close();
  out.close();
  return 0;
}
