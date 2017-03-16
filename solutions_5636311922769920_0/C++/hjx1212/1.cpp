#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("0.out","w",stdout);
	int _,T,k,c,s,sn,i,x;
	long long p,ans[105];
	bool f;
	for(scanf("%d",&T),_=1;_<=T;_++)
	{
		scanf("%d%d%d",&k,&c,&s);
		printf("Case #%d:",_);
		for(i=1,f=sn=0;sn<s;sn++)
		{
			for(p=1,x=0;x<c;x++)
			{
				p=(p-1)*k+i;
				if(++i>k)
					i=k,f=1;
			}
			ans[sn]=p;
			if(f)
				break;
		}
		if(sn>=s)
			printf(" IMPOSSIBLE");
		else
			for(i=0;i<=sn;i++)
				printf(" %I64d",ans[i]);
		puts("");
	}
	return 0;
}