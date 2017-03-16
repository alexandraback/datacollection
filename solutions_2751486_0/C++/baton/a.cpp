//

#include <stdlib.h>

#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <memory>


inline bool is_wowel( char const c )
{
	if( c == 'a')
		return true;
	if( c == 'e')
		return true;
	if( c == 'i')
		return true;
	if( c == 'o')
		return true;
	if( c == 'u')
		return true;
		
	return false;
}


int qq( std::string const & s, size_t const n )
{
	//std::cout << s << ' ' << n << std::endl;
	std::set< std::pair< size_t, size_t > > ss;
	
	size_t l( 0 );
	for( std::string::const_iterator i( s.begin() ), i_end( s.end() ); i != i_end; ++i )
		if( is_wowel( *i ) )
			l = 0;
		else
		{
			++l;
			if( l > n )
				l = n;
			if( l == n )
			{
//				std::cout << std::string( i - n + 1, i + 1 ) << std::endl;
				for( std::string::const_iterator j( s.begin() ), j_end( i - n + 2 ); j != j_end; ++j )
					for( std::string::const_iterator k( i ), k_end( s.end() ); k != k_end; ++k )
//						std::cout << std::string( j, k + 1 ) << std::endl;
						ss.insert( std::make_pair( j - s.begin(), k - i ) );
			}
		}
	
	return ss.size();
}

int main()
{
	size_t count( 0 );
	std::cin >> count;
	
	for( size_t n( 0 ); n != count; ++n )
	{
		std::string s;
		size_t num( 0 );
		std::cin >> s >> num;
		
		std::cout << "Case #" << ( n + 1 ) << ": " << qq( s, num ) << std::endl;
	}
	
	return 0;
}
