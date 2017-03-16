#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int T,N,J;

lld pr( lld x ){
	for(lld i=2; i*i<=x; i++){
		if( x % i == 0 ) return i;
	}
	return 0;
}

lld px[44][11], cp[11], cq[11];
char st[44];

int main(){
	for(int i=2; i<=10; i++) px[0][i] = 1;
	for(int i=1; i<40; i++)
		for(int j=2; j<=10; j++){
			px[i][j] = px[i-1][j] * j;
		}
	scanf("%d%d%d",&T,&N,&J);
	printf("Case #1:\n");
	lld j; int c, k;
	for(lld i=0; i<( 1LL<<(N-1) ) && J; i++){
		j = ( 1LL<<(N-1) ) + i*2 + 1;
		c = 0;
		memset( cp, 0, sizeof cp );
		while( j ){
			if( j & 1 )
				for(k=2; k<=10; k++)
					cp[k] += px[c][k];
			st[c] = '0' + (j&1); j /= 2; c++;
		}
		
		for(k=2; k<=10; k++){
			cq[k] = pr(cp[k]);
			if( cq[k] == 0 ) break;
		}
		if( k==11 ){
			reverse( st, st+N ); st[N] = '\0';
			printf("%s%s ",st,st);
			for(int k=2; k<=10; k++) printf("%lld ",cq[k]);
			printf("\n");
			J--;
		}
		cerr<<J<<"left..\n";
	}
	return 0;
}
