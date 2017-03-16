#include <bits/stdc++.h>
using namespace std;

long long n, m, pot, cp, licz;
long long dp[10010];
bool mat[100][100], jest;
void czysc()
{

}
void czytaj()
{
	freopen( "B-large (1).in", "r", stdin );
	freopen( "wyj2.txt", "w", stdout );
}
void wypisz( int x )
{
	cerr<<"Case #"<<x<<endl;
//	cerr<<r<<" "<<c<<" "<<w<<endl;
}


int main()
{
	czytaj();
	int ttt;
	cin>>ttt;
	for( int iii = 1; iii <= ttt; iii++ )
	{
		for( int a = 1; a <= 100; a++ )dp[a] = 0;
		for( int a = 1; a <= 60; a++ )for( int b = 1; b <= 60; b++ )mat[a][b] = 0;
		cin>>n>>m;
		cp = n - 2;
		pot = 1;
		jest = 0;
		if( pot >= m )jest = 1;
		for( int a = 1; a <= cp; a++ )
		{
			pot *= 2;
			if( pot >= m )jest = 1;
		}
		if( jest )
		{
//			foo = m;
			dp[1] = 1;
			licz = 0;
			for( int a = 1; a < n; a++ )
			{
				licz++;
				for( int b = 1; b < a; b++ )
				{
					dp[a] += dp[b];
					mat[b][a] = 1;
				}
				if( dp[a] > m )break;
			}
			while( m )
			{
				for( int a = licz; a > 0; a-- )
				{
					if( m >= dp[a] )
					{
						m -= dp[a];
						mat[a][n] = 1;
					}
				}
			}
			cout<<"Case #"<<iii<<": POSSIBLE"<<endl;
			for( int a = 1; a <= n; a++ )
			{
				for( int b = 1; b <= n; b++ )cout<<mat[a][b];
				cout<<endl;
			}
		}
		else
		{
			cout<<"Case #"<<iii<<": IMPOSSIBLE"<<endl;
		}
		
		
		wypisz( iii );
		czysc();
	} 
	return 0;
}
