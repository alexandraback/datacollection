//============================================================================
// Name        : A.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

const int inf = 1 << 29;
#define mod 1000000007
#define N 100010

ll dp[35][2][2][2];
int a[35],b[35],c[35];
int main() {
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int T, n, m,k,ri=1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n,&m,&k);
		for(int i=0;i<31;i++){
			a[i]=(n>>(30-i))&1;
			b[i]=(m>>(30-i))&1;
			c[i]=(k>>(30-i))&1;
		}
		memset(dp,0,sizeof(dp));
		dp[0][0][0][0]=1;
		int nn,mm;
		for(int i=0;i<31;i++){
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++){
					for(int p=0;p<2;p++){
							for(int kk=0;kk<2;kk++)
								for(int pp=0;pp<2;pp++){
									if(k==0&&kk>a[i]) continue;
									if(p==0&&pp>b[i]) continue;
									if(kk<a[i]) nn=1;
									else nn=0;
									if(pp<b[i]) mm=1;
									else mm=0;
									nn|=k;mm|=p;
									if((kk&pp)>c[i]){
										if(j) dp[i+1][j][nn][mm]+=dp[i][j][k][p];
									}else if((kk&pp)==c[i]){
										dp[i+1][j][nn][mm]+=dp[i][j][k][p];
									}else dp[i+1][1][nn][mm]+=dp[i][j][k][p];
								}
					}
				}
		}
		printf("Case #%d: ",ri++);
		 printf("%I64d\n",dp[31][1][1][1]);
	}
	return 0;
}
