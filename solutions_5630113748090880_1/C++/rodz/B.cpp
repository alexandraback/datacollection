#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T, cnt = 0;
	scanf("%d", &T);

	while(T--)
	{
		int freq[2510] = {0}, n;
		scanf("%d", &n);
		for (int i = 0; i < 2*n-1; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int x;
				scanf("%d", &x);
				freq[x]++;
			}
		}
		vector<int> ans;
		printf("Case #%d:", ++cnt);
		for (int i = 1; i <= 2500; i++)
		{
			if (freq[i]%2)
				printf(" %d", i);
		}
		printf("\n");	
	}
	return 0;
}
