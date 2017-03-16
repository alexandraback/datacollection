#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		vector<double> p(a);
		for (int j = 0; j < a; ++j)
			cin >> p[j];

		vector<double> cp(a+1);
		for (int j = 0; j < a + 1; ++j)
		{
			cp[j] = 1.0;
			for (int k = 0; k < j; k++)
				cp[j] *= p[k];
			if (j != a)
				cp[j] *= (1.0 - p[j]);
			//cout << cp[j] << endl;
		}

		for (int j = 1; j < a; ++j)
		{
			cp[j] += cp[j - 1];
		}

		double enter = (b + 2);
		double type = (b - a + 1) * cp[a] + (b - a + 1 + b + 1) * (1-cp[a]);
		vector<double> bp(a);
		for (int j = 1; j < a; j++)
		{
			bp[j] = (j * 2 + b - a + 1) * (1 - cp[a- j - 1]) + (j * 2 + b - a + 1 + b + 1) *cp[a-j-1];
			//cout << bp[j];
		}
		
		double min  = enter < type ? enter : type;
		for (int j = 1; j < a; j++)
			if (min > bp[j]) min = bp[j];

		cout << "Case #" << i + 1 << ": " << fixed << setprecision(6) << min << endl;
	}
}