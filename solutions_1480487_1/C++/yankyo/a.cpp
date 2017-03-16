
#include <iostream>

using namespace std;

int main()
{
	double eps = 0.0000001;
	int T;

	cin >> T;

	cout.precision(10);

	for (int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ": ";
		int N;
		cin >> N;

		int sum = 0, min = 100;
		int *s = new int[N];
		for (int n = 0; n < N; n++)
		{
			cin >> s[n];
			sum += s[n];
			if (min > s[n]) min = s[n];
		}

		double *p = new double[N];
		for (int n = 0; n < N; n++) p[n] = 0.0;
		double bod = 100.0 / (double) sum;
		double zbyva = 100.0;

		for (int level = min; level <= 2000; level++)
		{
			int count = 0;
			
			for (int i = 0; i < N; i++) if (s[i] == level) count++;

			if (count == 0) continue;

			if (zbyva >= count * bod + eps)
			{
				for (int i = 0; i < N; i++) if (s[i] == level)
				{
					p[i] += bod;
					s[i]++;
				}
				zbyva -= bod * count;
			} else
			{
				double rozdat = zbyva / (double) count;
				for (int i = 0; i < N; i++) if (s[i] == level)
				{
					p[i] += rozdat;
				}
				break;
			}
		}

		for (int n = 0; n < N; n++)
		{
			cout << p[n];
			if (n != N-1) cout << " ";
		}

		cout << endl;

		delete [] s;
		delete [] p;
	}

	return 0;
}

