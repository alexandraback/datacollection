#include <iostream>
#include <fstream>
using namespace std;

ifstream fin( "b.in" , ios::in );
ofstream fout( "ans.out" , ios::out );

int calc( int act[] , int m , int n , int e , int r , int E )
{
	if ( m == n ) return 0;
	int i;
	int k, ngain;
	ngain = calc( act , m + 1 , n , ( e + r > E ? E : e + r ) , r , E );
	for ( i = 1 ; i <= e ; ++i )
	{
		k = i * act[m] + calc( act , m + 1 , n , ( e - i + r > E ? E : e - i + r ) , r , E );
		if ( k > ngain )
			ngain = k;
	}

	return ngain;
}

int main()
{
	int k, t;
	int act[11];
	int e, r, n;
	int i;

	fin >> t;
	k = 1;
	while ( k <= t )
	{
		fin >> e >> r >> n;
		for ( i =  0 ; i < n ; ++i )
			fin >> act[i];
		fout << "Case #" << k++ << ": " << calc( act , 0 , n , e , r , e ) << endl;
	}

	return 0;
}
