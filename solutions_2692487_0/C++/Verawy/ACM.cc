#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

#define INF 10000000

int v[1000],f[111][111];


int calc(int A,int &B,int x){
	if (A==1) return 10000;
	int res=0;
	B=A;
	while (B<=x){
		B=B*2-1; res++;
	}
	return res;
}

int main(){
	int T,A,n;
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++){
		scanf("%d%d",&A,&n);
		for (int i=1;i<=n;i++)
			scanf("%d",&v[i]);
		sort(v+1,v+1+n);
		int ans=0;
		memset(f,-1,sizeof(f));
		f[0][0]=A;
		for (int i=1;i<=n;i++)
			f[0][i]=min(f[0][i-1]*2-1,INF);
		for (int i=1;i<=n;i++)
			for (int j=0;j<=n;j++){
				if (f[i-1][j]>v[i])
					f[i][j]=min(f[i-1][j]+v[i],INF);
				else
					if (j) f[i][j]=f[i-1][j-1];
				if (j) f[i][j]=max(f[i][j-1]*2-1,f[i][j]);
				f[i][j]=min(f[i][j],INF);
			}
		for (int i=0;i<=n;i++)
			if (f[n][i]!=-1) {
				ans=i; break;
			}
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}
