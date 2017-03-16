#include<iostream>
#include<cstdio>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<cassert>
using namespace std;
using ll = long long;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		ll n;
		scanf("%lld", &n);
		printf("Case #%d: ", i);
		if (!n)
			printf("INSOMNIA");
		else {
			vector<bool> have(10, false);
			int cnthave = 0;
			ll x = 0;
			do {
				ll y = (x += n);
				do if (!have[y%10])
						cnthave += (have[y%10] = true);
				while (y /= 10);
			} while (cnthave != 10);
			printf("%lld", x);
		}
		printf("\n");
	}

#ifdef LOCAL
	cerr << "time : " << (double)clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}