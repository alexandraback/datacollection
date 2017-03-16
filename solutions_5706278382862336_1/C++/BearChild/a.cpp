#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll t[50];

inline ll gcd (ll a, ll b) {
	return b == 0 ? a : gcd(b, a%b);
}

inline bool judge (ll a) {
	for (int i = 0; i <= 40; i++)
		if (a == t[i])
			return true;
	return false;
}

ll solve (ll a, ll b) {

	if (!judge(b))
		return -1;

	int cnt = 0;
	while (a < b) {
		a *= 2;
		cnt++;
	}
	return cnt;
}

int main () {
	int cas;
	cin >> cas;

	t[0] = 1;
	for (int i = 1; i <= 40; i++)
		t[i] = t[i-1] * 2;

	for (int i = 1; i <= cas; i++) {
		ll a, b;
		char ch;
		cin >> a >> ch >> b;
		ll d = gcd(a, b);
		ll ans = solve(a/d, b/d);

		cout << "Case #" << i << ": ";
		if (ans != -1)
			cout << ans << endl;
		else 
			cout << "impossible" << endl;
	}
	return 0;
}
