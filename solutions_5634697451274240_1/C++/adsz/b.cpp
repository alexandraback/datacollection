#include <bits/stdc++.h>

void test()
{
	std::string cakes;
	std::cin >> cakes;
	
	char last = '+';
	size_t result = 0;
	for (auto it = cakes.rbegin(); it!= cakes.rend(); ++it)
	{
		if (last != *it) result++;
		last = *it;
	}
	
	std::cout << result;
}

int main()
{
	size_t c;
	std::cin >> c;
	for (size_t i = 1; i<=c; ++i)
	{
		std::cout << "Case #" << i << ": ";
		test();
		std::cout << std::endl;
	}
}
