#include <stdio.h>
#include <math.h>

#define LEN 32
#define EPS 1E-6

char hom[4][LEN][LEN];
int xy[4][2];
int offset[4][2] = {
	{ -1,  0 },
	{  1,  0 },
	{  0, -1 },
	{  0, +1 },
};

int count_aix ( int H, int W, int D ) {
	int i, j;
	int x, y;
	int images;
	for ( i = images = 0; i < 4; ++i ) {
		for ( j = 1, x = xy[0][0], y = xy[0][1]; ; ++j ) {
			x += offset[i][0];
			y += offset[i][1];
			if ( '#' == hom[0][x][y] ) break;
		}
		if ( j * 2 - 1 <= D ) ++images;
	}
	return images;
}

int check ( char ( *m )[LEN], int nx, int ny, double cx, double cy, double k, double dt ) {
	double dx, dy, kk;
	if ( 'X' != m[nx][ny] ) return 0;
	dx = nx + 0.5 - cx;
	dy = ny + 0.5 - cy;
	kk = dy / dx;
#define ABSDIFF(a,b) ((a)<(b)?(b)-(a):(a)-(b))
	if ( EPS < ABSDIFF ( kk, k ) ) return 0;
	if ( dt - dy < EPS ) return 0;
	return 1;
}

int test ( int h, int H, int W, int dH, int dW, int D ) {
	char ( *m )[LEN];
	double cx, cy, tx, ty, t, mt, k;
	int nx, ny;

	cx = xy[h][0] + 0.5;
	cy = xy[h][1] + 0.5;
	t = 0;
	mt = D / sqrt ( dH * dH + dW * dW ) * dW;
	k = ( double ) dW / ( double ) dH;

	while ( 1 ) {
		m = hom[h];

		nx = floor ( cx + 1 );
		ny = floor ( cy + 1 );

		if ( t && check ( m, nx - 1, ny - 1, cx, cy, k, mt - t ) ) return 1;

		tx = ( nx - cx ) * k;
		ty = ( ny - cy );
		if ( tx < ty ) ty = tx;
		cy += ty, cx += ty / k;
		t += ty;
		if ( mt < t + EPS ) return 0;

		if ( ABSDIFF ( cx, nx ) < EPS ) cx = nx;
		if ( ABSDIFF ( cy, ny ) < EPS ) cy = ny;

		if ( cx == nx && cy != ny ) {
			if ( '#' == m[nx][ny - 1] ) h ^= 0x02, cx = H - cx;
		} else if ( cx != nx && cy == ny ) {
			if ( '#' == m[nx - 1][ny] ) h ^= 0x01, cy = W - cy;
		} else {
			if ( '#' != m[nx][ny] ) {
				continue;
			} else if ( '#' == m[nx][ny - 1] && '#' == m[nx - 1][ny] ) {
				h ^= 0x03, cx = H - cx, cy = W - cy;
			} else if ( '#' != m[nx][ny - 1] && '#' == m[nx - 1][ny] ) {
				h ^= 0x01, cy = W - cy;
			} else if ( '#' == m[nx][ny - 1] && '#' != m[nx - 1][ny] ) {
				h ^= 0x02, cx = H - cx;
			} else {
				return 0;
			}
		}
	}

	return 0;
}

int main ( ) {
	int i, j, k;
	int T, H, W, D, x, images;
	int dH, dW;
	int a, b, m;

	for ( scanf ( "%d", &T ), x = 1; x <= T; ++x ) {
		scanf ( "%d%d%d\n", &H, &W, &D );
		for ( i = 0; i < H; ++i ) {
			for ( j = 0; j < W; ++j ) {
				k = getchar ( );
				hom[0][i][j] = k;
				hom[1][i][W - 1 - j] = k;
				hom[2][H - 1 - i][j] = k;
				hom[3][H - 1 - i][W - 1 - j] = k;
				if ( 'X' == k ) {
					xy[0][0] = i, xy[0][1] = j;
					xy[1][0] = i, xy[1][1] = W - 1 - j;
					xy[2][0] = H - 1 - i, xy[2][1] = j;
					xy[3][0] = H - 1 - i, xy[3][1] = W - 1 - j;
				}
			}
			while ( '\n' != getchar ( ) );
		}
		images = count_aix ( H, W, D );
		for ( dH = 1; dH <= D; ++dH ) {
			for ( dW = 1; dW <= D; ++dW ) {
				for ( a = dH, b = dW; m = a % b; a = b, b = m );
				if ( 1 != b ) continue;
				images += test ( 0, H, W, dH, dW, D );
				images += test ( 1, H, W, dH, dW, D );
				images += test ( 2, H, W, dH, dW, D );
				images += test ( 3, H, W, dH, dW, D );
			}
		}
		printf ( "Case #%d: %d\n", x, images );
	}

	return 0;
}
