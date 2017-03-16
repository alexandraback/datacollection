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
#include <numeric>
#include <utility>
#include <limits> 
#include <math.h>

/*
Helpers.
*/
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
ll solve_puzzle()
{
	size_t c, d, v;
	vec p;
	std::cin >> c >> d >> v;

	readv(p, d);

	std::sort(p.begin(),p.end());

	ll nc = 0;
	ll cover = 0;

	for (size_t pi = 0; pi < p.size(); pi++)
	{
		if (cover + 1 < p[pi])
		{
			p.insert(p.begin() + pi, cover + 1);
			nc++;
		}

		cover = p[pi] * c + cover;
		if ( cover >= v )
			return nc;
	}

	while (cover < v)
	{
		nc++;
		cover = (cover + 1) * (c + 1) - 1;
	}

	return nc;
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
