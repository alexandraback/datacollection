#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int tqn,tqi,A,n,a[111],i,j,k,F[111][111][111],ret;

int main (int argc, char * const argv[]) {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&tqn);
	for(tqi=1;tqi<=tqn;tqi++){
		scanf("%d%d",&A,&n);
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(i=0;i<=100;i++)for(j=0;j<=100;j++)for(k=0;k<=100;k++)F[i][j][k]=-1000000000;
		F[0][0][0]=A;
		for(i=0;i<n;i++)for(j=0;j<=100;j++)for(k=0;k<=100;k++)if(F[i][j][k]!=-1000000000){
			if(F[i][j][k]>a[i+1])F[i+1][j][k]=max(F[i+1][j][k],F[i][j][k]+a[i+1]);
			F[i+1][j][k+1]=max(F[i+1][j][k+1],F[i][j][k]);
			if(F[i][j][k]<=2000001)F[i][j+1][k]=max(F[i][j+1][k],F[i][j][k]*2-1);
		}
		ret=1000000000;
		for(i=0;i<=100;i++)for(j=0;j<=100;j++)if(F[n][i][j]!=-1000000000)ret=min(ret,i+j);
		printf("Case #%d: %d\n",tqi,ret);
	}
    return 0;
}
