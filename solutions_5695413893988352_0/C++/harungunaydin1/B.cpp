#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define all(x) x.begin(),x.end() 
#define MAXN 20
using namespace std;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
bool check( string str, int x ) {

	for( int i = str.size() - 1; i >= 0; i-- )
	{
		if( str[i] != '?' && x % 10 != str[i] - '0' )
			return false;
		x /= 10;
	}

	return !x;

}
void solve() {

	string str1,str2;
	cin >> str1 >> str2;

	int i,j,res = 10000000 , x , y;
	FOR2(i,1000)
		FOR2(j,1000)
			if( check(str1,i) && check(str2,j) ) {
				int diff = abs(i-j);
				if( diff < res ) {
					res = diff;
					x = i;
					y = j;
				} else if( diff == res ) {

					if( i < x ) {
						x = i;
						y = j;
					} else if( i == x ) {

						if( j < y )
							y = j;

					}

				}


			}
	vector < int > X,Y;
	for( int i = 0; i < str1.size(); i++ , x /= 10 )
		X.push_back(x%10);

	for( int i = 0; i < str2.size(); i++ , y /= 10 )
		Y.push_back(y%10);

	reverse( all(X) );
	reverse( all(Y) );

	for( vector < int > :: iterator it = X.begin(); it != X.end(); ++it )
		printf("%d" , *it );

	printf(" ");

	for( vector < int > :: iterator it = Y.begin(); it != Y.end(); ++it )
		printf("%d" , *it );

	printf("\n");

}
int main()
{
	freopen( "input.txt" , "r" , stdin );
	freopen( "output.txt" , "w" , stdout );
	int T = read() , i;
	FOR(i,1,T) {
		printf("Case #%d: " , i );
		solve();
	}
	return 0;
}
