#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
	int T; scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		int C,D,V;
		scanf("%d %d %d",&C,&D,&V);
		vector<int> coins;
		for (int q=0;q<D;++q)
		{
			int t;scanf("%d",&t);
			coins.push_back(t);
		}
		int maxP = 0, ret = 0;
		for (int v=1,i=0;v<=V;v++)
		{
			if (i<D && coins[i]==v)
			{
				maxP += v;
				i++;
			}
			else if (maxP < v)
			{
				//printf("need %d\n",v);
				maxP += v;
				ret++;
			}
		}
		printf("Case #%d: %d\n",kase,ret);
	}

	return 0;
}