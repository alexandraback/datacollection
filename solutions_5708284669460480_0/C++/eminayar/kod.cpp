#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>

using namespace std;

double dn[110][110][110];
int ar[27],F[110];
int T,N,M,K;
string s;

double f( int a , int b , int c ){
	if( c < 0 ) return 0;
	if( a == K+1 && !c ) return 1;
	if( a == K+1 ) return 0;
	if( dn[a][b][c] != -1 ) return dn[a][b][c];
	double ret=0;
	for( int i=0 ; i<=25 ; i++ ) if( ar[i] ){
		int t=b;
		if( t == M ) t=F[t];
		while( t && s[t+1]-'A' != i ) t=F[t];
		if( s[t+1]-'A' == i ) t++;
		ret=ret+((double)ar[i]/(double)N)*f( a+1 , t , c-(t==M) );
	}
	return dn[a][b][c]=ret;
}

int main(){

	cin >> T;

	for( int z=1 ; z<=T ; z++ ){
		memset( ar , 0 , sizeof ar );
		memset( F , 0 , sizeof F );
		cin >> N >> M >> K;
		for( int i=1 ; i<=N ; i++ ){
			char c; 	scanf(" %c",&c);
			ar[c-'A']++;
		}
		cin >> s;
		s=" "+s+"#";
		F[1]=0;
		int ff=0;
		for( int i=1 ; i<=M ; i++ ) if( !ar[s[i]-'A'] ) ff=1;
		if( ff ){
			printf("Case #%d: 0.0000000000\n",z);
			continue;
		}
		for( int i=2,f=0 ; i<=M ; i++ ){
			while( f && s[f+1] != s[i] ) f=F[f];
			if( s[f+1] == s[i] ) F[i]=f+1,f++;
			else F[i]=f;
		}
		int Q=M-F[M];
		Q=1+(K-M)/Q;
		if( M > K ) Q=0;
		if( !Q ){
			printf("Case #%d: 0.0000000000\n",z);
			continue;
		}
		double res=0;
		for( int i=0 ; i<=K ; i++ )
			for( int j=0 ; j<=M ; j++ )
				for( int k=0 ; k<=Q ; k++ ) dn[i][j][k]=-1;
		for( int i=1 ; i<=Q ; i++ ){
			res=res+i*f( 1 , 0 , Q-i );
		}
		printf("Case #%d: %.10lf\n",z,res);
	}

	return 0;
}