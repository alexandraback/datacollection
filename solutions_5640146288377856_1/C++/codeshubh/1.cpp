#include<bits/stdc++.h>

int main()
{
	int t,i,j,k,n,p,u,T,m,r,c,w;
	int a[1000000];
	char g[1000000],e;
	scanf("%d",&t);
	for(T=1;T<=t;++T)
	{
		scanf("%d%d%d",&r,&c,&w);
		int rej=c/w;
		int rem=c-((rej-1)*w);
		int yy;
		if(rem==w)
			yy=w;
		else
			yy=w+1;
		k=(rej)*(r-1);
		u=rej-1+yy+k;
		printf("Case #%d: %d\n",T,u);
	}
	return 0;
}
