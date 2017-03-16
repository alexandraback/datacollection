#include <bits/stdc++.h>
using namespace std;

bool mat[55][55];
int n;
long long temp;

bool checker(){
	long long way[51];
	memset(way,0,sizeof(way));
	way[0]=1;
	for( int i=0 ; i<n ; i++ ){
		for( int j=0 ; j<n ; j++ ){
			if( mat[i][j] ){
				way[j]+=way[i];	
			}
		}
	}
	if( temp!=way[n-1] ) return false;
	return true;	
}

int main(){

	int test,t=0,i,j,k;
	long long m;
	bool can;
	for( scanf("%d",&test) ; test-- ;){
		scanf("%d%lld",&n,&m);
		can = m<=(1LL<<n-2);
		printf("Case #%d: %sPOSSIBLE\n",++t,can?"":"IM");
		
		if( can ){
			memset(mat,0,sizeof(mat));
			for( i=0 ; i<n ; i++ )
				for( j=i+1 ; j+1<n ; j++ )
					mat[i][j]=1;	
			
			temp = m;
			for( i=1 ; m ; m/=2LL,i++ ){
				if( m&1LL ) mat[i][n-1]=1;
			}
			
			// maximum value
			if( mat[n-1][n-1] ){
				mat[n-1][n-1] = 0;
				for( i=0 ; i<n-1 ; i++ ) mat[i][n-1]=1;
			}
			
			for( i=0 ; i<n ; i++ ,putchar(10) ) for( j=0 ; j<n ; j++ ) putchar(mat[i][j]+'0');
			
			assert(checker());
		}
	}
	return 0;
}

