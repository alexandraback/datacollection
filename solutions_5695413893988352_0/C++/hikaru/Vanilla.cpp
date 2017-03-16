#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <bitset>
#include <assert.h>
using namespace std;

string C, J;
int length;
int dC[256];
int dJ[256];
int rC, rJ;
int rA;
int maxval;

void to_ds(const string& s, int d[256])
{
	int i = 0;
	for (auto it = s.rbegin(); it != s.rend(); ++it, i++) {
		if (*it == '?') {
			d[i] = -1;
		} else {
			d[i] = *it - '0';
		}
	}
}

void match(int c, int j)
{
	int tc = c;
	for (int i = 0; i < length; i++) {
		if (dC[i] != -1 && tc % 10 != dC[i]) return;
		tc /= 10;
	}
	int tj = j;
	for (int i = 0; i < length; i++) {
		if (dJ[i] != -1 && tj % 10 != dJ[i]) return;
		tj /= 10;
	}
	int A = abs(c - j);
	if (A < rA) {
		rC = c;
		rJ = j;
		rA = A;
	} else if (abs(c - j) == abs(rC - rJ)) {
		if (c < rC) {
			rC = c;
			rJ = j;
			rA = A;
		} else if (c == rC) {
			if (j < rJ) {
				rC = c;
				rJ = j;
				rA = A;
			}
		}
	}
}

void solve()
{
	rA = INT_MAX;
	length = (int) C.length();
	maxval = (int) (pow(10, length) + 0.5);
	to_ds(C, dC);
	to_ds(J, dJ);
	for (int c = 0; c < maxval; c++) {
		for (int j = 0; j < maxval; j++) {
			match(c, j);
		}
	}
}

int main(int argc, char* argv[])
{
	if (argc >= 2) {
		FILE* fp = freopen(argv[1], "r", stdin);
	}

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> C >> J;
		solve();
		cout << "Case #" << i + 1 << ": ";
		cout << setw(C.length()) << setfill('0') << rC << " ";
		cout << setw(C.length()) << setfill('0') << rJ << endl;
	}

	return 0;
}
