#include <iostream>

int main()
{
	int t;
	std::cin >> t;
	for (int c = 0; c < t; )
	{
		size_t result = 0;
		int n, s, p, x;
		std::cin >> n >> s >> p;
		for (int i = 0; i < n; ++i)
		{
			std::cin >> x;
			int tmp;
			switch (x % 3)
			{
				case 0:
					tmp = x / 3;
					if (tmp >= p)
					{
						++result;
					}
					if (tmp - 1 >= 0 && tmp == p - 1 && s > 0)
					{
						++result;
						--s;
					}
					break;
				case 1:
					if ((x + 2) / 3 >= p)
					{
						++result;
					}
					break;
				case 2:
					tmp = (x + 1) / 3;
					if (tmp >= p)
					{
						++result;
					}
					if (tmp - 1 >= 0 && tmp == p - 1 && s > 0)
					{
						++result;
						--s;
					}
					break;
			}
		}
		std::cout << "Case #" << ++c << ": " << result << std::endl;
	}
	return 0;
}
