#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n, ans;
bool seen[20];
int test, digit;

int main()
{
	freopen("a-small.in", "r", stdin);
	freopen("a-small.out", "w", stdout);
	
	scanf("%d" ,&test);
	
	for(int t=1; t<=test; t++)
	{
		scanf("%lld" ,&n);
		
		if(n==0)
		{
			printf("Case #%d: INSOMNIA\n" ,t);
			continue;
		}
		
		digit = ans = 0;
		memset(seen, 0, sizeof(seen));
		
		for(ans=1; ; ans++)
		{
			ll x=n*ans;
			
			while(x)
			{
				digit+=(seen[x%10]==0);
				seen[x%10] = 1;
				x/=10;
			}
			
			if(digit==10)
				break;
		}
		
		printf("Case #%d: %lld\n" ,t ,ans*n);
	}
}
