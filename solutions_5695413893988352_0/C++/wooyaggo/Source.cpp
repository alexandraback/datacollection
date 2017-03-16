#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string>

using namespace std;

char C[111];
char J[111];

long long atoll(std::string s) {
	return _strtoi64(s.c_str(), 0, 10);
}

long long solveA(string A, string B, string& rA, string& rB) {
	int len = A.length();

	long long res = LLONG_MAX;
	for (int i = 0; i < len; i++) {
		string a = A;
		string b = B;
		bool can = false;
		if (a[i] == '?' && b[i] == '?') {
			a[i] = '1';
			b[i] = '0';
			can = true;
		} else if(a[i] == '?') {
			if (b[i] != '9') {
				a[i] = b[i] + 1;
				can = true;
			}
		} else if(b[i] == '?') {
			if (a[i] != '0') {
				b[i] = a[i] - 1;
				can = true;
			}
		} else {
			if (a[i] > b[i]) can = true;
		}

		if (can) {
			for (int j = i + 1; j < len; j++) {
				if (a[j] == '?') a[j] = '0';
				if (b[j] == '?') b[j] = '9';
			}
			long long aa = atoll(a);
			long long bb = atoll(b);
			if (aa >= bb) {
				if ((aa - bb < res) || 
					(aa - bb == res && a < rA) ||
					(aa - bb == res && a == rA && b < rB)) {
					res = aa - bb;
					rA = a;
					rB = b;
				}
			}
		}
		
		if (A[i] == '?' && B[i] == '?') A[i] = B[i] = '0';
		else if (A[i] == '?') A[i] = B[i];
		else if (B[i] == '?') B[i] = A[i];
		else if (A[i] != B[i]) break;

		if (i == len - 1) {
			a = A;
			b = B;
			long long aa = atoll(a);
			long long bb = atoll(b);
			if (aa >= bb) {
				if ((aa - bb < res) || 
					(aa - bb == res && a < rA) ||
					(aa - bb == res && a == rA && b < rB)) {
					res = aa - bb;
					rA = a;
					rB = b;
				}
			};
		}
	}

	return res;
}


long long solveB(string A, string B, string& rA, string& rB) {
	int len = A.length();

	long long res = LLONG_MAX;
	for (int i = 0; i < len; i++) {
		string a = A;
		string b = B;
		bool can = false;
		if (a[i] == '?' && b[i] == '?') {
			a[i] = '1';
			b[i] = '0';
			can = true;
		} else if(a[i] == '?') {
			if (b[i] != '9') {
				a[i] = b[i] + 1;
				can = true;
			}
		} else if(b[i] == '?') {
			if (a[i] != '0') {
				b[i] = a[i] - 1;
				can = true;
			}
		} else {
			if (a[i] > b[i]) can = true;
		}

		if (can) {
			for (int j = i + 1; j < len; j++) {
				if (a[j] == '?') a[j] = '0';
				if (b[j] == '?') b[j] = '9';
			}
			long long aa = atoll(a);
			long long bb = atoll(b);
			if (aa >= bb) {
				if ((aa - bb < res) || 
					(aa - bb == res && b < rB) ||
					(aa - bb == res && b == rB && a < rA)) {
					res = aa - bb;
					rA = a;
					rB = b;
				}
			}
		}
		
		if (A[i] == '?' && B[i] == '?') A[i] = B[i] = '0';
		else if (A[i] == '?') A[i] = B[i];
		else if (B[i] == '?') B[i] = A[i];
		else if (A[i] != B[i]) break;

		if (i == len - 1) {
			a = A;
			b = B;
			long long aa = atoll(a);
			long long bb = atoll(b);
			if (aa >= bb) {
				if ((aa - bb < res) || 
					(aa - bb == res && b < rB) ||
					(aa - bb == res && b == rB && a < rA)) {
					res = aa - bb;
					rA = a;
					rB = b;
				}
			};
		}
	}

	return res;
}

int main(void) {
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small.out.txt", "w", stdout);

	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%s %s", C, J);
		string rc1, rj1;
		string rc2, rj2;
		long long r1 = solveA(C, J, rc1, rj1);
		long long r2 = solveB(J, C, rj2, rc2);
		
		string a, b;
		if ((r1 < r2) ||
			(r1 == r2 && rc1 < rc2) ||
			(r1 == r2 && rc1 == rc2 && rj1 < rj2)) {
			a = rc1;
			b = rj1;
		} else {
			a = rc2;
			b = rj2;
		}
		printf("Case #%d: %s %s\n", tc, a.c_str(), b.c_str());
	}
	return 0;
}