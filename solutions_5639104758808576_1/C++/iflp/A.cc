#include <bits/stdc++.h>
using namespace std;

void solve ()
{
	int maxLevel;
	string str;
	cin >> maxLevel >> str;
	int lo = -1, hi = maxLevel; // (lo, hi]
	while (lo + 1 < hi)
	{
		int mi = (lo + hi) >> 1, valid = true;
		// invite mi level-0 friends
		int curStandUps = mi + str[0] - '0';
		for (int i = 1; i <= maxLevel; ++i)
		{
			if (curStandUps >= i)
			{
				curStandUps += str[i] - '0';
			}
			else
			{
				valid = false;
				break;
			}
		}
		if (valid)
		{
			hi = mi;
		}
		else
		{
			lo = mi;
		}
	}
	static int ncase = 0;
	cout << "Case #" << ++ncase << ": " << hi << endl;
}

int main ()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int ncase = 0;
	cin >> ncase;
	while (ncase--) solve();
	return 0;
}

