#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
#include <string>

using namespace std;

typedef long long ll;
const ll TOP = 100000000000000;

ll bag[1024];

bool check(ll value) {
	static char at[100];
	int cnt = 0;
	while (value) {
		at[cnt++] = value % 10;
		value /= 10;
	}
	for (int i = 0; i + i < cnt; i++)
		if (at[i] != at[cnt - i - 1])
			return false;
	return true;
}

int main() {
	freopen("/home/family/Desktop/C-large-1.in", "r", stdin);
	freopen("/home/family/Desktop/C-large-1.out", "w", stdout);
	ll ii, cnt = 0, L, R;
	for (ll i = 1; (ii = i * i) <= TOP; i++)
		if (check(i) && check(ii))
			bag[cnt++] = ii;
	int T, Cas = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%lld%lld", &L, &R);
		ll *p = lower_bound(bag, bag + cnt, L);
		ll *q = lower_bound(bag, bag + cnt, R + 1);
		printf("Case #%d: %d\n", ++Cas, q - p);
	}
	return 0;
}
