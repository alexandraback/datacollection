#include <iostream>
#include <vector>

int main()
{
	int T;
	std::cin >> T;
	for (int t = 1 ; t <= T ; ++t)
	{
		int n;
		int a[20];
		std::cin >> n;
		std::vector<int> mm(20 * 100000);
		for (int i = 0 ; i < n ; ++i)
			std::cin >> a[i];
		int m;
		int s = 0;
		for (m = 0 ; m < (1 << n) ; ++m)
		{
			s = 0;
			for (int j = 0 ; j < n ; ++j)
				if (m & (1 << j))
					s += a[j];

			if (mm[s])
				break;
			mm[s] = m;
		}
		std::cout << "Case #" << t << ":" << "\n";
		if (m == (1 << n))
			std::cout << "Impossible\n";
		else
		{
			bool first = true;
			for (int j = 0 ; j < n ; ++j)
				if (m & (1 << j))
				{
					std::cout << (first ? "" : " ") << a[j];
					first = false;
				}
			std::cout << "\n";
			m = mm[s];
			first = true;
			for (int j = 0 ; j < n ; ++j)
				if (m & (1 << j))
				{
					std::cout << (first ? "" : " ") << a[j];
					first = false;
				}
			std::cout << "\n";
		}
	}
	return 0;
}

