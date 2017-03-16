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

const int MAXN = 1000 * 1000 + 10;

bool mark[11];

int main () {
	ios::sync_with_stdio(false);

	int tc; cin >> tc;
	for (int oo = 0; oo < tc; oo ++) {
		CLR(mark, 0);
		
		cout << "Case #" << oo + 1 << ": ";

		ll n; cin >> n;
		bool asleep = false;
		for (int i = 1; i < MAXN; i ++) {
			ll cur = n * i;
			while (cur) {
				mark[cur % 10] = 1;
				cur /= 10;
			}

			int cnt = 0;
			for (int j = 0; j < 10; j ++)
				cnt += !mark[j];
			if (!cnt) {
				cout << n * i << endl;
				asleep = true;
				break;
			}
		}

		if (!asleep) cout << "INSOMNIA" << endl;
	}
	return 0;
}

