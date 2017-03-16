#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXD 1200

int T,D,P[MAXD];

int GetAnswer(int pmax)
{
	int ans = pmax;
	for (int i=0;i<D;++i)
	{
		ans += (P[i] - 1) / pmax;
	}
	return ans;
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	for (int cases=1;cases<=T;cases++)
	{
		scanf("%d",&D);
		int pmax = 0;
		for (int i=0;i<D;i++)
		{
			scanf("%d",&P[i]);
			pmax = max(P[i], pmax);
		}
		int ans = pmax;
		for (int i=1;i<=pmax;++i)
		{
			ans = min(GetAnswer(i), ans);
		}
		printf("Case #%d: %d\n", cases, ans);
	}
}
