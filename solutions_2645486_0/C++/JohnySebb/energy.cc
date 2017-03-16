/*
 * =====================================================================================
 *
 *       Filename:  energy.cc
 *
 *    Description:  Energy
 *
 *        Version:  1.0
 *        Created:  04/27/2013 04:12:11 AM
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
#include <algorithm>

int E,R,N;
int act[100];

int calc( int pos, int en ) {
	if(pos >= N) return 0;
	if( en > E )en = E;
	int res = 0;
	for( int i = 0; i <= en; i++ ) {
		res = std::max(res, act[pos]*i + calc(pos + 1, en - i + R ));	
	}
	return res;
}

int main(){
	int T;
	scanf("%d",&T);
	for( int i = 1; i <= T; i++ ) {
		scanf("%d%d%d",&E,&R,&N);
		for( int j = 0; j < N; j++ )
			scanf("%d",&act[j]);
		printf("Case #%d: %d\n",i,calc(0,E));
	}
	return 0;
}
