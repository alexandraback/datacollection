#include <iostream>
#include <iomanip>

using namespace std;

int tt, n;
double a[1000], x;
double k, l, r;
const double e = 1e-12;

int main()
{
	freopen("A-small-attempt3.in", "r", stdin);
	freopen("A-small-attempt3.out", "w", stdout);

	cout << setprecision(8);
	cout.setf(ios::fixed);

	cin >> tt;
	for (int t = 1; t <= tt; ++t)
	{
		cin >> n;
		x = 0;
		for (int i = 0; i != n; ++i)
		{
			cin >> a[i];
			x += a[i];
		}
		cout << "Case #" << t << ":";
		for (int i = 0; i != n; ++i)
		{
			l = 0;
			r = 1;
			while (l < r - e)
			{
				k = (l + r) / 2;
				double x1 = x * k;
				double x2 = x - x1;
				x1 += a[i];
				for (int j = 0; j != n; ++j)
					if (i != j && x1 > a[j])
						x2 -= x1 - a[j];
				if (x2 < e)
					r = k;
				else
					l = k;
			}
			cout << " " << k * 100;
		}
		cout << endl;
	}

	return 0;
}