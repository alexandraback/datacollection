#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

int t;
int a, b, k;
map <ii, ll> ways;

ll getWays(int id, int a, int b)
{
	if (id < 0) return 1;
	if (a > b) swap(a, b);
	ii key = ii(a, b);
	int ta = (a & 1 << id)? a % (1 << id): 0;
	int ba = (a & 1 << id)? (1 << id) - 1: a;
	int tb = (b & 1 << id)? b % (1 << id): 0;
	int bb = (b & 1 << id)? (1 << id) - 1: b;
	if (!ways.count(key)) {
		ll res = 0;
		if (k & 1 << id)
			if ((a & 1 << id) && (b & 1 << id))
				res += getWays(id - 1, ta, tb) + 
					   ll(ta + 1) * ll(bb + 1) + ll(ba + 1) * ll(tb + 1) + ll(ba + 1) * ll(bb + 1);
			else res += ll(a + 1) * ll(b + 1);
		else if ((a & 1 << id) && (b & 1 << id))
				res += getWays(id - 1, ta, bb) + getWays(id - 1, ba, tb) + getWays(id - 1, ba, bb);
			else {
				if (a & 1 << id) res += getWays(id - 1, ta, bb);
				if (b & 1 << id) res += getWays(id - 1, ba, tb);
				res += getWays(id - 1, ba, bb);
			}
		ways[key] = res;
	}
	return ways[key];
}

int main()
{
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d %d %d", &a, &b, &k); a--; b--; k--;
		ways.clear();
		printf("Case #%d: %lld\n", tc, getWays(30, a, b));
	}
	return 0;
}