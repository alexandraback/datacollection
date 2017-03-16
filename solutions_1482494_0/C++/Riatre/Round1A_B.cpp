#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main(void)
{
	freopen("B.in","rt",stdin);
	freopen("B.out","wt",stdout);
	int TK = 0;
	int T = 0;
	scanf("%d",&T);
	while(T--)
	{
		int Need1[1111] = {0};
		int Need2[1111] = {0};
		int Score[1111] = {0};
		int n = 0;
		scanf("%d",&n);
		for(int i = 0;i < n;i++)
		{
			scanf("%d %d",&Need1[i],&Need2[i]);
		}

		int ans = 0;
		int curScore = 0;
		while(curScore < 2*n)
		{
			bool did2 = false;
			int id = -1;
			for(int i = 0;i < n;i++)
			{
				if(Score[i] < 2 && curScore >= Need2[i])
				{
					curScore += 2-Score[i];
					Score[i] = 2;
					ans++;
					did2 = true;
					break;
				}
				if(Score[i] < 1 && curScore >= Need1[i])
				{
					if(id == -1 || Need2[i] > Need2[id]) id = i;
				}
			}
			if(did2) continue;
			if(id == -1) break;
			Score[id] = 1;
			ans++;
			curScore++;
		}

		if(curScore < 2*n) printf("Case #%d: Too Bad\n",++TK);
		else printf("Case #%d: %d\n",++TK,ans);
	}
	return 0;
}
