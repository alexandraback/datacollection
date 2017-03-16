#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int num = 0;
long long ans[MAXN];
long long Pow(long long x, int n) {
	long long ret = 0;
	for(int i = 0; i < n; i ++) {
		ret *= x;
	}
	return ret;
}
int main() {
	freopen("D-large.in","r",stdin);
	freopen("D-large.out","w",stdout);
	int T; cin>>T;
	for(int cs = 1, K, C, S; cs <= T; cs ++) {
		cerr << "Processing Case #" << cs << "...\n";
		cin >> K >> C >> S;
		printf("Case #%d:", cs);
		if(C == 1) {
			if(K != S) {
				puts(" IMPOSSIBLE");
			} else {
				for(int i = 1; i <= K; i ++) {
					printf(" %d", i);
				}
				puts("");
			}
			continue;
		}
		if(S * 2 >= K) {
			long long cnt = 0, pos = 2;
			int num = 0;
			long long ret = Pow(K, cnt);
			for(; num < S; cnt += 2, pos += 2) {
				if(pos > K) {
					pos = K;
				}
				if(cnt * K + pos > K * K) break;
				assert(cnt * K + pos <= K * K);
				ans[num ++] = cnt * K + pos;
			}
			for(int i = 0; i < num; i ++) {
				printf(" %d", ans[i]);
			}
			puts("");
		} else {
			puts(" IMPOSSIBLE");
		}
	}
	return 0;
}

