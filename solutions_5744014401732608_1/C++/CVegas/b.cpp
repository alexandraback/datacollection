#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int T0 = 1; T0 <= T; ++T0)
	{
		cout << "Case #" << T0 << ": ";
		int n;
		long long m;
		cin >> n;
		cin >> m;

		if (m > (1LL << (n - 2)))
		{
			cout << "IMPOSSIBLE" << endl;
		}
		else
		{
			cout << "POSSIBLE" << endl;

			for (int i = 0; i < n - 1; ++i)
			{
				cout << "0";
				for (int j = 0; j < i; ++j) cout << "0";
				//cout << "1";
				for (int j = i + 1; j < n - 1; ++j) cout << "1";
				if ((m & (1LL << (i - 1))) || m == (1LL << (n - 2)))
					cout << "1";
				else
					cout << "0";
				cout << endl;
			}
			for (int j = 0; j < n; ++j) cout << "0";
			cout << endl;
		}
	}
}