#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
#include <climits>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef map<int, int> mii;

int T;
ll N;
const ll MAX_N = 100000000;
map<ll, ll> dp;

ll reverseInt(ll num)
{
	char buf[32];
	if (num % 10 == 0) {
		return MAX_N + 1;
	}
	sprintf(buf, "%lld", num);
	int len = strlen(buf);
	int imax = len / 2;
	for (int i = 0; i < imax; ++i) {
		swap(buf[i], buf[len-1-i]);
	}
	ll ret = atoll(buf);
	return ret;
}

ll lowerN(ll num) {
	char buf[32];
	sprintf(buf, "%lld", num);
	int len = strlen(buf) - 1;
	memset(buf, 0, sizeof(buf));
	int cnt = len / 2;
	if (len % 2) {
		++cnt;
	}
	for (int i = 0; i < len/2; ++i) {
		buf[i] = '9';
	}
	buf[len - 1] = '1';
	for (int i = len/2; i < len-1; ++i) {
		buf[i] = '0';
	}
	ll tmp = atoll(buf);
	return tmp;
}

void createTable()
{
	dp[1] = 1;
	dp[10] = 10;
	char buf[32], ld[32];
	for (int digits = 2; digits <= 13; ++digits) {
		memset(buf, 0, sizeof(buf));
		int ud = digits / 2;
		int start = 1;
		for (int k = 0; k < ud-1; ++k) {
			start *= 10;
		}
		int end = start * 10;
		for (int idx = 0; idx <= digits - 1 - ud; ++idx) {
			if (idx == digits - 1 - ud) {
				ld[idx] = '1';
			} else {
				ld[idx] = '0';
			}
		}
		for (int upper = start+1; upper < end; ++upper) {
			sprintf(buf, "%d%s", upper, ld);
			ll num = atoll(buf);
			ll rev = reverseInt(num);
			ll low = lowerN(rev);
			// printf("%lld %lld %lld\n", num, rev, low);
			dp[num] = dp[low] + 1 + (rev - low);
			//printf("%lld %lld %lld %lld\n", num, dp[num], low, rev);
		}
	}
}

void solve()
{
	if (dp.find(N) != dp.end()) {
		ll ret = dp[N];
		printf("%lld", ret);
		return;
	}
	//ll low = lowerN(N);
	map<ll, ll>::iterator it = dp.begin();
	ll low = 1;
	while (it != dp.end() && it->first < N) {
		low = it->first;
		++it;
	}
	ll ret = dp[low] + (N - low);
	printf("%lld", ret);
}

int main()
{
	createTable();
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%lld", &N);
		printf("Case #%d: ", t);
		solve();
		printf("\n");
	}
	return 0;
}
