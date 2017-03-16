#include <bits/stdc++.h>

void test()
{
	size_t start;
	std::cin >> start;
	
	if (start == 0)
	{
		std::cout << "INSOMNIA";
		return;
	}
	
	int seen_bits = 0;
	
	size_t x;
	for (x = start; seen_bits < 0b1111111111; x += start)
	{
		size_t n = x;
		while (n>0)
		{
			int digit = n%10;
			seen_bits |= 1 << digit;
			n/=10;
		}
	}
	
	std::cout << x - start;
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
