#include <ios>
#include <iostream>

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w",stdout);
	int tc, c, k, s;
	std::cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		std::cin >> k >> c >> s;
		std::cout << "Case #" << t+1 << ":";
		for (int i = 0; i < k; i++)
		{
			std::cout << ' ';
			std::cout << i+1;
		}
		std::cout << '\n';
	}
}
