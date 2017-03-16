#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

class BigInt {

public:
  vector<int> v;
  BigInt() : v(1, 0) {}
  BigInt(const int& i) : v(1, i) {}
  BigInt(const vector<int>& iv) : v(iv) {}
};

BigInt operator-(const BigInt& a, const BigInt& b) {
  const vector<int> &lhs = a.v, &rhs = b.v;
  int l = lhs.size(), r = rhs.size();

  vector<int> v;
  int carry = 0, tmp, i;
  for (i = 0; i < r; ++i) {
    tmp = lhs[i] - rhs[i] - carry;
    if (tmp < 0) {
      v.push_back(tmp + 10);
      carry = 1;
    } else {
      v.push_back(tmp);
      carry = 0;
    }
  }

  for (; i < l; ++i) {
    tmp = lhs[i] - carry;
    if (tmp < 0) {
      v.push_back(tmp + 10);
      carry = 1;
    } else {
      v.push_back(tmp);
      carry = 0;
    }
  }

  while (!v.empty() && v.back() == 0) {
    v.pop_back();
  }
  return v.empty() ? BigInt() : BigInt(v);
}

string c, j;
char bufc[100], bufj[100];
char solc[100], solj[100];
int minDiff, minJ;

void dfs(int valc, int ixc, int valj, int ixj) {
	if (ixc == c.length() && ixj == j.length()) {
		int diff = abs(valc - valj);
		if (diff < minDiff || (diff == minDiff && valj < minJ)) {
			minDiff = diff;
			minJ = valj;
			memcpy(solc, bufc, sizeof(bufc));
			memcpy(solj, bufj, sizeof(bufj));
		}
		return;
	}

	if (ixc == c.length()) {
		if (bufj[ixj] == '?') {
			for (int i = 0; i < 10; ++i) {
				bufj[ixj] = char('0' + i);
				dfs(valc, ixc, valj * 10 + i, ixj+1);
				bufj[ixj] = '?';
			}
		} else {
			dfs(valc, ixc, valj * 10 + (int)(bufj[ixj] - '0'), ixj+1);
		}
		return;
	}

	if (bufc[ixc] == '?') {
		for (int i = 0; i < 10; ++i) {
			bufc[ixc] = char('0' + i);
			dfs(valc * 10 + i, ixc+1, valj, ixj);
			bufc[ixc] = '?';
		}
	} else {
		dfs(valc * 10 + (int)(bufc[ixc] - '0'), ixc+1, valj, ixj);
	}
}

void solve() {
	minDiff = 999;
	minJ = 999;
	
	bufc[c.length()] = '\0';
	for (int i = 0; i < c.length(); ++i) {
		bufc[i] = c[i];
	}

	bufj[j.length()] = '\0';
	for (int i = 0; i < j.length(); ++i) {
		bufj[i] = j[i];
	}
	dfs(0, 0, 0, 0);
	printf("%s %s\n", solc, solj);
}


int main() {
	int t;
	cin >> t;
	
	for (int tt = 1; tt <= t; ++tt) {
		cin >> c >> j;
		cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}