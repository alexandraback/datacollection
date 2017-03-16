#include <cstdio>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>

	using namespace std ;

string TypeToString( int tValue )
{
	stringstream stringStream ;
	stringStream << tValue ;

	return stringStream.str() ;
}

map< int, string >check ;
bool Find( vector<int> list, int index, int c_sum, string slist )
{
	//printf( "%s\n", slist.c_str() ) ;
	for ( int i = index ; i < list.size() ; i++ )
	{
		if ( check.find( c_sum + list[i] ) != check.end() )
		{
			printf( "%s\n", check[ c_sum + list[i] ].c_str() ) ;
			printf( "%s %d\n", slist.c_str(), list[i] ) ;

			return true ;
		}
		else
		{
			string sTarget = slist.size() == 0 ? TypeToString( list[i] ) : slist + " " + TypeToString( list[i] ) ;
			check[ c_sum + list[i] ] = sTarget ;

			bool result = Find( list, i + 1, c_sum + list[i], sTarget );

			if ( result )
				return true ;
		}
	}

	return false ;
}

int main()
{
	freopen( "C-small-attempt0.in", "r", stdin ) ;
	freopen( "output.txt", "w", stdout ) ;

	int T ;
	cin >> T ;

	for ( int n = 1 ; n <= T ; n++ )
	{
		int r ;
		cin >> r ;


		vector<int> list ;
		for ( int i = 0 ; i < r ; i++ )
		{
			int number ;
			cin >> number ;
			list.push_back( number ) ;
		}

		check.clear() ;

		printf( "Case #%d: \n", n ) ;
		bool result = Find( list, 0, 0, "" ) ;

		if ( !result )
			printf( "Impossible\n" ) ;

	}


	return 0 ;
}