#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<(n);i++)
#define MOD 1000000007
#define PB push_back
typedef long long ll;

int T, N, po[10];
string a, b;
tuple<int, int, int> ans;

int d (int v, int p) {
	return (v / po[N - p - 1]) % 10;
}

int main () {
	fo(i, 10) po[i] = i ? po[i-1] * 10 : 1;
	cin >> T;
	for (int _ = 1; _ <= T; _++) {
		ans = make_tuple(MOD, MOD, MOD);
		cin >> a >> b; N = (int) a.size();
		int mx = 0;
		if (N == 1) mx = 10;
		else mx = (N == 2 ? 100 : 1000);
		fo(i, mx) fo(j, mx) {
			bool bad = 0;
			fo(x, N) if (a[x] != '?' && a[x]-'0' != d(i, x)) bad = 1;
			fo(x, N) if (b[x] != '?' && b[x]-'0' != d(j, x)) bad = 1;
			if (!bad) {
				ans = min(ans, make_tuple(abs(j-i), i, j));
			}
		}
		fo(x, N) a[x] = (char) '0' + d(get<1>(ans), x);
		fo(x, N) b[x] = (char) '0' + d(get<2>(ans), x);
		printf("Case #%d: ", _);
		cout << a << " " << b << '\n';
	}
	return 0;
}
