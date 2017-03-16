#include <iostream>

#define ld long double
#define min(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

const int MAX = 100000;
ld p[MAX+1];

int main()
{
	cout.precision(30);

	int cases;
	cin >> cases;

	for (int c = 0; c < cases; c++)
	{
		int n, m;
		cin >> m >> n;
		for (int i = 0; i < m; i++)
		{
			cin >> p[i];
		}

		ld best = 10e10;
		ld pGood = 1;
		for (int i = 0; i <= m; i++)
		{
			ld pBad = 1 - pGood;

			ld e = pGood * (m - i + n - i + 1)
				+ pBad * (m - i + n - i + 1 + n + 1);
			best = min(best, e);

			pGood *= p[i];
		}

		cout << "Case #" << c+1 << ": " << min(best, n + 2) << "\n";
	}

	return 0;
}
