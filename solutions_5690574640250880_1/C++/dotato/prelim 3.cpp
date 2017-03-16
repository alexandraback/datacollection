#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){

	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	int test,tc=1,n,m,x,i,j;
	char ans[55][55];
	
	for( scanf("%d",&test) ; test-- ; ){
		scanf("%d%d%d",&n,&m,&x);
		
		
		printf("Case #%d:\n",tc++);
		
		if( x+1==n*m ){
			for( i=0 ; i<n ; ans[i][j]=0, i++ ) for( j=0 ; j<m ; j++ ) ans[i][j]='*';
			ans[n-1][m-1]='c';
			goto end;
		}
		for( i=0 ; i<n ; ans[i][j]=0, i++ ) for( j=0 ; j<m ; j++ ) ans[i][j]='.';
		ans[n-1][m-1]='c';
		
		if( x==0 ) goto end;
		
		if( min(n,m)==1 ){
			if( n==1 ) for( i=0 ; i<x ; i++ ) ans[0][i]='*';
			else for( i=0 ; i<x ; i++ ) ans[i][0]='*';
		}
		else if( min(n,m)==2 ){
			if( x&1 || x+2==n*m ){
				printf("Impossible\n");
				continue;
			}
			x>>=1;
			if( n==2 ) for( i=0 ; i<x ; i++ ) ans[0][i]=ans[1][i]='*';
			else for( i=0 ; i<x ; i++ ) ans[i][0]=ans[i][1]='*';
			
		}
		else{
			if( x+2==n*m || x+3==n*m || x+5==n*m || x+7==n*m ){
				printf("Impossible\n");
				continue;
			}
			
			// leave last 2 row and column empty
			for( i=0 ; i<n-2 ; i++ ){
				for( j=0 ; j<m-2 ; j++ ){
					ans[i][j]='*';
					x--;
					if( x==0 ) goto end;
				}
			}
			
			// fill last 2 column, stop at 3rd last row
			for( i=0 ; x && i<n-3 ; i++ ){
				for( j=1 ; j<=2 ; j++ ){
					ans[i][m-j]='*';
					if( x )	x--;
					else{
						ans[n-3][m-3]='.';
						goto end;
					}
				}
			}
			
			// fill last 2 row, stop at 2nd last row
			for( j=0 ; x && j<m-2 ; j++ ){
				for( i=1 ; i<=2 ; i++ ){
					ans[n-i][j]='*';
					if( x ) x--;
					else{
						ans[n-3][m-3]='.';
						goto end;
					}
				}
			}
			
			// fill last 2 mine
			if( x ) ans[n-3][m-2]=ans[n-3][m-1]='*';
			
			
		}
		
		end:
		for( i=0 ; i<n ; i++ ) puts(ans[i]);
		
	}
	
	return 0;
}

