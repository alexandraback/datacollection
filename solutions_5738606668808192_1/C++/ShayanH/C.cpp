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

const int MAXN = 100;

string dec_to_bin(ll n) {
	string res;
	while (n) {
		res.pb(n % 2 + '0');
		n /= 2;
	}
	reverse(ALL(res));
	return res;
}

bool is_prime(int n) {
	for (int i = 2; SQR(i) <= n; i ++)
		if (n % i == 0)
			return false;
	return true;
}

vector<int> primes;

int find_div(string coin, int base) {
	for (int p = 0; p < SZ(primes); p++) {
		int prime = primes[p], pw = 1, res = 0;
		
		for (int i = SZ(coin) - 1; i >= 0; i --) {
			res = (res + pw * (coin[i] - '0')) % prime;
			pw = (pw * base) % prime;
		}
		if (res == 0)
			return prime;
	}
	return -1;
}

int main () {
	ios::sync_with_stdio(false);

	for (int i = 2; i < MAXN; i ++)
		if (is_prime(i))
			primes.pb(i);

	int n, j; cin >> n >> n >> j;
	cout << "Case #1: \n";

	for (int mask = 0; mask < (1 << (n - 2)); mask ++) {
		ll coin = (mask + (1LL << (n - 2))) * 2 + 1;
		string jamcoin = dec_to_bin(coin);

		vector<int> ans;
		for (int base = 2; base < 11; base ++) {
			int dv = find_div(jamcoin, base);
			if (dv == -1) break;
			ans.pb(dv);
		}
		if (SZ(ans) == 9) {
			cout << jamcoin << " ";
			FOREACH(i, ans) cout << *i << ' ';
			cout << endl;
			j --;
		}
		if (j == 0) break;
	}
	return 0;
}

