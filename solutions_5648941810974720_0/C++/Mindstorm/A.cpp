#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector< int > ans;
string s;
int t, i, v, tab[310];

int main()
{
	freopen( "A-small-attempt2.in", "r", stdin );
	freopen( " wyj.txt", "w", stdout ); 
	cin>>t;
	while( t-- )
	{
		++i;
		cin>>s;
		for( int a = 1; a <= 300; a++ )tab[a] = 0;
		for( int a = 0; a < s.size(); a++ )
		{
			tab[ int( s[a] )  ]++;
		}
		v = tab[ int( 'X' ) ];
		for( int a = 1; a <= v; a++ )ans.push_back( 6 );
		tab[ int('S') ] -= v;
		tab[ int('I') ] -= v;
		tab[ int('X') ] -= v; 
	
		v = tab[ int( 'Z' ) ];
		for( int a = 1; a <= v; a++ )ans.push_back( 0 );
		tab[ int('Z') ] -= v;
		tab[ int('E') ] -= v;
		tab[ int('R') ] -= v;
		tab[ int('O') ] -= v;
		
		v = tab[ int( 'W' ) ];
		for( int a = 1; a <= v; a++ )ans.push_back( 2 );
		tab[ int('T') ] -= v;
		tab[ int('W') ] -= v;
		tab[ int('O') ] -= v;
		
		v = tab[ int( 'G' ) ];
		for( int a = 1; a <= v; a++ )ans.push_back( 8 );
		tab[ int('E') ] -= v;
		tab[ int('I') ] -= v;
		tab[ int('G') ] -= v;
		tab[ int('H') ] -= v;
		tab[ int('T') ] -= v;
		
		v = tab[ int( 'H' ) ];
		for( int a = 1; a <= v; a++ )ans.push_back( 3 );
		tab[ int('T') ] -= v;
		tab[ int('H') ] -= v;
		tab[ int('R') ] -= v;
		tab[ int('E') ] -= v;
		tab[ int('E') ] -= v;
		
		v = tab[ int( 'R' ) ];
		for( int a = 1; a <= v; a++ )ans.push_back( 4 );
		tab[ int('F') ] -= v;
		tab[ int('O') ] -= v;
		tab[ int('U') ] -= v;
		tab[ int('R') ] -= v;

		v = tab[ int( 'F' ) ];
		for( int a = 1; a <= v; a++ )ans.push_back( 5 );
		tab[ int('F') ] -= v;
		tab[ int('I') ] -= v;
		tab[ int('V') ] -= v;
		tab[ int('E') ] -= v;
	
		v = tab[ int( 'V' ) ];
		for( int a = 1; a <= v; a++ )ans.push_back( 7 );
		tab[ int('S') ] -= v;
		tab[ int('E') ] -= v;
		tab[ int('V') ] -= v;
		tab[ int('E') ] -= v;
		tab[ int('N') ] -= v;
		
		v = tab[ int( 'O' ) ];
		for( int a = 1; a <= v; a++ )ans.push_back( 1 );
		tab[ int('O') ] -= v;
		tab[ int('N') ] -= v;
		tab[ int('E') ] -= v;
		
		v = tab[ int( 'N' ) ] / 2;
		for( int a = 1; a <= v; a++ )ans.push_back( 9 );
		tab[ int('N') ] -= v;
		tab[ int('I') ] -= v;
		tab[ int('N') ] -= v;
		tab[ int('E') ] -= v;
		
		sort( ans.begin(), ans.end() );
		cout<<"Case #"<<i<<": ";
		for( int a = 0; a < ans.size(); a++ )cout<<ans[a];
		cout<<endl;
		ans.clear();
	}
	return 0;
}
