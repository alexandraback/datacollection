#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int a, b, k;
		int total = 0;
		cin >> a >> b >> k;
		for (int p = 0; p < a; p++)
			for (int q = 0; q < b; q++)
				if ((p & q) < k)
				{
					total++;
				}
		cout << "Case #" << t << ": " << total << endl;
	}
	return 0;
}

