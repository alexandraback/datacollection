#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int bitat(long long x, int pos) {
	return (x >> pos) & 1;
}
long long A, B, K;
long long memo[32][2][2][2];
long long dp(int i, int a, int b, int k) {
	if (i >= 32) {
		return a && b && k;
	}
	long long &ret = memo[i][a][b][k];
	if (ret >= 0) return ret;
	ret = 0;
	for (int x = 0; x < 2; ++x) {
		for (int y = 0; y < 2; ++y) {
			for (int aa = 0; aa < 2; ++aa) {
				for (int bb = 0; bb < 2; ++bb) {
					for (int kk = 0; kk < 2; ++kk) {
						int tmpa, tmpb, tmpk;
						if (aa) {
							int xx = bitat(A, i);
							tmpa = x < xx ? 0 : x > xx ? -1 : 1;
						}
						else tmpa = 0;
						if (bb) {
							int yy = bitat(B, i);
							tmpb = y < yy ? 0 : y > yy ? -1 : 1;
						}
						else tmpb = 0;
						if (kk){
							int z = x & y;
							int zz = bitat(K, i);
							tmpk = z < zz ? 0 : z > zz ? -1 : 1;
						}
						else tmpk = 0;
						if (tmpa == a && tmpb == b && tmpk == k) {
							ret += dp(i + 1, aa, bb, kk);
						}
					}
				}
			}
		}
	}
	return ret;
}
int main(){
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas) {
		printf("Case #%d:", cas);
		scanf("%lld %lld %lld", &A, &B, &K);
		--A, --B, --K;
		memset(memo, -1, sizeof(memo));
		long long ans = 0;
		for (int x = 0; x < 2; ++x) {
			for (int y = 0; y < 2; ++y) {
				for (int z = 0; z < 2; ++z) {
					ans += dp(0, x, y, z);
				}
			}
		}
		printf(" %lld\n", ans);
	}
	return 0;
}
