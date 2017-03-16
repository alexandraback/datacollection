#include <cstdlib>
#include <iostream>

long double f(int n, int x, int y)
{
	x = std::abs(x);
	
	auto xy = (x + y) / 2;
	
	// half diamond
	int definite_n = 1;
	int accum = 1;
	for (int i = 0; i < xy; ++i)
		definite_n += (accum += 4);
	if (n >= definite_n) return 1;
	
	// one off the top
	if (n == definite_n - 1 && !(x == 0 && y == xy * 2))
		return 1;
	
	/////////////////////
	
	if (n == 2)
	{
		if (x == 2 && y == 0) return .5;
		// otherwise, 0
	}
	
	if (n == 3)
	{
		if (x == 2 && y == 0) return .75;
		if (x == 1 && y == 1) return .25;
		// otherwise, 0
	}
	
	if (n == 4)
	{
		if (x == 2 && y == 0) return 1;
		if (x == 1 && y == 1) return .5;
		// otherwise, 0
	}
	
	if (n == 5)
	{
		
	}
			
	return 0;
}

int main()
{
	int test_cases;
	std::cin >> test_cases;
	
	for (int i = 0; i < test_cases; ++i)
	{
		int n, x, y;
		std::cin >> n >> x >> y;
		
		std::cout << "Case #" << i + 1 << ": " << f(n, x, y) << std::endl;
	}
}
