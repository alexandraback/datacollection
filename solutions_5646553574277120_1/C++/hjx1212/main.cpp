#include<bits/stdc++.h>
using namespace std;

int a[105];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,t,c,d,v,s,i;
	long long nw;
	for(scanf("%d",&T),t=1;t<=T;t++)
	{
		for(scanf("%d%d%d",&c,&d,&v),i=0;i<d;i++)
			scanf("%d",a+i);
		for(nw=s=i=0;nw<v;)
		{
			if(i<d&&a[i]<=nw+1)
				nw+=1ll*c*a[i],i++;
			else
				nw+=1ll*c*(nw+1),s++;
		}
		printf("Case #%d: %d\n",t,s);
	}
}
