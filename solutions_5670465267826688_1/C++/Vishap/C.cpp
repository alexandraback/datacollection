/*
VIM: let g:lcppflags="-std=c++11 -O2 -pthread"
VIM: let g:wcppflags="/O2 /EHsc /DWIN32"
*/

#include <assert.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <exception>
#include <stdexcept>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <string>
#include <memory>
#include <functional>
#include <algorithm>
#include <utility>
#include <limits> 
#include <math.h>

typedef long long ll;
typedef std::vector<ll> vec;

/*
Read n values into v
*/
template <class V>
void readv(V& v, int n)
{
	v.reserve(n);
	for (int i = 0; i < n; ++i)
	{
		typename V::value_type e;
		std::cin >> e;
		assert(!std::cin.fail());
		v.push_back(e);
	}
}

/*
Problem
*/

int mul(int a, int b)
{
	static int m[4][4] = {
		{ 1, 2, 3, 4 },
		{ 2,-1, 4,-3 },
		{ 3,-4,-1, 2 },
		{ 4, 3,-2,-1 }
	};
	int r = 1;
	if (a < 0)
	{
		r *= -1;
		a = -a;
	}
	if (b < 0)
	{
		r *= -1;
		b = -b;
	}
	r *= m[a-1][b-1];
	return r;
}

std::string yesno(bool b)
{
	return b ? std::string("YES") : std::string("NO");
}

std::string solve_puzzle()
{
	ll l, x;
	std::string s;
	std::cin >> l >> x >> s;

	int m = 1;
	int n = 1;
	bool I = false;
	bool J = false;
	for (int i = 0; i < x && i < 12; ++i) {
		for (auto c : s) {
			m = mul(m, c - 'g');
			if (!I && m == 2)
				I = true;
			else if (I && !J && m == 4)
				J = true;
		}
		if (i == 0)
			n = m;
	}
	assert(x < 4 || m == 1 || I && J);
	//std::cout << n << ' ';

	if (n == 1)
		return yesno(false);
	else if (n == -1 && x % 2 != 1)
		return yesno(false);
	else if (n != -1 && x % 4 != 2)
		return yesno(false);
	else
		return yesno(I && J);
}

int main(void)
{
	try{
		srand((unsigned)time(NULL));
		int puzzle_count;

		std::cin >> puzzle_count;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		for (int i = 1; i <= puzzle_count; i++)
		{
			std::cout << "Case #" << i << ": ";
			auto r = solve_puzzle();
			std::cout << r << std::endl;
		}

		return 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << std::endl
			<< "std::exception(\"" << e.what() << "\")." << std::endl;
		return 2;
	}
	catch (...)
	{
		std::cerr << std::endl
			<< "unknown exception." << std::endl;
		return 1;
	}
}
