#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ":" << endl;
		int N, A;
		double D;
		cin >> D >> N >> A;
		double t[N], x[N];
		double ac[A];

		double othertime = 0.0;
		for (int n = 0; n < N; n++)
		{
			cin >> t[n] >> x[n];
			if (x[n] == D)
				othertime = t[n];
			if (x[n] > D)
			{
				double v = ((double)x[n] - (double)x[n-1]) / (double)((double)t[n] - (double)t[n-1]);
				double dd = (D - x[n - 1]) / v;
				double dt = t[n - 1];
				othertime = dd + (double)dt;
			}
		}

		for (int a = 0; a < A; a++)
		{
			cin >> ac[a];
			double mytime = sqrt((double)D * 2.0 / ac[a]);
			if (othertime < mytime)
				cout << mytime << endl;
			else
				cout << othertime << endl;
		}
	}
	return 0;
}
