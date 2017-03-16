#include <stdio.h>

int main(void)
{
	freopen("B-large.in","rt",stdin);
	freopen("B-large.out","wt",stdout);
	int T = 0;
	int TK = 0;
	scanf("%d",&T);
	while(T--)
	{
		int N = 0;
		int S = 0;
		int p = 0;
		int score[200] = {0};
		scanf("%d %d %d",&N,&S,&p);
		for(int i = 0;i < N;i++) scanf("%d",&score[i]);

		int ans = 0;
		for(int i = 0;i < N;i++)
		{
			bool cannormal = false;
			bool cansurprise = false;
			for(int a = p;a <= 10;a++)
			{
				for(int b = a;b >= a-2 && b >= 0;b--)
				{
					int c = score[i]-a-b;
					if(c < 0 || c > 10) continue;
					if(c > a) continue;
					if(a-c <= 1 && a-b <= 1) cannormal = true;
					else if(a-c <= 2) cansurprise = true;
				}
			}
			if(cannormal) ans++;
			else if(cansurprise && S)
			{
				ans++;
				S--;
			}
		}
		printf("Case #%d: %d\n",++TK,ans);
	}
	return 0;
}
