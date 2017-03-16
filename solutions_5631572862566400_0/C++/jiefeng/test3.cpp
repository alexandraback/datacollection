#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	scanf("%d",&tc);
	for(int t = 1;t<=tc;t++)
	{
		int n;
		scanf("%d",&n);
		int bff[1005];
		int perm[1005];
		for(int i = 1;i<=n;i++)
		{
			scanf("%d",&bff[i]);
			perm[i-1] = i;
		}
		int maxi = 0;
		do
		{
			for(int j = 1;j<=n;j++)
			{
				bool can = 1;
				for(int k = 0;k<j;k++)
				{
					can &= (bff[perm[k]] == perm[(k+j-1)%j]) || (bff[perm[k]] == perm[(k+1)%j]);
				}
				if(can)maxi = max(maxi, j);
			}
		} while( next_permutation(perm,perm+n));
		printf("Case #%d: %d\n",t,maxi);
	}
}
