#include <iostream>
#include <string>
using namespace std;
int n, sum;
int points[500];

bool check(double l)
{
	double sum1 = 0;
	for (int i = 0; i < n; ++i)
		if (l - points[i] > 0)
			sum1 += l - points[i];
	if (sum1 > sum)
		return true;
	else
		return false;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t = 0;
	cin >> t; getchar();
	for (int counter = 1; counter <= t; ++counter)
	{
		cout << "Case #" << counter << ": ";
		cin >> n;
		sum = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> points[i];
			sum += points[i];
		}
		for (int i = 0; i < n; ++i)
		{
			double l = 0, r = 1;
			for (int j = 0; j < 100; ++j)
			{
				double m = (l + r) / 2;
				if (check(points[i] + sum * m))
					r = m;
				else
					l = m;
			}
			printf("%.10lf ", (l + r) * 50);
		}
		putchar('\n');
	}
}