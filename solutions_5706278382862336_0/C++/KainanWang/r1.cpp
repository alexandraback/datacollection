#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int testCase;
	cin >> testCase;
	int caseNumber = 0;
	while (testCase--) {
		long long n, p, q;
		char c;
		cin >> p;
		getchar();
		cin >> q;
		long long g = gcd(p, q);
		p /= g;
		q /= g;

	//	cout << "ds" << p << endl;
		int res = 0;
		while (p < q) {
			p *= 2;
			++res;
		}
		bool ok = true;
		while (q > 1) {
			if (q % 2 != 0) ok = false;
			q /= 2;
		}
		if (!ok) printf("Case #%d: impossible\n", ++caseNumber);
		else printf("Case #%d: %d\n", ++caseNumber, res);
	}
} 
