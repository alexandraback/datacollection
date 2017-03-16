#include <iostream>

using namespace std;

double p[100000];

int main()
{
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    cout << "Case #" << t << ": ";
		int a, b;
		cin >> a >> b;
		double P = 1;
		double M = b + 2;
		cout.precision(6);
		cout.setf(ios::fixed,ios::floatfield);
		for (int i = 0; i < a; i++)
		{
			cin >> p[i];
			P *= p[i];
			double m = a - i - 1 + b - i - 1 + 1 + (1-P) * (b + 1);
			if (m < M) M = m;
		}
		cout << M;
    cout << endl;
  }
  return 0;
}