#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <set>

using namespace std;

int r, n, m, k;
int ls[64][5], ln;
int ds[5];
int kk[8];

void Dfs(int s, int lls)
{
	if (s == n)
	{
		memcpy(ls[ln], ds, sizeof(ds));
		ln ++;
		return;
	}
	for (int k = lls; k <= m; k ++)
	{
		ds[s] = k;
		Dfs(s + 1, k);
	}
}

set <int> pro[64];

bool Check(int kn)
{
	for (int i = 0; i < k; i ++)
		if (pro[kn].find(kk[i]) == pro[kn].end())
			return false;
	return true;
}

void Work()
{
	cin >> r >> n >> m >> k;
	ln = 0;
	Dfs(0, 2);

	for (int i = 0; i < ln; i ++)
	{
		pro[i].clear();
		for (int s = 0; s < 8; s ++)
		{
			int z = 1;
			for (int j = 0; j < n; j ++)
				if ((1 << j) & s)
					z *= ls[i][j];
			pro[i].insert(z);
		}
	}

	for (int rr = 0; rr < r; rr ++)
	{
		for (int i = 0; i < k; i ++)
			cin >> kk[i];
		for (int i = 0; i < ln; i ++)
			if (Check(i))
			{
				for (int j = 0; j < n; j ++)
					cout << ls[i][j];
				cout << endl;
				break;
			}
	}
}

int main()
{
	freopen("C-small-1-attempt0.in", "r", stdin);
	freopen("C-small-1-out.txt", "w", stdout);

	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	cout << "Case #1:" << endl;
	Work();

	return 0;
}