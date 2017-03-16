#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	for(int tc=1; tc <= T; tc++)
	{
		int K, C, S;
		scanf("%d%d%d", &K, &C, &S);

		printf("Case #%d: ", tc);

		long long len = 1;
		for(int i=0; i < C; i++)
			len = len * K;

		vector<int> ans;

		int n = (K + C - 1) / C;
		if(n <= S)
		{
			for(int i=0; i < n; i++)
				ans.push_back(i * (K - 1) + K);
		}

		if(ans.empty())
		{
			puts("IMPOSSIBLE");
			continue;
		}
		for(size_t i=0; i < ans.size(); i++)
			printf("%d ", ans[i]);
		puts("");
	}
	return 0;
}