#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define all(x) x.begin(),x.end() 
#define MAXN 20
using namespace std;
typedef pair < string , string > pss;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
pss P[MAXN];
int solve() {

	int N,i,j,res(0);

	N = read();

	FOR2(i,N)
		cin >> P[i].f >> P[i].s;

	int K = (1<<N) - 1;
	FOR(i,1,K) {

		map < string , bool > mp1,mp2;

		FOR2(j,N)
			if( !( i & ( 1 << j ) ) ) {
				mp1[ P[j].f ] = true;
				mp2[ P[j].s ] = true;
			}

		FOR2(j,N)
			if( i & ( 1 << j ) )
				if( !mp1[ P[j].f ] || !mp2[ P[j].s ] )
					break;

		if( j == N ) {

			int t = i,s(0);
			while(t) {
				t -= t & -t;
				s++;
			}

			res = max( res , s );

		}

	}
	return res;
}
int main()
{
	freopen( "input.txt" , "r" , stdin );
	freopen( "output.txt" , "w" , stdout );
	int T = read() , i;
	FOR(i,1,T)
		printf("Case #%d: %d\n" , i , solve() );
	return 0;
}
