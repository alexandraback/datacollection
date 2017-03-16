#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
double nao[1005],ken[1005];
int main()
{
	int T;scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		int n;scanf("%d",&n);
		for (int i=0;i<n;i++)
			scanf("%lf",&nao[i]);
		for (int i=0;i<n;i++)
			scanf("%lf",&ken[i]);
		sort(nao,nao+n);
		sort(ken,ken+n);
		//solve 1.
		int w1 = 0;
		for (int i=0,j=0;i<n && j<n;i++)
		{
			if (ken[j] < nao[i])
			{
				w1++;
				j = j + 1;
			}
		}
		//solve 2.
		int l2 = 0;
		for (int i=0,j=0;i<n && j<n;j++)
		{
			if (nao[i] < ken[j])
			{
				l2++;
				i = i + 1;
			}
		}
		printf("Case #%d: %d %d\n",kase,w1,n-l2);
	}
	return 0;
}