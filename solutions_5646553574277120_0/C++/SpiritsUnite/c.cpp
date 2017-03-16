#include <bits/stdc++.h>

using namespace std;

int T, c, d, v;

int can[50], deno[120];

int check(int at, int last, set<int> &dset)
{
	if (at > 5) return -1;
	int all = true;
	for (int i = 0; i <= v; i++)
		if (!can[i]) all = false;
	if (all) return 0;
	int ans = 10;
	for (int i = last + 1; i <= v; i++)
	{
		if (dset.count(i)) continue;
		vector<int> add;
		for (int j = v; j; j--)
			if (!can[j] && j - i >= 0 && can[j-i])
			{
				can[j] = true;
				add.push_back(j);
			}
		int tmp = check(at+1, i, dset);
		if (tmp != -1) ans = min(tmp, ans);
		for (auto i: add) can[i] = false;
	}
	if (ans == 10) return -1;
	return ans + 1;
}

int main()
{
	cin >> T;
	for (int C = 1; C <= T; C++)
	{
		cin >> c >> d >> v;
		set<int> dset;
		for (int i = 0; i < d; i++)
		{
			cin >> deno[i];
			dset.insert(deno[i]);
		}
		sort(deno, deno + d);
		memset(can, 0, sizeof(can));
		can[0] = true;
		for (int i = 0; i < d; i++)
			for (int j = v; j; j--)
				if (j - deno[i] >= 0 && can[j-deno[i]]) can[j] = true;
		cout << "Case #" << C << ": " << check(0, 0, dset) << '\n';
	}
	return 0;
}

