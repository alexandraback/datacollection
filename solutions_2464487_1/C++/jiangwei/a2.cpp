#include <iostream>
#include <cstdio>
#include <cstring>
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
/*		
		long long result = 0, c = 2 * r + 1;
		while (t >= c)
		{
			++result;
			t -= c;
			c += 4;
		}
*/
		long long p = 1, q = t, result = 1;
		while (p <= q)
		{
			long long K = (p + q) / 2;
			long long temp = (2 * K + 2 * r - 1);
//			if (temp > 0 && temp <= t)
			if (/*t * 1.0 / K + 1e-6 >= temp &&*/ K * temp <= t && K * temp > 0)
			{
				result = K;
				p = K + 1;
			}
			else
			{
				q = K - 1;
			}
		}
		if (result * (2 * result + 2 * r - 1) > t ||
				(result + 1) * (2 * result + 2 * r + 1) <= t)
		{
			fprintf(stderr, "wrong! %lld \n", (result + 1) * (2 * result + 2 * r + 1) - t);
		}
		cout << result << endl;
	}
	return 0;
}
