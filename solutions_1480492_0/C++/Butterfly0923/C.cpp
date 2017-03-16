#include <stdio.h>

#define LEN 64
#define EPS 1E-6
#define INF 1E100

struct c_t {
	int C, S;
	double P;
} cs[LEN];

int main ( ) {
	int T, c;
	int N, i, j, mi;
	char ci;
	double t, dt, mt, ds;

	for ( scanf ( "%d", &T ), c = 1; c <= T; ++c ) {
		printf ( "Case #%d: ", c );
		for ( scanf ( "%d\n", &N ), i = 0; i < N; ++i ) {
			scanf ( "%c%d%lf\n", &ci, &cs[i].S, &cs[i].P );
			cs[i].C = ci == 'R';
		}
		for ( t = 0; ; ) {
			for ( mt = INF, i = 0; i < N; ++i ) {
				for ( j = 0; j < N; ++j ) {
					if ( cs[i].C != cs[j].C ) continue;
					if ( cs[i].S <= cs[j].S ) continue;
					if ( cs[i].P >= cs[j].P ) continue;
					dt =  ( cs[j].P - cs[i].P - 5 ) / ( double ) ( cs[i].S - cs[j].S );
					if ( mt > dt ) mt = dt, mi = i;
				}
			}
			if ( INF == mt ) {
				puts ( "Possible" );
				break;
			}
			for ( i = 0; i < N; ++i ) {
				cs[i].P += cs[i].S * mt;
			}
			t += mt;
			for ( i = 0; i < N; ++i ) {
				if ( i == mi ) continue;
				if ( cs[i].C == cs[mi].C ) continue;
				ds = cs[mi].P - cs[i].P;
				if ( ds < 0 ) ds = -ds;
				if ( ds < 5 + EPS ) break;
			}
			if ( i < N ) {
				printf ( "%.6lf\n", t );
				break;
			}
			cs[mi].C = !cs[mi].C;
		}
	}

	return 0;
}
