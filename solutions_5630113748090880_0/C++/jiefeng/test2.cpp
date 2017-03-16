#include <bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	scanf("%d",&tc);
	for(int i = 1;i<=tc;i++)
	{
		int n;
		scanf("%d",&n);
		int cnt[3005] = {0};
		for(int j = 0;j<2*n-1;j++)
		{
			for(int k = 0;k<n;k++)
			{
				int a;
				scanf("%d",&a);
				cnt[a]++;
			}
		}
		printf("Case #%d: ",i);
		for(int j = 0;j<=2500;j++)
		{
			if((cnt[j]&1))
			printf("%d ",j);
		}
		printf("\n");
	}
}
