#include <fstream>
#include <iostream>
#include <vector>

#define IMPOSSIBLE "RICHARD"
#define POSSIBLE "GABRIEL"

void solve_case()
{
	short X, R, C;
	std::cin >> X;
	std::cin >> R;
	std::cin >> C;

	// loopy shape...
	if(X >= 7)
	{
		std::cout << IMPOSSIBLE;
		return;
	}
	// number of squares
	if( (R * C) % X )
	{
		std::cout << IMPOSSIBLE;
		return;
	}
	
	if(C < R)
	{
		R += C;
		C = R - C;
		R -= C;
	}
	// now C >= R
	
	// any omino should fit
	if( C < X)
	{
		std::cout << IMPOSSIBLE;
		return;
	}
	if( R < ((X+1)/2))
	{
		std::cout << IMPOSSIBLE;
		return;
	}

	if(X == 4)
	{
		if(R < 3) // The Z shape...
		{
			std::cout << IMPOSSIBLE;
			return;
		}
	}
	
	if(X >= 5)
	{
		if(R < 4) // The W and Y shapes...
		{
			std::cout << IMPOSSIBLE;
			return;
		}
	}
	
	std::cout << POSSIBLE;
	return;
}

int main(int argc, char* argv[])
{
	unsigned T;
	
	freopen ("D-small-attempt0.in", "r", stdin);		//input file
	freopen ("D-small-attempt0.out", "w", stdout);		//output file
	std::cin >> T;
	for( int i = 0; i < T; ++i )
	{
		std::cout << "Case #" << i+1 << ": ";
		solve_case();
		std::cout << std::endl;
		
	}
	
	return 0;
}