#include <iostream>
#include <iomanip>

using namespace std;

int tt, n, a[1000], b[1000];
int x1, x2;
bool flag;

bool find(int k)
{
	if (x1 == x2 && x1 != 0)
	{
		return true;
	}
	if (k == n)
		return false;
	if (find(k + 1)) return true;
	b[k] = 1;
	x1 += a[k];
	if (find(k + 1)) return true;
	x1 -= a[k];
	b[k] = 2;
	x2 += a[k];
	if (find(k + 1)) return true;
	x2 -= a[k];
	b[k] = 0;
	return false;
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);

	cin >> tt;
	for (int t = 1; t <= tt; ++t)
	{
		cin >> n;
		for (int i = 0; i != n; ++i)
		{
			cin >> a[i];
		}
		cout << "Case #" << t << ":" << endl;
		memset(b, 0, sizeof(b));
		x1 = x2 = 0;
		if (find(0))
		{
			for (int i = 0; i != n; ++i)
				if (b[i] == 1)
					cout << a[i] << " ";
			cout << endl;
			for (int i = 0; i != n; ++i)
				if (b[i] == 2)
					cout << a[i] << " ";
			cout << endl;
		}
		else
		{
			cout << "Impossible" << endl;
		}
	}

	return 0;
}