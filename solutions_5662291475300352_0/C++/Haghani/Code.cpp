#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int _ = 1; _ <= t; _++)
	{
		int n;
		cin >> n;
		long long p1, t1, p2, t2;
		if (n == 1)
		{
			cin >> p1 >> p2 >> t1;
			if (p2 == 1)
			{
				cout << "Case #" << _ << ": 0\n";
				continue;
			}
			p2 = p1;
			t2 = t1 + 1;
		}
		else
			cin >> p1 >> t1 >> t1 >> p2 >> t2 >> t2;
		if (t1 > t2)
		{
			swap(p1, p2);
			swap(t1, t2);
		}
		if (t1 * (720 - p1) <= t2 * (360 - p2))
			cout << "Case #" << _ << ": 1\n";
		else
			cout << "Case #" << _ << ": 0\n";
	}
	return 0;
}
