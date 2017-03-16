#include <bits/stdc++.h>
using namespace std;

int dig[10];

int main()
{
	int t;
	scanf("%d",&t);

	for(int cn=1; cn<=t; cn++)
	{
		int n;
		scanf("%d",&n);

		printf("Case #%d: ",cn);

		if(n==0)
			printf("INSOMNIA\n");
		else
		{
			for(int i=0; i<10; i++)
				dig[i] = 0;

			int total = 0;
			long long curr = 0;
			long long temp;
			while(total!=10)
			{
				curr += n;
				temp = curr;
				while(temp)
				{
					int c = temp%10;
					temp /= 10;
					if(dig[c]==0)
					{
						total++;
						dig[c] = 1;
					}
				}

			}

			printf("%lld\n",curr);
		}
	}
}