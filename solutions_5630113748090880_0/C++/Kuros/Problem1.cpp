#include <bits/stdc++.h>

using namespace std;

int T;

int num[2600];

int main() {
	freopen("B-small-attempt0.in","r",stdin);
	freopen("ans.txt","w",stdout);

	scanf("%d", &T);
	int cas = 1;
	while(T--) {
		int n;
		scanf("%d", &n);

		memset(num,0,sizeof(num));
		for(int i = 1; i < 2 * n; i++) {
			for(int j = 1; j <= n; j++) {
				int a;
				scanf("%d", &a);
				num[a]++;
			}
		}
		printf("Case #%d:", cas++);
		for(int i = 1; i <= 2500; i++) {
			if(num[i] & 1) {
				printf(" %d", i);
			}
		}
		printf("\n");
	}
}