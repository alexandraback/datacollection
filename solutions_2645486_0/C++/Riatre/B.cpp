// Warning: Small Only

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main(void)
{
	freopen("B-small-attempt0.in","rt",stdin);
	freopen("B-small.out","wt",stdout);
	int T = 0;
	scanf("%d",&T);
	int TK = 0;
	while(T--)
	{
		printf("Case #%d: ",++TK);
		int E = 0;
		int R = 0;
		int N = 0;
		scanf("%d %d %d",&E,&R,&N);
		if(R > E) R = E;
		int F[20][111] = {0};
		memset(F,0xCC,sizeof(F));
		F[0][E] = 0;
		for(int i = 0;i < N;i++)
		{
			int v = 0;
			scanf("%d",&v);
			for(int p = 0;p <= E;p++)
			{
				for(int j = 0;j <= p;j++)
				{
					int& tar = F[i+1][min(p-j+R,E)];
					tar = max(tar,F[i][p]+v*j);
				}
			}
		}
		printf("%d\n",*max_element(F[N],F[N]+E+1));
	}
	return 0;
}
