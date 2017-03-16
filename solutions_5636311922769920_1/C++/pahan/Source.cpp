#include<iostream>
#include<cstdio>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<cassert>
using namespace std;
using ll = long long;

ll gen(ll k, ll a, ll b) {
	ll res = 0;
	for (ll t = a; t < b; t++)
		res = res * k + t;
	return res;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	srand(time(NULL));

	int t;
	cin >> t;
	for (int tcase = 1; tcase <= t; tcase++) {
		ll k, c, s;
		cin >> k >> c >> s;
		cout << "Case #" << tcase << ":";
		if ((k+c-1)/c > s)
			cout << " IMPOSSIBLE";
		else {
			for (int i = 0; i < (k+c-1)/c; i++)
				cout << ' ' << gen(k, i*c, min((i+1)*c, k))+1;
		}
		cout << endl;
	}

#ifdef LOCAL
	cerr << "time : " << (double)clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}