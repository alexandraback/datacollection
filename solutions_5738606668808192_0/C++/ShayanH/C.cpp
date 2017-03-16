#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define CLR(x, a) memset(x, a, sizeof x)
#define VAL(x) #x << " = " << (x) << "   "
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define FOR(i, n) for (int i = 0; i < (n); i ++)
#define X first
#define Y second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int MAXN = 1 * 1000 + 10;

string dec_to_bin(ll n) {
	string res;
	while (n) {
		res.pb(n % 2 + '0');
		n /= 2;
	}
	reverse(ALL(res));
	return res;
}

ll convert(int c, int base) {
	string coin = dec_to_bin(c);
	ll res = 0, p = 1;	
	for (int i = SZ(coin) - 1; i >= 0; i --, p *= base)
		res += p * (coin[i] - '0');
	return res;
}

map<ll, int> dv;

bool is_prime(ll n) {
	if (dv.count(n))
		return (dv[n] == 1);
	dv[n] = 1;
	for (ll i = 2; SQR(i) <= n; i ++)
		if (n % i == 0) {
			dv[n] = i;
			return false;
		}
	return true;
}

int main () {
	ios::sync_with_stdio(false);
	
	int n, j; cin >> n >> n >> j;
	cout << "Case #1: \n";

	for (int mask = 0; mask < (1 << (n - 2)); mask ++) {
		ll coin = (mask + (1LL << (n - 2))) * 2 + 1;

		bool check = true;
		for (int base = 2; base < 11; base ++) {
			ll cur = convert(coin, base);
			if (is_prime(cur))
				check = false;
		}
		if (check) {
			cout << dec_to_bin(coin) << " ";
			for (int base = 2; base < 11; base ++) {
				ll cur = convert(coin, base);
				cout << dv[cur] << ' ';
			}
			cout << endl;
			j --;
		}

		if (j == 0) break;
	}
	return 0;
}

