#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

constexpr long double pi = std::atan(1.L) * 4;

constexpr long double area(long double radius)
{
	return pi * (radius * radius);
}

/**
 * @return The millilitres of paint needed to fill one ring.
 */
constexpr long double paint_for_ring(long double inner_radius)
{
	return (area(inner_radius + 1) - area(inner_radius)) / area(1.L);
}

int main()
{
	int T;
	{
		std::string s;
		std::getline(std::cin, s);
		std::istringstream ss(s);
		ss >> T;
	}
	
	for (int i = 0; i < T; ++i)
	{
		long double r, t;
		{
			std::string s;
			std::getline(std::cin, s);
			std::istringstream ss(s);
			ss >> r >> t;
		}
		
		int n = 0;
		for (;;)
		{
			t -= paint_for_ring(r);
			if (t + .00000000000001L < 0) break;
			++n;
			r += 2;
		}
		
		assert(n);
		std::cout << "Case #" << i + 1 << ": " << n << std::endl;
	}
}
