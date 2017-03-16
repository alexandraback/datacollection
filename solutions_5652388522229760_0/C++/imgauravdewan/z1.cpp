#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 10000000;
int main()
{
	int t;
	scanf("%d",&t);
	for(int kases=1;kases<=t;kases++)
	{
		ll n;
		int i;
		scanf("%d",&i);
		ll j,k,l;
		
		if(i==0)
			printf("Case #%d: %s\n",kases,"INSOMNIA");
		else
		{
			n = i;
			bool h[10] = {0};
			int cnt = 0;
			
			while(true)
			{
				k = n;
				while(k)
				{
					l = k%10;
					if(h[l]==0)
						{
						h[l] = 1;
						cnt++;
						}
					k/=10;
				}
				if(cnt==10)
				{
					//n is anwer
					break;
				}
				n+=i;
			}
			printf("Case #%d: %lld\n",kases,n);
			//cout<<i<<"\t"<<n/i<<"\n";
		}
		
	}
	return 0;
}
