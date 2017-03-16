#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	for (int i = 0; i < n; )
	{
		size_t result = 0;
		int a, b;
		std::cin >> a >> b;
		for (int j = a; j <= b; ++j)
		{
			int t = j;
			int tmp2 = 10;
			for (int tmp3 = t; tmp3 >= 10; tmp3 /= 10, tmp2 *= 10);
			do
			{
				//std::cout << "checking " << j << " and " << t << std::endl;
				if (t >= a && t <= b && j < t)
				{
					++result;
				}
				((t *= 10) += (t / tmp2)) %= tmp2;
			}
			while (t != j);
		}
		std::cout << "Case #" << ++i << ": " << result << std::endl;
	}
}
