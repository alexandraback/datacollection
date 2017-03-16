/*
 */
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#define A 26
#define N 0x80
#define oo (1L<<29)
#define tol 1e-9
using namespace std;

int K,L,S,pi[0x400],n,failure[N][A],E;
double p[A],z[N][N][N],e;
char kbd[0x400],t[0x400];

int main() {
	int i,j,k,l,nl,cs = 0,ts;
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	for ( scanf("%d",&ts); ts--; ) {
		printf("Case #%d: ",++cs);
		scanf("%d %d %d",&K,&L,&S);
		scanf("%s %s",kbd,t+1);
		assert( strlen(t+1) == L );
		assert( strlen(kbd) == K );
		memset(p,0,sizeof p);
		for ( i = 0; i < K; ++i )
			p[kbd[i]-'A'] = p[kbd[i]-'A']+1;
		for ( i = 0; i < A; ++i )
			p[i] /= K;

		for ( n = L, pi[0] = -1, pi[1] = 0, i = 2; i <= n; pi[i++] = k+1 ) 
			for ( k = pi[i-1]; k >= 0 && t[i] != t[k+1]; k = pi[k] );

		for ( i = 0; i <= S; ++i )
			for ( j = 0; j <= n; ++j )
				for ( k = 0; k <= S; ++k )
					z[i][j][k] = 0;

		for ( i = 1; i <= n; ++i ) 
			for ( j = 0; j < A; ++j )
				if ( j+'A' != t[i] ) {
					for ( k = pi[i-1]; k >= 0 && t[k+1] != j+'A'; k = pi[k] );
					failure[i][j] = k+1;
				}

		assert( pi[n] < n );

		for ( z[0][0][0] = 1.00, i = 0; i <= S-1; ++i )
			for ( l = 0; l < n; ++l )
				for ( k = 0; k <= S; ++k ) {
					if ( z[i][l][k] < tol )
						continue ;
					for ( j = 0; j < A; ++j )
						if ( p[j] >= tol ) {
							if ( j+'A' == t[l+1] ) {
								if ( l+1 == n )  
									z[i+1][pi[n]][k+1] += p[j]*z[i][l][k];
								else 
									z[i+1][l+1][k] += p[j]*z[i][l][k];
							}
							else {
								nl = failure[l+1][j];
								z[i+1][nl][k] += p[j]*z[i][l][k];
							}
						}
				}
		for ( E = -1, k = S; k >= 0 && E == -1; --k )
			for ( i = 0; i < n && E == -1; ++i )
				if ( z[S][i][k] >= tol ) {
					E = k;
					break ;
				}
		for ( e = 0, k = 0; k <= S; ++k )
			for ( i = 0; i <= n; ++i )
				e += z[S][i][k]*k;
		printf("%.7lf\n",E-e);
	}
    return 0;
}

