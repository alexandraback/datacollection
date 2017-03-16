#include <fstream>
#include <iostream>
//#include <algorithm>
//#include <stdlib.h>
//#include <vector>
//#include <string>
#include <stdio.h>
//#include <utility>


int main(int argc, char* argv[])
{
    int T, y, elf;
	long long unsigned P, Q, nod, tP, tQ;
	
	if( argc == 3 )
	{
		freopen (argv[1], "r", stdin);
		freopen (argv[2], "w", stdout);
	}
	else
	{
		std::cout << "Usage:" << std::endl;
		std::cout << "\t" << argv[0] << " <input> <output>" << std::endl;
		return 0;
	}
    std::cin >> T;
    for( int x = 0; x < T; ++x )
	{
//		std::cerr << x+1 << std::endl;
		scanf("%llu/%llu", &P, &Q);
//		std::cin >> P;
//		std::cin >> Q;
//		std::cerr << P << " " << Q << std::endl;

		tP = P;
		tQ = Q;
		while( tP && tQ )
		{
			if( tP > tQ )
			{
				tP %= tQ;
			}
			else
			{
				tQ %= tP;
			}
		}
//		std::cerr << tP << " " << tQ << std::endl;
		if( tP > tQ )
		{
			tQ = tP;
		}
		else
		{
			tP = tQ;
		}
		
		P /= tP;
		Q /= tQ;
		y = 0;
		elf = 0;
		while( !(Q % 2) )
		{
			y++;
			Q /= 2;
			if( (P >= Q) && !(elf) )
			{
				elf = y;
			}
		}
		y = elf;
		if( Q == 1 )
			std::cout << "Case #" << x+1 << ": " << y << std::endl;
		else
			std::cout << "Case #" << x+1 << ": " << "impossible" << std::endl;
	}
	
    return 0;
}