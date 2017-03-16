#include <stdio.h>

int main()
{
	static const size_t maxsize = 100;
	unsigned int nCases = 0;scanf("%d",&nCases);
	unsigned int data[maxsize][maxsize] = { 0 };
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		unsigned int rowmax[maxsize] = { 0 },colmax[maxsize] = { 0 };
		unsigned int n = 0,m = 0;scanf("%d%d",&n,&m);
		for(unsigned int i = 0;i < n;++i)
		{
			for(unsigned int k = 0;k < m;++k)
			{
				scanf("%d",&data[i][k]);
				if(data[i][k] > rowmax[i]) rowmax[i] = data[i][k];
				if(data[i][k] > colmax[k]) colmax[k] = data[i][k];
			}
		}

		bool ans = true;
		for(unsigned int i = 0;i < n && ans;++i)
		{
			for(unsigned int k = 0;k < m && ans;++k)
			{
				if(data[i][k] >= rowmax[i]) continue;
				if(data[i][k] >= colmax[k]) continue;
				ans = false;
			}
		}

		printf("Case #%u: %s\n",iCases,ans?"YES":"NO");
	}
	return 0;
}