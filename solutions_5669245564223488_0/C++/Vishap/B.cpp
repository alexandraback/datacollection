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

template <class V>
ll perm( V& v, size_t idx = 0 )
{
	std::vector<int> p(26,0);
	char c = 0;
	for ( int j = 0; j < idx+1; ++j )
	{
		for( auto l : v[j] )
		{
			if ( c != l )
			{
				if ( p[ l-'a' ] )
					return 0;
				else
					p[ l-'a' ] = 1;
				c = l;
			}
		}
	}

	if ( idx == v.size()-1 )
		return 1;

	ll r = 0;
	for( size_t i = idx; i < v.size(); i++ )
	{
		std::swap(v[idx],v[i]);
		r += perm<V>(v,idx+1);
		std::swap(v[idx],v[i]);
	}

	return r;
}

std::string solve_puzzle()
{
	int n;
	std::cin >> n;

	const ll m = 1000000007;

	std::vector<std::string> s;
	readv(s,n);

	std::vector<int> p(26,0);
	for ( auto it = s.begin(); it != s.end(); )
	{
		bool b = true;
		char c = (*it)[0];
		for( auto l : *it )
		{
			if ( c != l )
			{
				b = false;
				break;
			}
		}
		if ( b )
		{
			p[c-'a']++;
			it = s.erase(it);
		}
		else
			++it;
	}

	ll coef = 1;
	for ( int i = 0; i < p.size(); ++i )
	{
		auto r = p[i];

		if ( r > 0 )
		{
			std::string ss;
			ss += char('a'+i);
			s.push_back( ss );
		}
		while( r > 1 )
			coef *= r--;
	}

	/*
	std::vector<int> h;

	char t[26][26] = {};
	
	std::vector<int> rep(26,0);
	for ( auto t : s )
	{
		char c = 0;
		std::vector<int> p(26,0);
		for( auto l : t )
		{
			if ( c != l )
			{
				if ( p[ l-'a' ] )
					return "error";
				else
					p[ l-'a' ] = 1;
				c = l;
			}
		}
		int hh = 0;
		for ( int i = 0; i < p.size(); ++i )
			hh |= p[i] << i;
		if ( (hh-1)
		h.push_back(hh);
	}

	for (
		[&i](std::vector<std::string>& s){
		std::vector<int> p(26,0);
		char c = 0;
		for ( auto& str : s )
		{
			for( auto l : str )
			{
				if ( c != l )
				{
					if ( p[ l-'a' ] )
						return;
					else
						p[ l-'a' ]++;
					c = l;
				}
			}
		}
		i++; 
	});
	*/

	ll i = perm( s );

	std::stringstream ss;
	ss << (i*coef)%m;
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
