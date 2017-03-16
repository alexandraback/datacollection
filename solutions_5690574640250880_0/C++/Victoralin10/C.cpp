#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair < int, int >
#define mp make_pair
#define pb push_back
#define scan1(_x) scanf("%d", &(_x))
#define scan2(_x,_y) scanf("%d%d", &(_x), &(_y))
#define scan3(_x,_y,_z) scanf("%d%d%d", &(_x), &(_y), &(_z))
#define FOR(_i,_a,_b) for(int (_i) = (_a); (_i) < (_b); (_i)++)
#define SETALL(_M,_v) memset((_M), (_v), sizeof (_M))
#define TEST() puts(" *** LIGERZERO *** ")
#define MAXN 1000
#define MOD 1000000007

using namespace std;

int tc, r, c, m;
int a, b, n;
int fil, col;
char M[MAXN][MAXN+1];

bool valid(){
	if( n == 1 ){
		a = b = 1;
		fil = col = 0;
		return 1;
	}
	
	if( r == 1 || c == 1 ){
		a = 1;
		b = n;
		fil = col = 0;
		if( c == 1 ) swap(a,b);
		return 1;
	}
	
	for(a = 2; a <= r && a*2 <= n; a++ )
		for(b = 2; b <= c && a*b <= n; b++)
				if( a*b == n ) {
					fil = col = 0;
					return 1;
				}
	
	for(a = 2; a <= r && a*2 <= n; a++ )
		for(b = 2; b <= c && a*b <= n; b++){
				int x = n-a*b;
				if( a < r && x < b && x > 1 ) {
					fil = x;
					col = 0;
					return 1;
				}
				if( b < c  && x < a && x > 1){
					col = x;
					fil = 0;
					return 1;
				}
				if( a < r && b < c && x <= a+b ){
					if( x >= 4 ){
						fil = x/2;
						if( fil > b ) fil = b;
						col = x - fil;
						if( col > a ) col = a, fil = x - col;
						return 1;
					}
				}
			}
	return 0;
}

int main(int nargs, char * args[])
{
	//int _inicio = clock();
	
	scan1(tc);
	for(int caso = 1; caso <= tc; caso++){
		scan3(r,c,m);
		n = r*c - m;
		printf("Case #%d:\n", caso);
		if( !valid() ) puts("Impossible");
		else {
			SETALL(M,'*');
			FOR(i,0,a)
				FOR(j,0,b)
					M[i][j] = '.';
			
			FOR(i,0,fil)
				M[a][i] = '.';
			
			FOR(i,0,col)
				M[i][b] = '.';
			
			M[0][0] = 'c';
			FOR(i,0,r)
				M[i][c] = 0;
			FOR(i,0,r)
				printf("%s\n", M[i]);
		}
	}
	
	//printf("\nTime elapsed: %d ms", clock() - _inicio);
}
