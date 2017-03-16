#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int a[1001];
int b[1001][1001];
int c[1001];
int N;

int work()
{
	for (int i = 1; i <= N; i++)
	{
		int vis[1001];
		memset(vis, 0, sizeof vis);
		int j = i, k = 1;
		while (a[a[j]] != j && !vis[j])
		{
			vis[j] = 1;
			j = a[j];
			k++;
		}
		if (a[a[j]] == j)
			c[j] = max(c[j], k);
	}
	int ans = 0;
	for (int k = 1; k <= N; k++)
		ans += c[k];
	for (int i = 1; i <= N; i++)
	{
		int vis[1001];
		memset(vis, 0, sizeof vis);
		int j = i, k = 1;
		while (a[j] != i && !vis[j])
		{
			vis[j] = 1;
			j = a[j];
			k++;
		}
		if (a[j] == i)
			ans = max(ans, k);
	}
	return ans;
}

int main()
{
	int Cases;
	cin >> Cases;
	for (int cc = 1; cc <= Cases; cc++)
	{
		cin >> N;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		for (int i = 1; i <= N; i++)
			cin >> a[i];
		cout << "Case #" << cc << ": " << work() << endl;
	}
}