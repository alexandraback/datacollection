#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int n, x, y;

long long var, good;

void sim(int l, int r, int tot, int lim, int chk)
{
	if (l>lim || r>lim || l+r>tot)
		return;

	if (l + r == tot)
	{
		++var;

		if (l >= chk)
		{
			++good;
		}
	}

	sim(l+1, r, tot, lim, chk);
	sim(l, r+1, tot, lim, chk);
}

double solve()
{
	int lev = 0, nused = 1, lsize = 1;

	while (true)
	{
		lsize += 4;

		if (nused + lsize > n)
		{
			break;
		}

		nused += lsize;
		++lev;
	}
	
	int req = (abs(x) + y) / 2;

	if (req > lev + 1)
		return 0;
	if (req <= lev)
		return 1;

	int rest = n - nused;

	var = 0;
	good = 0;
	int hl = (lsize - 1)/2;

	sim(0, 0, rest, hl, y+1);

	if (good == 0)
		return 0;

	return ((double)good)/var;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;

	cin >> t;

	cout.precision(15);

	for (int i=0; i<t; ++i)
	{
		cin >> n >> x >> y;

		double r = solve();

		cout << "Case #" << i+1 << ": " << fixed << r << endl;
	}

	return 0;
}