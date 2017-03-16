#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <cstdlib>
#include <queue>
#include <set>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <bitset>
#include <sstream>

using namespace std;

long long gcd(long long a, long long b) {
	return b ? gcd(b, a % b) : a;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		long long p = 0, q = 0;
		string s;
		cin >> s;
		int pos = 0;
		while (s[pos] != '/') {
			p = p * 10 + s[pos] - '0';
			++pos;
		}
		++pos;
		while (pos < s.length()) {
			q = q * 10 + s[pos] - '0';
			++pos;
		}
		long long d = gcd(p, q);
		p /= d;
		q /= d;
		int pow = 0;
		long long l = q;
		while (!(l % 2)) {
			l >>= 1;
			++pow;
		}
		cout << "Case #" << i + 1 << ": ";
		if (l != 1)
			cout << "impossible";
		else {
			int k = 1;
			while (k <= 40 && (long double)(p + 0.0) / q < (long double)1.0 / (1ll << k))
				++k;
			if (k > 40)
				cout << "impossible";
			else
				cout << k;
		}
		cout << endl;
	}
	return 0;
}