#include <algorithm>
#include <cstdio>
#include <cstring>

#define LEN 1024

using namespace std;

struct l_t {
	l_t ( int l1 = 0, int l2 = 0, int i = 0 ) : l1 ( l1 ), l2 ( l2 ), i ( i ) { }
	int l1, l2, i;
	bool operator < ( l_t const & r ) const {
		return l2 < r.l2;
	}
} l[LEN];

int lv[LEN];

int main ( ) {
	int T, c;
	int N, i, j, s, y;

	for ( scanf ( "%d", &T ), c = 1; c <= T; ++c ) {
		for ( scanf ( "%d", &N ), i = 0; i < N; ++i ) {
			scanf ( "%d%d", &l[i].l1, &l[i].l2 );
			l[i].i = i;
		}
		sort ( l + 0, l + N );
		memset ( lv, 0x00, sizeof ( int ) * N );
		for ( s = y = i = 0; i < N; ) {
			if ( l[i].l2 <= s ) {
				if ( lv[l[i].i] != 2 ) {
					s += 2 - lv[l[i].i];
					lv[l[i].i] = 2;
					++y;
				}
				++i;
				continue;
			}
			for ( j = N - 1; j >= i; --j ) {
				if ( l[j].l1 <= s && lv[l[j].i] == 0 ) break;
			}
			if ( j < i ) break;
			lv[l[j].i] = 1;
			++s, ++y;
		}
		printf ( "Case #%d: ", c );
		if ( i < N ) puts ( "Too Bad" );
		else printf ( "%d\n", y );
	}

	return 0;
}
