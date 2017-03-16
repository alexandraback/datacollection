/*
 * =====================================================================================
 *
 *       Filename:  guess.cpp
 *
 *    Description:  Guess
 *
 *        Version:  1.0
 *        Created:  04/27/2013 03:58:55 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jan Sebechlebsky (), sebecjan@fit.cvut.cz
 *   Organization:  FIT CTU
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(){
	int T;
	scanf("%d",&T);
	printf("Case #1:\n");
	int R,N,M,K;
	scanf("%d%d%d%d",&R,&N,&M,&K);
	int res[6][6][6];
	int ma,mb,mc;
	while(R--){
		for( int a = 2 ; a <=M ; a++ )
			for( int b = 2; b <= M ; b++) 
				for( int c = 2; c <= M; c++ )
					res[a][b][c] = 0;
		for( int i = 0; i < K; i++ ) {
			int num;
			scanf("%d",&num);
			for( int a = 2; a <= M; a++ )
				for( int b = 2; b <= M; b++ )
					for(int c = 2; c <= M; c++ ) {
						if(num == 1)continue;
						if( num == a*b*c || num == a * b || num == a * c || num == b *c ) {
							if(res[a][b][c]>=0)
							res[a][b][c]++;
						} //else {
							//res[a][b][c] = -1;
						//}
					}
		}
			ma = 2,mb = 2,mc = 2;
			for( int a = 2; a <= M; a++ )
				for( int b = 2; b <=M; b++ )
					for( int c = 2; c <= M; c++) 
					if( res[a][b][c] > res[ma][mb][mc]){
						ma = a;
						mb = b;
						mc = c;
					}
		
		
		printf("%d%d%d\n",ma,mb,mc);

	}	
	return 0;
}
