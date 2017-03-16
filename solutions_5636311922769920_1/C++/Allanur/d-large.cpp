#include <stdio.h>
#include <algorithm>


using namespace std;
typedef long long ll;

ll pw(ll a, ll b)
{
	ll ret = 1;
	
	for(int i=0; i<b; i++)
		ret*=a;
	
	return ret;
}

ll k, c, s, test;

int main()
{
	freopen("d-large.in", "r", stdin);
	freopen("d-large.out", "w", stdout);
	
	scanf("%lld" ,&test);
	
	for(int t=1; t<=test; t++)
	{
		scanf("%lld %lld %lld" ,&k ,&c ,&s);
		
		printf("Case #%d:" ,t);
		
		if(c==1)
		{
			if(k!=s)
			{
				printf(" IMPOSSIBLE\n");
				continue;
			}
			else
			{
				for(int i=1; i<=s; i++)
					printf(" %d" ,i);
				
				printf("\n");
				continue;
			}
		}
		
		if(s<(k+1)/2)
		{
			printf(" IMPOSSIBLE\n");
			continue;
		}
		
		for(ll i=2,b=0; i<=k; i+=2,b++)
			printf(" %lld" ,pw(k,c-1)*b + i);
		
		if(k%2==1)
			printf(" %lld" ,pw(k,c));
		
		printf("\n");
	}
}
