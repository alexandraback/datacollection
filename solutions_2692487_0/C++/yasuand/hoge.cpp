#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define rep(i, from, to) for(int i = (from); i < (to); ++i)

vector<long long> mote;
vector<long long> cnt;
long long a;

long long cache[101][101];

int solve(int lower, int upper)
{
	if (cache[lower][upper] >= 0) {
		return cache[lower][upper];
	} else if (lower >= upper) {
		return 0;
	} else {
		int res1 = solve(lower + 1, upper) + cnt[lower];
		int res2 = solve(lower, upper - 1) + 1;
		return min(res1, res2);
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	rep(i, 1, t + 1) {
		long long n;
		scanf("%lld%lld", &a, &n);
		mote.clear();
		mote.resize(n);
		rep(j, 0, n) {
			scanf("%lld", &mote[j]);
		}
		if (a == 1) {
			printf("Case #%d: %d\n", i, n);
			continue;
		}
		sort(mote.begin(), mote.end());
		memset(cache, -1, sizeof(cache));
		cnt.clear();
		cnt.resize(n);
		long long aa = a;
		rep(j, 0, n) {
			int count = 0;
			while (aa <= mote[j]) {
				aa = 2 * aa - 1;
				++count;
			}
			aa += mote[j];
			cnt[j] = count;
		}
		printf("Case #%d: %d\n", i, solve(0, n));
	}
	return 0;
}