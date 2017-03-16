#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;

int T,B;
LL M;
int a[100][100];

int main() {
	freopen("2A.in","r",stdin);
	freopen("2A.out","w",stdout);
	scanf("%d",&T);
	for (int kase = 1;kase <= T; kase++) {
		scanf("%d%lld",&B,&M);
		memset(a,0,sizeof a);
		//cout<<(1ll << (B-2))<<endl;
		if (M > (1ll << (B-2))) {
			printf("Case #%d: IMPOSSIBLE\n",kase);
		} else {
			for (int i = 1;i <= B-1; i++) {
				for (int j = i+1;j <= B-1; j++) {
					a[i][j] = 1;
				}
			}
			if (M == (1ll << (B-2))) {
				for (int i = 1;i <= B-1; i++)
						a[i][B] = 1;
			} else {
				for (int i = 2;i <= B-1; i++) {
					if (1&(M>>(i-2))) 
						a[i][B] = 1;
				}
			}
			printf("Case #%d: POSSIBLE\n",kase);
			for (int i = 1;i <= B; i++) {
				for (int j = 1;j <= B; j++)
					printf("%d",a[i][j]);
				printf("\n");
			}
		}
	}
	return 0;
}