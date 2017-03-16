#include<bits/stdc++.h>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)

int cnt[2555];
int n;
int main() {
	int T; cin >> T;
	For(TK,1,T) {
		printf("Case #%d:", TK);
		cin >> n;
		memset(cnt,0,sizeof cnt);
		For(i,1,n + n - 1) {
			For(j,1,n) {
				int t;
				scanf("%d", &t);
				cnt[t] ^= 1;
			}
		}
		For(i,1,2500) if (cnt[i]) {
			printf(" %d", i);
		}
		puts("");
	}
	return 0;
}
