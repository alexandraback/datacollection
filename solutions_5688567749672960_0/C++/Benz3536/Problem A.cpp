#include<bits/stdc++.h>
using namespace std;
main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out-A-small.txt","w",stdout);
	long long a,b,c,d,e,f,ans;
	char s[100];
	scanf("%I64d",&a);
	for(b=0;b<a;b++)
	{
		ans=0;
		scanf("%I64d",&c);
		while(c>10)
		{
			d=c%100;
			if(d==0)c+=100;
			d--;
			e=c;
			f=0;
			while(e>0)
			{
				f*=10;
				if(f>=100)f+=e%10;
				else f++;
				e/=10;
			}
			e=f;
			//printf("%lld\n",e);
			if(e+d+1<c)c=e,ans+=d+1;
			else c-=d+2,ans+=d+2;
		}
		//printf("[%lld]",c);
		ans+=c;
		printf("Case #%lld: %lld\n",b+1,ans);
	}
}
