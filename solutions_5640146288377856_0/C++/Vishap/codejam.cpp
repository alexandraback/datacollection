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

std::pair<ll,ll> rec( long r )
{
	if ( r <= 0 )
		return std::make_pair(ll(0),ll(0));

	if ( r == 1 )
		return std::make_pair(ll(1), ll(0));
	
	auto c0 = rec (r+1/2-1);
	auto c1 = rec ( r - (r+1)/2 );

	if ((c0.first-c0.second) > (c1.first-c1.second-1) )
		return std::make_pair(c0.first+1,c0.second);
	else
		return std::make_pair(c1.first+1, c1.second+1);
}

std::pair<ll, ll> rec2(long r)
{
	if (r <= 0)
		return std::make_pair(ll(0), ll(0));

	if (r == 1)
		return std::make_pair(ll(1), ll(0));

	std::pair<ll, ll> m(r+10,0);
	for (int i = 0; i < r; ++i)
	{
		auto c0 = rec(i);
		c0.first++;

		auto c1 = rec(r-i-1);
		c1.first++;
		c1.second++;

		auto m01 = ((c0.first - c0.second) < (c1.first - c1.second)) ?
					c1 : c0;

		if ((m01.first - m01.second) < (m.first - m.second))
			m = m01;
	}
	return m;
}


/*
Problem
*/
ll solve_puzzle()
{
	vec v;
	size_t r, c, w;
	std::cin >> r >> c >> w;

	ll moves = 0;

	moves += r*(c/w);

	if ( w > 1 )
	{
		auto p = rec2(c%w);

		if ( (c/w) > 1 )
		{
			auto q = rec2(w-1);
			q.first--;
			if ((p.first - p.second) < (q.first - q.second))
				p = q;
		}

		moves += p.first + w-1 -p.second;
	}

	return moves;
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
