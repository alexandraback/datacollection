#include <stdio.h>
#include <vector>
#include <assert.h>

using std::vector;

int main()
{
	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		unsigned int e = 0,r = 0,n = 0;scanf("%d%d%d",&e,&r,&n);
		if(r > e) r = e;
		vector<unsigned int> data(n,0);
		for(unsigned int i = 0;i < n;++i) scanf("%d",&data[i]);
		vector< vector<unsigned int> > dps(n,vector<unsigned int>(e+1,0));
		for(unsigned int i = r;i <= e;++i)
		{
			dps[0][i] = data[0]*(e - i + r);
			//printf("%d %d\n",i,dps[0][i]);
		}

#if 1
		for(unsigned int i = 1;i < n;++i)
		{
			for(unsigned int k = r;k <= e;++k)
			{
				for(unsigned int j = k - r;j <= e;++j)
				{
					unsigned int x = data[i];
					x *= (j - k + r);
					x += dps[i-1][j];
					//printf("%d %d %d %d\n",i,k,j,x);
					if(x > dps[i][k]) dps[i][k] = x;
				}
				//printf("%d %d %d\n",i,k,dps[i][k]);
			}
		}
#else
		for(unsigned int i = 1;i < n;++i)
		{
			for(unsigned int j = r;j <= e;++j)
			{
				for(unsigned int k = 0;k <= j;++k)
				{
					unsigned int x = data[i]*k;
					x += dps[i-1][j];
					unsigned int y = j - k + r;
					if(y > e) y = e;
					if(x > dps[i][y]) dps[i][y] = x;
				}
				//printf("%d %d %d\n",i,k,dps[i][k]);
			}
		}
#endif

		unsigned int ans = 0;
		for(unsigned int i = 0;i <= e;++i)
		{
			if(dps[n-1][i] > ans) ans = dps[n-1][i];
		}
		printf("Case #%u: %u\n",iCases,ans);
	}
	return 0;
}