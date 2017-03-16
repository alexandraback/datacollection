#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++)
	{
		long long a, n, cur = 0;
		cin >> a >> n;
		vector <long long> x(n);
		for (int i = 0; i < n; i++)
			cin >> x[i];
		sort(x.begin(), x.end());

		long long ans = n;


		for (int i = 0; i < n; i++)
		{
			if (a == 1)
				continue;

			if (x[i] >= a)
			{
				ans = min(ans, cur + n - i);
				while (x[i] >= a)
				{
					a = 2 * a - 1;
					cur++;
				}
			}
			a += x[i];
		}

		if (a != 1)
			ans = min(ans, cur);

		cout << "Case #" << tt << ": " << ans << endl;
	}
	return 0;
}