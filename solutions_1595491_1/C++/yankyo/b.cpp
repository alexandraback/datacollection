
#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ": ";

		int N, S, p;

		cin >> N >> S >> p;

		int yes = 0, surp_only = 0;

		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;

			// get rid of the special cases
			if (a == 0)
			{
				if (p == 0) yes++;
			} else if (a >= 28)
			{
				yes++;
			} else
			{
				int b = a / 3;
				int m = a % 3;

				if ((b >= p) || (m > 0 && b+1 >= p))
				{
					yes++;
				} else if ((m == 0 && b + 1 >= p) || (m == 2 && b + 2 >= p))
				{
					surp_only++;
				}
			}
		}

		int res = yes;

		if (surp_only < S) res += surp_only; else res += S;
		
		cout << res << endl;
	}

	return 0;
}
