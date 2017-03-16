#include<cstdio>
#include<algorithm>
using namespace std;
int main () {
	int t,T,a,n,i,j,k;
	int num[100];
	int dp[100][101];
	scanf("%d",&T);
	for(t=0;t<T;t++) {
		for(i=0;i<100;i++) for(j=0;j<=100;j++) dp[i][j]=-1;
		scanf("%d%d",&a,&n);
		for(i=0;i<n;i++) scanf("%d",&num[i]);
		sort(num,num+n);
		if(a>num[0]) dp[0][0]=a+num[0];
		else {
			dp[0][1]=a;
			k=0;
			if(a!=1) {
				while(a<=num[0]) {
					a+=a-1;
					k++;
				}
				if(dp[0][k]<a+num[0])
					dp[0][k]=a+num[0];
			}
		}
		for(i=1;i<n;i++) {
			for(j=0;j<=100;j++) {
				if(dp[i-1][j]!=-1) {
					if(dp[i-1][j]>num[i]) {
						if(dp[i][j]<num[i]+dp[i-1][j])
							dp[i][j]=num[i]+dp[i-1][j];
					} else {
						if(dp[i][j+1]<dp[i-1][j])
							dp[i][j+1]=dp[i-1][j];
						a=dp[i-1][j];
						if(a==1) continue;
						k=0;
						while(a<=num[i]) {
							a+=a-1;
							k++;
						}
						if(dp[i][j+k]<a+num[i])
							dp[i][j+k]=a+num[i];
					}
				}
			}
		}
		for(i=0;i<=100;i++) 
			if(dp[n-1][i]!=-1) 
				{printf("Case #%d: %d\n",t+1,i);break;}
	}
	return 0;
}