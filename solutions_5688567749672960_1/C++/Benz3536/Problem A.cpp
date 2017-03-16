#include<bits/stdc++.h>
using namespace std;
main()
{
	freopen("A-large.in","r",stdin);
	freopen("out-A-large.txt","w",stdout);
	long long a,b,c,d,e,f,g,ans,num;
	char s[100];
	scanf("%I64d",&a);
	for(b=0;b<a;b++)
	{
		ans=0;
		scanf("%I64d",&c);
		while(c>10)
		{
			e=c;
			g=1;
			num=0;
			while(e>0)
			{
				num+=e%10;
				e/=10;
			}
			if(num==1)ans++,c--;
			e=c;
			while(e>9)
			{
				g*=10;
				e/=100;
			}
			d=c%g;//printf("[%d %d %d]",c,g,d);
			if(d==0)d+=g;
			d--;
			e=c-d;
			f=0;
			while(e>0)
			{
				f*=10;
				f+=e%10;
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
