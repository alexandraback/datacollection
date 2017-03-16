#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int T;
int N;
int cnt[3000];

int main() {
	freopen("2b.in","r",stdin);
	freopen("2b.out","w",stdout);
	scanf("%d",&T);
	for (int kase = 1;kase <= T; kase++) {
		scanf("%d",&N);
		memset(cnt,0,sizeof cnt);
		for (int i = 1;i <= 2*N-1; i++) {
			for (int j = 1;j <= N; j++) {
				int k; scanf("%d",&k);
				cnt[k]++;
			}
		}
		printf("Case #%d:",kase);
		for (int i = 1;i <= 2500; i++) {
			if (cnt[i] % 2 == 1) printf(" %d",i);
		}
		printf("\n");
	}
	return 0;
}