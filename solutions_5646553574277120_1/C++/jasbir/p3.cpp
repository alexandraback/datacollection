#include<cstdio>
#include<algorithm>
using namespace std;
long long ar[105];
int main()
{
	int ntc; scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		printf("Case #%d: ",tc);
		long long c,d,v;
		scanf("%lld %lld %lld",&c,&d,&v);
		long long r=0;
		int ans=0;
		for(int i=0;i<d;i++)
		{
			scanf("%d",ar+i);
		
		}
		sort(ar,ar+d);
		for(int i=0;i<d;i++)
		{
			long long t;
			t=ar[i];
			while(r<(t-1))
			{
				long long a=r+1;
				r+=(a*c);
				ans++;
			}
			
			r+=(t*c);
			
		}
		
		while(r<v)
		{
			long long a=r+1;
				r+=(a*c);
				ans++;
		}
		printf("%d\n",ans);
	}
}
