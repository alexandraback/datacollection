/*
 * By Duck
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

const int N = 50;
int mp[N][N], total, res, dx, dy, n;
double f(int r, int nw) { // r==0 -- slide to l
	int x, y;
	double tmp;
	y = 20;
	x = 20;
	while( y!=0 && !(mp[y-1][x-1]&&mp[y-1][x+1]) ) {
		if( !mp[y-1][x-1] && !mp[y-1][x+1] && !(y>=2?mp[y-2][x]:0) ) {
			y -= 2;
			if( y<0 ) y = 0;
		} else if ( mp[y-1][x-1] ) {
			y -= 1;
			x += 1;
		} else if ( mp[y-1][x+1] ) {
			y -= 1;
			x -= 1;
		} else {
			y -= 1;
			if( r ) 
				x += 1;
			else
				x -= 1;
		}
	}
	mp[y][x] = 1;
//	printf("%d %d\n", x, y);
	if( nw==n ) {
		/*for( int i=0; i<5; i++ ) {
			for( int j=17; j<23; j++ )
				printf("%d ", mp[i][j]);
			puts("");
		}
		puts("");*/
		tmp = 1.0*mp[dy][dx+20];
		mp[y][x] = 0;
		return tmp;
	} else {
		tmp = (f(0, nw+1) + f(1, nw+1))/2;
		mp[y][x] = 0;
		return tmp;
	}
}

int main(){
	int t;
	scanf("%d", &t);
	for( int r=1; r<=t; r++ ) {
		scanf("%d %d %d", &n, &dx, &dy);
		if( dx>=20 || dx<=-20 || dy>=20 || dy<0 )
			printf("Case #%d: %lf\n", r, .0);
		else {
			total = res = 0;
			for( int i=0; i<n; i++ ) for( int j=0; j<n; j++ ) mp[i][j] = 0;
			printf("Case #%d: %lf\n", r, f(0,1));
		}
	}
}

