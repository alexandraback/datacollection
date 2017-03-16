#include<cstdio>
#include<math.h>
#define PI 4*atan(1.)

#define ll long long
int main() {
	int tc;
	scanf("%d", &tc);
	freopen("out.txt", "w", stdout);
	for(int z = 1;  z <= tc ; z++) {
		ll r, t;
		scanf("%lld%lld", &r, &t);

		ll st = 0, end = 1e18, m;

		while(st <= end) {
			m = (st+end)/2;
			bool chk = true;
			if( t/2/r <= m ) chk = false;
			if( m != 0 && t/2/m <= m ) chk = false;

			if( end == 4 ) {
				int c = 1;
			}
			ll tot = 2*r*m + 2*m*m - m;
			if( tot > t ) chk = false;

			if( chk ) st = m+1;
			else end = m-1;
		}
		while( 2*r*m + 2*m*m - m <= t ) m++;
		printf("Case #%d: %lld\n", z, m-1);
	}
	fclose(stdout);
}