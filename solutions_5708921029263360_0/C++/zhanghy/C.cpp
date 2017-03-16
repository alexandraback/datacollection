#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int T;
int J,P,S,K;
int d[10000][3];
int a[3][20][20];

int main() {
	freopen("3.in","r",stdin);
	freopen("3.out","w",stdout);
	scanf("%d",&T);
	for (int kase = 1;kase <= T; kase++) {
		memset(a,0,sizeof a);
		int tot = 0;
		scanf("%d%d%d%d",&J,&P,&S,&K);
		for (int i = 1;i <= J; i++) {
			for (int j = 1;j <= P; j++)
				for (int k = 1;k <= S; k++) {
					if (a[0][i][j] < K && a[1][i][k] < K && a[2][j][k] < K) {
						tot++; d[tot][0] = i; d[tot][1] = j; d[tot][2] = k;
						a[0][i][j] ++; a[1][i][k] ++;  a[2][j][k] ++;
					}
				} 
		}	
		printf("Case #%d: %d\n",kase,tot);
		for (int i = 1;i <= tot; i++) {
			printf("%d %d %d\n",d[i][0],d[i][1],d[i][2]);
		}
	}
	return 0;
}