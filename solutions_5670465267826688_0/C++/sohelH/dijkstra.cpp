#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<cmath>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>

using namespace std;

#define DEBUG(x) cout<<">> "<<#x<<':'<<(x)<<endl
const int inf = 1000000000;

int mat[4][4] = {
	0, 1, 2, 3,
	1, 0, 3, 2,
	2, 3, 0, 1,
	3, 2, 1, 0
};

int sign[4][4] = {
	1, 1, 1, 1,
	1, -1, 1, -1,
	1, -1, -1, 1,
	1, 1, -1, -1
};

string s;
long long L, X;

int calSymbol() {
	int cur = 0;
	for (int i = 0; i < s.size(); i++) {
		cur = mat[cur][s[i] - 'i' + 1];
	}
	return cur;
}

int calSign() {
	int cur = 0;
	int sn = 1;
	for (int i = 0; i < s.size(); i++) {
		sn = sn * sign[cur][s[i] - 'i' + 1];
		cur = mat[cur][s[i] - 'i' + 1];
	}
	return sn;
}

#define NO "NO"
#define YES "YES"

long long calIIndex() {
	int cur = 0;
	long long cnt = 0;
	int sn = 1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < L; j++) {
			sn = sn * sign[cur][ s[j] - 'i' + 1];
			cur = mat[cur][ s[j] - 'i' + 1];
			if (cur == 1 && sn == 1) return cnt;
			cnt++;
		}
	}
	return -1;
}

long long calKIndex() {
	int cur = 0;
	int sn = 1;
	long long cnt = L * X - 1;
	for (int i = 0; i < 4; i++) {
		for (int j = L - 1; j >= 0; j--) {
			sn = sn * sign[s[j] - 'i' + 1][ cur ];
			cur = mat[ s[j] - 'i' + 1][ cur ];
			if (cur == 3 && sn == 1) return cnt;
			cnt--;
		}
	}
	return -1;
}

int main() {
	int test, cases = 1;
	cin >> test;
	for (cases = 1; cases <= test; cases++) {
		cin >> L >> X;
		cin >> s;

		int symbol = calSymbol();
		int sn = calSign();

		bool ok = true;
		if (symbol == 0) {
			if (sn == 1) ok = false;
			if (X % 2 == 0) ok = false;
		} else {
			if ( (X + 2) % 4 != 0) ok = false;
		}

		if (!ok) {
			cout << "Case #" << cases << ": " << NO << endl;
			continue;
		}

		long long int iIndex = calIIndex();
		long long int kIndex = calKIndex();

		if (iIndex == -1 || kIndex == -1) {
			cout << "Case #" << cases << ": " << NO << endl;
			continue;
		}

		if (kIndex - iIndex >= 2) {
			cout << "Case #" << cases << ": " << YES << endl;
		} else {
			cout << "Case #" << cases << ": " << NO << endl;
		}
	}
	return 0;
}
