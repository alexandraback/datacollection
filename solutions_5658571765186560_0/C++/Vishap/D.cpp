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
	return b ? std::string("RICHARD") : std::string("GABRIEL");
}

std::string solve_puzzle()
{
	ll x, r, c;
	std::cin >> x >> r >> c;

	if (r > c)
		std::swap(r, c);

	if ((r*c) % x != 0)
		return yesno(true);
	else if (x > c)
		return yesno(true);

	else if (x == 1)
		return yesno(false);
	else if (x == 2)
		return yesno(false);
	
	else if (x == 3 && r <= 1 )
		return yesno(true);
	else if (x == 3)
		return yesno(false);
	
	else if (x == 4 && r <= 2)
		return yesno(true);
	else if (x == 4)
		return yesno(false);

	else if (x == 5 && r <= 2)
		return yesno(true);
	else if (x == 5 && r == 3 && c == 5 )
		return yesno(true);
	else if (x == 5 )
		return yesno(false);

	else if (x == 6 && r <= 3)
		return yesno(true);
	else if (x == 6)
		return yesno(false);

	else //if (x >= 7)
		return yesno(true);
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
