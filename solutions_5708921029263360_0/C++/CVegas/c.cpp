#include <iostream>
#include <fstream>

using namespace std;

int J, P, S, k, ans;
int cnt[4][4][4];
void dfs(int j, int p, int s, int m)
{
	//cout << j << ' ' << p << ' ' << s << ' ' << m << endl;
	if (j == J)
	{
		if (__builtin_popcount((unsigned)m) > __builtin_popcount((unsigned)ans))
		{
			ans = m;
		}
		return;
	}

	int j0 = j, p0 = p, s0 = s + 1;
	if (s0 == S) s0 = 0, p0++;
	if (p0 == P) p0 = 0, j0++;

	++cnt[3][p][s];
	++cnt[j][3][s];
	++cnt[j][p][3];
	if (cnt[3][p][s] <= k && cnt[j][3][s] <= k && cnt[j][p][3] <= k)
	{
		dfs(j0, p0, s0, m | (1 << (j * 9 + p * 3 + s)));
	}
	--cnt[3][p][s];
	--cnt[j][3][s];
	--cnt[j][p][3];
	dfs(j0, p0, s0, m);
}

int main()
{
	int T;
	cin >> T;
	for (int T0 = 1; T0 <= T; ++T0)
	{
		cout << "Case #" << T0 << ": ";
		cin >> J >> P >> S >> k;
		ans = 0;
		dfs(0, 0, 0, 0);
		cout << __builtin_popcount((unsigned)ans) << endl;
		for (int i = 0; i < 27; ++i)
			if (ans & (1 << i))
			{
				cout << i / 9 + 1 << ' ' << (i % 9) / 3 + 1 << ' ' << i % 3 + 1 << endl;
			}
	}
}