#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		long long int p,q;
		int m,n,k;
		scanf("%d %d %d",&n,&m,&k);
		if(k<=4) printf("%d\n",k );
		else if(m<=2 || n<=2)
		{
			printf("%d\n",k );
		}
		else if(k<(m*n-4))
		{
			int min=m*n;
			for (int i = 1; i < m; ++i)
			{
				int initial =3*i +2;
				int remaining = k-initial;
				if(remaining<=0)
				{
					if(2*i + 2 < min) min = 2*i +2;
					continue;
				}
				else
				{
					int req = 2*i + 2 + 2*remaining/(i+3) + remaining%(i+3);
					if(remaining/(i+3) <= n-2)
					{
						if(req<min) min = req;
					}
				}
			}
			for (int i = 1; i < n; ++i)
			{
				int initial =3*i +2;
				int remaining = k-initial;
				if(remaining<=0)
				{
					if(2*i + 2 < min) min = 2*i +2;
					continue;
				}
				else
				{
					int req = 2*i + 2 + 2*remaining/(i+3) + remaining%(i+3);
					if(remaining/(i+3) <= m-2)
					{
						if(req<min) min = req;
					}
				}
			}
			printf("%d\n",min );
		}
		else
		{
			printf("%d\n",2*(m+n-4) + k+4-m*n );
		}
	}

}