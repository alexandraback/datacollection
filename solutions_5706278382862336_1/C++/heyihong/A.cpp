#include<iostream>
#include<cstdio>

using namespace std;

int ca;
string s;

long long gcd(long long a, long long b) {
	return b ? gcd(b, a % b) : a;
}

int calc(long long p, long long q) {
	long long x = q;
	for (; x % 2 == 0; x /= 2);
	if (x != 1) return 41;
	int ret = 1;
	for (; p * 2 < q; p *= 2, ++ret);
	return ret;
}

int main() {
	freopen("in.txt", "r", stdin);
	cin >> ca;
	for (int C = 1; C <= ca; ++C) {
		cin >> s;
		bool deno = false;
		long long p = 0, q = 0;
		for (int i = 0; i != s.size(); ++i)
			if (s[i] == '/') deno = true;
			else if (deno) q = q * 10 + s[i] - '0';
			else p = p * 10 + s[i] - '0';
		long long g = gcd(p, q);
		p /= g; q /= g;
		int ans = calc(p, q);
		if (ans > 40) cout << "Case #" << C << ": impossible" << endl;
		else cout << "Case #" << C << ": " << ans << endl;
	}
	return 0;
}