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

typedef long long i64;
typedef std::vector<i64> vec;
void check( bool b ) { 	if ( !b ) 
	std::cerr << "error" << std::endl; }
#define FOR(i,l) for ( i64 i =0, ie = i64(l); i<ie; ++i )
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


int solve_puzzle()
{
	int a, b, k;
	std::cin >> a >> b >> k;

	int s = 0;
	for ( int i = 0; i < a; i++ )
		for ( int j = 0; j < b; j++ )
			if ( (i&j) < k )
				s++;

	return s;
}

#undef int
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
