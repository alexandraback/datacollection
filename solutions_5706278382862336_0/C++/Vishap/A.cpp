/* Check cf5-opt.vim defs.
VIM: let g:lcppflags="-std=c++11 -O2 -pthread"
VIM: let g:wcppflags="/O2 /EHsc /DWIN32"
VIM: let g:cppflags=g:Iboost.g:Itbb
VIM: let g:ldflags=g:Lboost.g:Ltbb.g:tbbmalloc.g:tbbmproxy
VIM: let g:ldlibpath=g:Bboost.g:Btbb
VIM: let g:argv=""
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
void check( bool b ) { 	if ( !b ) 
	std::cerr << "error" << std::endl; }
#define FOR(i,l) for ( ll i =0, ie = ll(l); i<ie; ++i )
/*
	Read n values into v
*/
template <class V>
void readv( V& v, int n )
{
	v.reserve(n);
	for ( int i = 0; i < n; ++i )
	{
		typename V::value_type e;
		std::cin >> e;
		check( !std::cin.fail() );
		v.push_back(e);
	}
}

ll cd( ll a, ll b )
{
	ll d = a % b;

	if ( d > 0 )
		return cd( b, d );
	else
		return b;
}

std::string solve_puzzle()
{
	ll p, q;
	char s;
	std::cin >> p >> s >> q;

	ll d = ( p > q ) ? cd(p,q) : cd(q,p);
	p /= d;
	q /= d;

	if ( ((q-1)&q) || q > (ll(2) << 40) )
		return "impossible";

	int i = 0;
	for ( ; q > p; q >>= 1, ++i );

	std::stringstream ss;
	ss << i;
	return ss.str();
}

int main ( void )
{try{
	srand((unsigned)time(NULL));
	int puzzle_count;

	std::cin >>	puzzle_count;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	for ( int i = 1; i <= puzzle_count; i++ )
	{
		std::cout << "Case #" << i << ": ";
		auto r = solve_puzzle();
		std::cout << r << std::endl;
	}

	return 0;
}
catch ( const std::exception& e )
{
	std::cerr << std::endl
			<< "std::exception(\"" << e.what() << "\")." << std::endl;
	return 2;
}
catch ( ... )
{
	std::cerr  << std::endl
			<< "unknown exception." << std::endl;
	return 1;
}}
