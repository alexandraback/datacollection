#include <iostream>


long long calc_rings (long long _r, long long _t)
{
	long long result = 0;
	int ring = 1;
	long long needed = 2 * _r + 1;
	
	while (_t >= needed) {
		_t -= needed;
		++result; ring += 2;
		needed = 2 * _r + 2 * ring - 1;
	}
	return result;
}


int main()
{
	int T;
	std::cin >> T;
	for (int i = 1; i <= T; ++i) {
		long long r, t;
		std::cin >> r >> t;
		std::cout << "Case #" << i << ": " << calc_rings (r, t) << '\n';
	}

	return 0;
}