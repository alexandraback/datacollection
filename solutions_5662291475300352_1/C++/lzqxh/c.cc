//By Lin
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>
#include <queue>

#define X first
#define Y second
#define mp make_pair
#define sqr(x) ((x) * (x))
#define Rep(i, n) for(int i = 0; i<(n); i++)
#define foreach(it, n) for(__typeof(n.begin()) it = n.begin(); it != n.end(); it++)

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

#define esp 1e-8
#define N 100010
#define MOD 1000000007

pii data[10];
int n;

int cal(int i, int j) {
	if (data[i].Y >= data[j].Y) return 0;
	int dis = data[j].X - data[i].X;
	LL a = (360 - data[j].X) * 1ll * (data[j].Y - data[i].Y) - dis * 1ll * data[i].Y;
	LL b = data[i].Y;
	int t = a / 360;
	for (int t = 1; t <= 11; t++)
		if (t * b < a) return t - 1;
	return 10;
}

bool test(int msk, int i) {
	return msk & (1<<i);
}
int cal(int msk) {
	int ret = 0;
	Rep(i, n) {
		if (!test(msk, i)) ret ++;
	}
	Rep(j, n) {
		int cur = 0;
		Rep(i, n) 
			if (test(msk, i))
				cur = max(cur, cal(j, i));
		ret += cur;
	}
	return ret;
}

int main() {
	int cas, tt = 0;
	scanf("%d", &cas);
	while (cas--) {
		int m;
		scanf("%d", &m);
		n = 0;
		while (m--) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			Rep(k, y) data[n++] = mp(x, z + k);
		}
		int ans = n;
		Rep(msk, 1<<n) {
			ans = min(ans, cal(msk));
		}
		printf("Case #%d: %d\n", ++tt, ans);
	}
	return 0;
}
