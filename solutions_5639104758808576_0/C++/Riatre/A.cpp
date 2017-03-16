#include <bits/stdc++.h>

using namespace std;

int shy[1111];

int main(void)
{
	int T = 0;
	int TK = 0;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d: ", ++TK);
		int Smax = 0;
		scanf("%d",&Smax);
		for(int i = 0;i <= Smax;i++) scanf("%01d",&shy[i]);

		int already = 0;
		int ans = 0;
		for(int i = 0;i <= Smax;i++)
		{
			if(already < i)
			{
				ans += i - already;
				already = i;
			}
			already += shy[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}