#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int itc;

template<typename T>
T powi(T a, unsigned int b) {
	T c = 1;
	while (b != 0) {
		if (b&1) c = c*a;
		a = a*a;
		b >>= 1;
	}
	return c;
}

void solve() {
	int n, m;
	cin >> n >> m;
	int bl = 2;
	int bu = 11;
	vector<long long> a(bu);
	for (int b = bl; b < bu; b++) {
		a[b] = powi((long long)b, (n+1)/2)+1;
	}
	string s0(n%2, '0');
	string s(n/2-2, '0');
	for (int k = 0; k < m; k++) {
		auto s1 = "1"+s+"1";
		reverse(s1.begin(), s1.end());
		printf((s1+s0+s1).c_str());
		for (int b = bl; b < bu; b++) {
			printf(" %lld", a[b]);
		}
		puts("");
		auto i = s.find('0');
		if (i == string::npos) break;
		fill(s.begin(), s.begin()+i, '0');
		s[i] = '1';
	}
}

int main() {
	cin.sync_with_stdio(false);
	int ntc;
	cin >> ntc;
	for (itc = 1; itc <= ntc; itc++) {
		printf("Case #%d:\n", itc);
		solve();
	}
}
