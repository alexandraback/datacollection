#include			<iostream>
#include    		<iomanip>
#include			<string>
using	namespace	std;

#include			<JpMooParaiso/Exceptions.h>
#include			<JpMooParaiso/Arithmetics.h>
using	namespace	JpMooParaiso;

static	int
Comp( const void* pL, const void* pR )
{	return	*(double*)pL == *(double*)pR
	?	0
	:	*(double*)pL < *(double*)pR ? -1 : 1
	;
}

double	naomisOrg[ 1000 ];
double	kensOrg[ 1000 ];
double	naomis[ 1000 ];
double	kens[ 1000 ];
size_t	diffs[ 1000 ];

struct
Case
{	size_t	N;
	size_t	normal_point;
	size_t	deceit_point;
	Case( istream& p )
	:	normal_point( 0 )
	,	deceit_point( 0 )
	{	p >> N;
		for ( size_t i = 0; i < N; i++ ) cin >> naomisOrg[ i ];
		qsort( (void*)naomisOrg, N, sizeof( double ), Comp );
		for ( size_t i = 0; i < N; i++ ) cin >> kensOrg[ i ];
		qsort( (void*)kensOrg, N, sizeof( double ), Comp );

//		cout << "Num:" << N << endl;
//		for ( size_t i = 0; i < N; i++ ) cout << ' ' << naomisOrg[ i ];
//		cout << endl;
//		for ( size_t i = 0; i < N; i++ ) cout << ' '  << kensOrg[ i ];
//		cout << endl;
	}
	
	void
	Normal1()
	{	for ( size_t i = 0; i < N; i++ )
		{	naomis[ i ] = naomisOrg[ i ];
			kens[ i ] = kensOrg[ i ];
		}
	
//cout << endl;
		for ( size_t i = 0; i < N; i++ )
		{	size_t	remain = N - i;
//for ( size_t i = 0; i < remain; i++ ) cout << ' ' << naomis[ i ];
//cout << endl;
//for ( size_t i = 0; i < remain; i++ ) cout << ' ' << kens[ i ];
//cout << endl;
			double	ken = 0;
			for ( size_t j = 0; j < remain; j++ )
			{	if ( kens[ j ] > naomis[ 0 ] )
				{	ken = kens[ j ];
					for ( size_t k = j + 1; k < remain; k++ ) kens[ k - 1 ] = kens[ k ];
					break;
				}
			}
			for ( size_t j = 1; j < remain; j++ ) naomis[ j - 1 ] = naomis[ j ];
			if ( ken == 0 ) normal_point++;
		}
	}
	
	//	とりあえず勝つ
	void
	Deceit1()
	{	for ( size_t i = 0; i < N; i++ )
		{	naomis[ i ] = naomisOrg[ i ];
			kens[ i ] = kensOrg[ i ];
		}
//cout << endl;
		for ( size_t i = 0; i < N; i++ )
		{	size_t	remain = N - i;
//for ( size_t i = 0; i < remain; i++ ) cout << ' ' << naomis[ i ];
//cout << endl;
//for ( size_t i = 0; i < remain; i++ ) cout << ' ' << kens[ i ];
//cout << endl;
			bool win = false;
			for ( size_t j = 0; j < remain; j++ )
			{	if ( naomis[ j ] > kens[ remain - 1 ] )
				{	win = true;
					for ( size_t k = j + 1; k < remain; k++ ) naomis[ k - 1 ] = naomis[ k ];
					deceit_point++;
					break;
				}
			}
			if ( ! win )
			{	for ( size_t j = 1; j < remain; j++ ) naomis[ j - 1 ] = naomis[ j ];
			}
//cout << deceit_point << endl;
		}
	}

	//	負けるとわかってたらチート
	//	その後勝ちに向かう
	void
	Deceit2()
	{	for ( size_t i = 0; i < N; i++ )
		{	naomis[ i ] = naomisOrg[ i ];
			kens[ i ] = kensOrg[ i ];
		}
cout << endl;
		for ( size_t i = 0; i < N; i++ )
		{	size_t	remain = N - i;
for ( size_t i = 0; i < remain; i++ ) cout << ' ' << naomis[ i ];
cout << endl;
for ( size_t i = 0; i < remain; i++ ) cout << ' ' << kens[ i ];
cout << endl;
			if ( naomis[ 0 ] < kens[ 0 ] )
			{	for ( size_t j = 1; j < remain; j++ ) naomis[ j - 1 ] = naomis[ j ];
			}
			else
			{	bool win = false;
				for ( size_t j = 0; j < remain; j++ )
				{	if ( naomis[ j ] > kens[ remain - 1 ] )
					{	win = true;
						for ( size_t k = j + 1; k < remain; k++ ) naomis[ k - 1 ] = naomis[ k ];
						deceit_point++;
						break;
					}
				}
				if ( ! win )
				{	for ( size_t j = 0; j < remain; j++ )
					{	if ( kens[ j ] > naomis[ 0 ] )
						{	for ( size_t k = j + 1; k < remain; k++ ) kens[ k - 1 ] = kens[ k ];
							break;
						}
					}
					for ( size_t j = 1; j < remain; j++ ) naomis[ j - 1 ] = naomis[ j ];
				}
			}
cout << deceit_point << endl;
		}
	}
	
	void
	Solve()
	{	Normal1();
		Deceit1();
	}
	
	void
	Err()
	{
	}
	void
	Out()
	{	cout << ' ' << deceit_point << ' ' << normal_point;
	}
};


void
Main()
{
	cout << fixed << setprecision( 7 );
	cerr << fixed << setprecision( 7 );

	size_t	wNumCases;	cin >> wNumCases;
	for ( size_t i = 1; i <= wNumCases; i++ )
	{	cout << "Case #" << i << ":";
		Case wCase( cin );
		wCase.Solve();
		wCase.Out();
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

