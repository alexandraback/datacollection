#include <bits/stdc++.h>
using namespace std;

#define int long long

void PutAll(vector< vector<bool> > &d, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			d[i][j] = true;
		}
	}
}

vector< vector<bool> > Solve(int B, int M)
{
	if (M > (1 << (B - 2))) return vector< vector<bool> >();

	vector< vector<bool> > ans(B);
	for (int i = 0; i < B; i++) ans[i].resize(B, false);

	if (M == (1 << (B - 2)))
	{
		PutAll(ans, B);
		return ans;
	}

	PutAll(ans, B - 1);
	for (int i = 0; i < B - 2; i++)
	{
		if ((M >> i)&1) ans[i + 1][B - 1] = true;
	}
	return ans;
}

void Output(int t, const vector< vector<bool> > &ans)
{
	printf("Case #%lld: ", t);
	if (ans.size() == 0)
	{
		puts("IMPOSSIBLE");
		return;
	}
	puts("POSSIBLE");
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
		{
			printf("%d", ans[i][j]);
		}
		puts("");
	}
}

signed main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int B, M;
		cin >> B >> M;
		Output(t, Solve(B, M));
	}
	return 0;
}