//
//  main.cpp
//  MagicTric
//
//  Created by Satoru Ogura on 2014/04/12.
//
//

#include			<iostream>
#include    		<iomanip>
#include			<string>
using	namespace	std;

#include			<JpMooParaiso/Exceptions.h>
#include			<JpMooParaiso/Arithmetics.h>
using	namespace	JpMooParaiso;

struct
Case
{	double	c;
	double	f;
	double	x;
	
	Case()
	{	cin >> c;	//	cerr << c << endl;
		cin >> f;	//	cerr << f << endl;
		cin >> x;	//	cerr << x << endl;
	}
	
	double
	Solve() const
	{	double	slant = 2;
		double	bias = 0;
		double	estimate = x / slant + bias;
		while ( true )
		{	double	newSlant = slant + f;
			double	newBias = bias + c / slant;
			double	newEstimate = x / newSlant + newBias;
			if ( estimate < newEstimate ) return estimate;
			slant = newSlant;
			bias = newBias;
			estimate = newEstimate;
		}
	}
};

void
Main()
{
	cout << fixed << setprecision( 7 );
	cerr << fixed << setprecision( 7 );

	size_t	wNumCases;	cin >> wNumCases;
	for ( size_t i = 1; i <= wNumCases; i++ )
	{	cout << "Case #" << i << ": ";
		cout << Case().Solve();
		cout << endl;
	}
}

int
main( int argc, const char * argv[] )
{	N( freopen( argv[ 1 ], "r", stdin ) );
	N( freopen( argv[ 2 ], "w", stdout ) );
	Main();
	return 0;
}

