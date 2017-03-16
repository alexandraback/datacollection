/*
 * =====================================================================================
 *
 *       Filename:  bullseye.cc
 *
 *    Description:  Bullseye
 *
 *        Version:  1.0
 *        Created:  04/27/2013 03:10:12 AM
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

int main(){
	int T;
	long t,r,k;
	scanf("%d",&T);
	for( int i = 1; i <= T; i++ ) {
		scanf("%ld%ld",&r,&t);
		k = 0;
		while( 1 ){
			long tmp = (r+(k<<1));
			t -= (tmp+1)*(tmp+1) - tmp*tmp;
			//printf("t = %ld\n",t );
			if( t >= 0 )k++;
			else break;
		} 
		printf("Case #%d: %ld\n",i,k);
	}
	return 0;
}
