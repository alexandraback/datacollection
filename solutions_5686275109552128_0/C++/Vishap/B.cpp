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

ll solve_puzzle()
{
	vec v;
	v.reserve(1000000);
	int d;
	std::cin >> d;
	readv(v, d);

	ll mt = *std::max_element(v.begin(),v.end());	
	for (ll i = mt-1; i; --i)
	{
		ll t = i;
		for (auto e : v)
			t += ((e+i-1)/i)-1;
		mt = std::min(mt, t);
	}

	return mt;
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
