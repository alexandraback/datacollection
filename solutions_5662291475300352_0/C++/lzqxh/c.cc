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

bool check(int i, int j) {
	if (data[i].Y >= data[j].Y) return true;
//	printf("%d %d\n", i, j);
	int dis = data[j].X + 360 - data[i].X;
//	if (data[i].X < data[j].X) dis += 360;
//	printf("%d\n", dis);
//	int v =  1/data[i].Y - 1/data[j].Y;
//   v = (data[j].Y - data[i].Y)/(data[i].Y * data[j].Y)
//  t = dis / v 
//  t = dis * data[i].Y * data[j].Y / (data[j].Y - data[i].Y)
//  t * 1 / data[j].Y < 360 - data[j].X
//  dis * data[i].Y / (data[j].Y - data[i].Y) < 360 - data[j].X
// dis * data[i].Y < (360 - data[j].X) * (data[j].Y - data[i].Y)
	
//	printf("%d %d\n",dis * data[i].Y , (360 - data[j].X) * (data[j].Y - data[i].Y) );
	return dis * 1ll * data[i].Y > (360 - data[j].X) * 1ll * (data[j].Y - data[i].Y);
}

bool check(int msk) {
	Rep(i, n) Rep(j, n) {
		if ((msk & (1<<i)) == 0) continue;
		if ((msk & (1<<j)) == 0) continue;
		if (!check(i, j)) return false;
	}
	return true;
}

int cal(int msk) {
	int ret = 0;
	for (; msk; msk /= 2) ret += msk & 1;
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
//		printf("%d\n", check(3));
//		return 0;
		int ans = n;
		Rep(msk, 1<<n) {
			if (check(msk)) ans = min(ans, n - cal(msk));
		}
		printf("Case #%d: %d\n", ++tt, ans);
	}
	return 0;
}
