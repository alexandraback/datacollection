#include <bits/stdc++.h>
using namespace std;

int c[2505];

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("0.out","w",stdout);
	int T,_,i,j,x,n,m;
	for(scanf("%d",&T),_=1;_<=T;_++)
	{
		memset(c,0,sizeof(c));
		for(scanf("%d",&n),m=2*n-1,i=0;i<m;i++)
			for(j=0;j<n;j++)
				scanf("%d",&x),c[x]++;
		printf("Case #%d:",_);
		for(i=1;i<=2500;i++)
			if(c[i]&1)
				printf(" %d",i);
		puts("");
	}
	return 0;
}
