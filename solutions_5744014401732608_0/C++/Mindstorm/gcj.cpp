#include <bits/stdc++.h>
using namespace std;

vector< pair< int, int > > s;
bitset< 40 > foo;

int n, m, mat[10][10], dp[10], in[10], met[10], ans, i, ile, j; 
bool jest[100], blad;

void czysc()
{

}
void czytaj()
{
	freopen( "B-small-attempt0 (2).in", "r", stdin );
	freopen( "wyj.txt", "w", stdout );
}
void wypisz( int x )
{
	cerr<<"Case #"<<x<<endl;
//	cerr<<r<<" "<<c<<" "<<w<<endl;
}

void topo( int w )
{
	for( int a = 1; a <= n; a++ )
	{
		if( mat[w][a] )
		{
			dp[a] += dp[w];
			in[a]--;
			if( in[a] == 0 )topo(a);
		}	
	}
}
void dfs( int w )
{
	met[w] = 1;
	jest[w] = 1;
	for( int a = 1; a <= n; a++ )
	{
		if( jest[a] && ( mat[w][a] || mat[a][w] ) )
		{
			blad = 1;
			return;
		}
		else 
		{
			dfs( a );
		} 
	}
	jest[w] = 0;
}
int main()
{
	czytaj();
	int ttt;
	cin>>ttt;
	for( int iii = 1; iii <= ttt; iii++ )
	{
		ans = 0;
		cin>>n>>m;
		i = n * ( n - 1 );
		i /= 2;
		ile = 1;
		for( int a = 1; a <= i; a++ )ile *= 2;
		for( int a = 1; a <= ile; a++ )
		{
			for( int c = 1; c <= n; c++ )for( int d = 1; d <= n; d++ )mat[c][d] = 0;
			for( int c = 1; c <= n; c++ )dp[c] = 0, in[c] = 0;
			foo = a;
			j = 0;
			for( int b = 1; b <= n; b++ )
			{
				for( int c = b + 1; c <= n; c++ )
				{
					mat[b][c] = foo[j];
					++j;
				}	
			}
			dp[1] = 1;
//			dfs( 1 );
//			if( !blad )
//			{
				for( int b = 1; b <= n; b++ )
				{
					for( int c = b + 1; c <= n; c++ )
					{
						if( mat[b][c] == 1 )in[c]++;
					}
				}
				topo( 1 );
//			}	
			if( dp[n] == m )
			{
				cout<<"Case #"<<iii<<": POSSIBLE"<<endl;
				for( int b = 1; b <= n; b++ )
				{
					for( int c = 1; c <= n; c++ )cout<<mat[b][c];
					cout<<endl; 
				}
				ans = 1;
				break;
			}
		}
		if( !ans )cout<<"Case #"<<iii<<": IMPOSSIBLE"<<endl;
		
		
		wypisz( iii );
		czysc();
	} 
	return 0;
}
