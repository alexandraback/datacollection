#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<bitset>
using namespace std;
bitset<40> foo;
map< string, int > mapka1, mapka2, mapka3;
int t, n, i, ans, z, blad, licz;
string s1[100],s2[100];


int main()
{
	freopen( "C-small-attempt1.in", "r", stdin );
	freopen( " wyj.txt", "w", stdout ); 
	cin>>t;
	while( t-- )
	{
//		t--;
		++i;
		cin>>n;
		for( int a = 1; a <= n; a++ )
		{
			cin>>s1[a]>>s2[a];
		}
		z = 1;
		for( int a = 1; a <= n; a++ )z *= 2;
		for( int a = 1; a <= z; a++ )
		{
			foo = a;
			licz = 0;
			mapka1.clear();
			mapka2.clear();
			mapka3.clear();
			blad = 0;
//			ans = 0;
			for( int b = 1; b <= n; b++ )
			{
//				cout<<foo[b-1]<<" ";
				if( foo[b-1] )mapka1[ s1[b] ] = 1, mapka2[s2[b]] = 1, mapka3[ s1[b]+"_"+s2[b] ] = 1, licz++;
			}
//			cout<<endl;
			for( int b = 1; b <= n; b++ )
			{
				if( !foo[b-1] )
				{
					if( mapka1[s1[b]] == 1 && mapka2[s2[b]] == 1 && mapka3[s1[b]+"_"+s2[b]] != 1 )
					{
						blad = 0;
					}
					else
					{
//						cout<<a<<" "<<b<<endl;
						blad = 1;
						break;
					}
				}
			}
			if( !blad )
			{
//				cout<<a<<" "<<licz<<endl;
				ans = max( ans, n - licz );
//				cout<<ans<<endl;
			}
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
		ans = 0;
	}
	return 0;
}
