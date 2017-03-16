#include <iostream>
#include <algorithm>

std::pair<int, int> s[200];
double m[200];
int z[200];

int main()
{
	int T;
	std::cin >> T;
	for (int t = 1 ; t <= T ; ++t)
	{
		int n;
		std::cin >> n;
		double x = 0;
		for (int i = 0 ; i < n ; ++i)
		{
			std::cin >> s[i].first;
			s[i].second = i;
			x += s[i].first;
		}
		std::sort(s, s + n);

		for (int i = 0 ; i < n ; ++i)
		{
			double y = 0;
			double yy = 1;
			int j;
			for (j = 0 ; j < i && yy > 0.0000001 ; ++j)
			{
				double t = (s[j + 1].first - s[j].first) / x;
				if (t * (j + 1) > yy)
				{
					t = yy / (j + 1);
				}
				y += t;
				yy -= t * (j + 1);
			}
			double r = 0;
			for ( ; j < n - 1 && yy > 0.0000001 ; ++j)
			{
				double t = (s[j + 1].first - s[j].first) / x;
				if (t * (j + 1) > yy)
				{
					t = yy / (j + 1);
				}
				r += t;
				yy -= t * (j + 1);
			}
			r += yy / n;
			m[i] = r;
		}

		for (int i = 0 ; i < n ; ++i)
			z[s[i].second] = i;

		std::cout.setf(std::ios::fixed);
		std::cout.precision(6);
		std::cout << "Case #" << t << ":";
		for (int i = 0 ; i < n ; ++i)
			std::cout << " " << m[z[i]] * 100;
		std::cout << "\n";
	}
	return 0;
}

