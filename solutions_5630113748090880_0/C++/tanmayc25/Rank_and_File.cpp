#include <bits/stdc++.h>
using namespace std;

int cnt[2505];
vector<int > v;
int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int tt = 1;tt <= t;tt++)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0;i < 2 * n - 1;i++)
		{
			for (int j = 0;j < n;j++)
			{
				int temp;
				scanf("%d", &temp);
				cnt[temp]++;
			}
		}
		for (int i = 1;i <= 2500;i++)
			if (cnt[i] & 1)
				v.push_back(i);
		printf("Case #%d: ", tt);
		for (int i = 0;i < v.size();i++)
			printf("%d ", v[i]);
		puts("");
		v.clear();
		memset(cnt, 0, sizeof(cnt));
	}
	return 0;
}