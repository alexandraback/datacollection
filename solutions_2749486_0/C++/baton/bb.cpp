//

#include <stdlib.h>

#include <iostream>
#include <list>


std::string qq( int const xx, int const yy )
{
	int x( xx ), y( yy );
	std::string dx( "WE" ), dy( "SN" );
	if( x < 0 )
	{
		x = -x;
		dx = "EW";
	}
	if( y < 0 )
	{
		y = -y;
		dy = "NS";
	}
	
	std::string r;
	while( x-- )
		r += dx;
	while( y-- )
		r += dy;
		
	return r;
}

int main()
{
	size_t count( 0 );
	std::cin >> count;
	
	for( size_t n( 0 ); n != count; ++n )
	{
		int x( 0 ), y( 0 );
		std::cin >> x >> y;
		
		std::cout << "Case #" << ( n + 1 ) << ": " << qq( x, y ) << std::endl;
	}
	
	return 0;
}
