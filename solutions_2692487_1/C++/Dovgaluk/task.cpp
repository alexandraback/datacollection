#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int T;
	std::cin >> T;
	for (int t = 1 ; t <= T ; ++t)
	{
		int a, n;
		std::cin >> a >> n;
		std::vector<int> v(n);
		for (int i = 0 ; i < n ; ++i)
			std::cin >> v[i];
		std::sort(v.begin(), v.end());
		int r = n;
		if (a > 1)
		{
			std::vector<int> z1(n, -1);
			z1[0] = a;
			for (int i = 0 ; i < n ; ++i)
			{
				std::vector<int> z2(n, -1);
				for (int j = 0 ; j < n ; ++j)
					if (z1[j] >= 0)
					{
						if (z1[j] > v[i])
						{
							z2[j] = z1[j] + v[i];
						}
						else
						{
							if (j < n - 1)
							{
								// del
								z2[j + 1] = z1[j];
								// add some new
								int t = z1[j];
								int cnt = 0;
								while (t <= v[i] && cnt < n)
								{
									t += t - 1;
									++cnt;
								}
								if (j + cnt < n)
								{
									if (z2[j + cnt] < t + v[i])
										z2[j + cnt] = t + v[i];
								}
							}
						}
					}
				z1.swap(z2);
			}
			for (int i = 0 ; i < n ; ++i)
				if (z1[i] >= 0)
				{
					r = i;
					break;
				}
		}
		std::cout << "Case #" << t << ": " << r << "\n";
	}
	return 0;
}

