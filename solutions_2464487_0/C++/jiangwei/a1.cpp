#include <iostream>
using namespace std;

int main()
{
	int T, task;
	cin >> T;
	for (task = 1; task <= T; task++)
	{
		cout << "Case #" << task << ": ";

		long long r, t;
		cin >> r >> t;
		
		long long result = 0, c = 2 * r + 1;
		while (t >= c)
		{
			++result;
			t -= c;
			c += 4;
		}
		cout << result << endl;
	}
	return 0;
}
