#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

long long t,tes,i,x,y,z;
long long a[10007],b[10007],c[10007];
long long mem[10007][4][4][4];

long long DP(long long pos, long long udah1, long long udah2, long long udah3) {
	//printf("%d %d %d\n",pos,udah1,udah2);

	if (pos < 0) return 1;
	if (mem[pos][udah1][udah2][udah3] != -1) return mem[pos][udah1][udah2][udah3];

	long long ans = 0;
	
	if (udah3) {
		if (udah1 && udah2) {
			if (c[pos] == 1) {
				if (a[pos] == 1 && b[pos] == 1) ans += DP(pos-1,1,1,1);
				if (a[pos] == 1 && b[pos] == 0) ans += 0;
				if (a[pos] == 0 && b[pos] == 1) ans += 0;
				if (a[pos] == 0 && b[pos] == 0) ans += 0;
				if (a[pos] == 1 && b[pos] == 1) ans += DP(pos-1,0,0,0) + DP(pos-1,1,0,0) + DP(pos-1,0,1,0);
				if (a[pos] == 1 && b[pos] == 0) ans += DP(pos-1,0,1,0) + DP(pos-1,1,1,0);
				if (a[pos] == 0 && b[pos] == 1) ans += DP(pos-1,1,0,0) + DP(pos-1,1,1,0);
				if (a[pos] == 0 && b[pos] == 0) ans += DP(pos-1,1,1,0);
			} else {
				if (a[pos] == 1 && b[pos] == 1) ans += DP(pos-1,0,0,1) + DP(pos-1,1,0,1) + DP(pos-1,0,1,1);
				if (a[pos] == 1 && b[pos] == 0) ans += DP(pos-1,0,1,1) + DP(pos-1,1,1,1);
				if (a[pos] == 0 && b[pos] == 1) ans += DP(pos-1,1,0,1) + DP(pos-1,1,1,1);
				if (a[pos] == 0 && b[pos] == 0) ans += DP(pos-1,1,1,1);
			}
		} else
		if (udah1 && !udah2) {
			if (c[pos] == 1) {
				if (a[pos] == 1 && b[pos] == 1) ans += DP(pos-1,1,0,1);
				if (a[pos] == 1 && b[pos] == 0) ans += DP(pos-1,1,0,1);
				if (a[pos] == 0 && b[pos] == 1) ans += 0;
				if (a[pos] == 0 && b[pos] == 0) ans += 0;
				if (a[pos] == 1 && b[pos] == 1) ans += DP(pos-1,0,0,0) + DP(pos-1,0,0,0) + DP(pos-1,1,0,0);
				if (a[pos] == 1 && b[pos] == 0) ans += DP(pos-1,0,0,0) + DP(pos-1,0,0,0) + DP(pos-1,1,0,0);
				if (a[pos] == 0 && b[pos] == 1) ans += DP(pos-1,1,0,0) + DP(pos-1,1,0,0);
				if (a[pos] == 0 && b[pos] == 0) ans += DP(pos-1,1,0,0) + DP(pos-1,1,0,0);
			} else {
				if (a[pos] == 1 && b[pos] == 1) ans += DP(pos-1,0,0,1) + DP(pos-1,0,0,1) + DP(pos-1,1,0,1);
				if (a[pos] == 1 && b[pos] == 0) ans += DP(pos-1,0,0,1) + DP(pos-1,0,0,1) + DP(pos-1,1,0,1);
				if (a[pos] == 0 && b[pos] == 1) ans += DP(pos-1,1,0,1) + DP(pos-1,1,0,1);
				if (a[pos] == 0 && b[pos] == 0) ans += DP(pos-1,1,0,1) + DP(pos-1,1,0,1);
			}
		} else
		if (!udah1 && udah2) {
			if (c[pos] == 1) {
				if (a[pos] == 1 && b[pos] == 1) ans += DP(pos-1,0,1,1);
				if (a[pos] == 1 && b[pos] == 0) ans += 0;
				if (a[pos] == 0 && b[pos] == 1) ans += DP(pos-1,0,1,1);
				if (a[pos] == 0 && b[pos] == 0) ans += 0;
				if (a[pos] == 1 && b[pos] == 1) ans += DP(pos-1,0,0,0) + DP(pos-1,0,1,0) + DP(pos-1,0,0,0);
				if (a[pos] == 1 && b[pos] == 0) ans += DP(pos-1,0,1,0) + DP(pos-1,0,1,0);
				if (a[pos] == 0 && b[pos] == 1) ans += DP(pos-1,0,0,0) + DP(pos-1,0,1,0) + DP(pos-1,0,0,0);
				if (a[pos] == 0 && b[pos] == 0) ans += DP(pos-1,0,1,0) + DP(pos-1,0,1,0);
			} else {
				if (a[pos] == 1 && b[pos] == 1) ans += DP(pos-1,0,0,1) + DP(pos-1,0,1,1) + DP(pos-1,0,0,1);
				if (a[pos] == 1 && b[pos] == 0) ans += DP(pos-1,0,1,1) + DP(pos-1,0,1,1);
				if (a[pos] == 0 && b[pos] == 1) ans += DP(pos-1,0,0,1) + DP(pos-1,0,1,1) + DP(pos-1,0,0,1);
				if (a[pos] == 0 && b[pos] == 0) ans += DP(pos-1,0,1,1) + DP(pos-1,0,1,1);
			}
		} else
		if (!udah1 && !udah2) {
			if (c[pos] == 1) {
				ans += DP(pos-1,0,0,1);
				ans += 3LL * DP(pos-1,0,0,0);
			} else {
				ans += 3LL * DP(pos-1,0,0,1);
			}
		}
	} else {
		if (udah1 && udah2) {
			if (a[pos] == 1 && b[pos] == 1) ans += DP(pos-1,1,1,0) + DP(pos-1,1,0,0) + DP(pos-1,0,1,0) + DP(pos-1,0,0,0);
			if (a[pos] == 1 && b[pos] == 0) ans += DP(pos-1,1,1,0) + DP(pos-1,0,1,0);
			if (a[pos] == 0 && b[pos] == 1) ans += DP(pos-1,1,1,0) + DP(pos-1,1,0,0);
			if (a[pos] == 0 && b[pos] == 0) ans += DP(pos-1,1,1,0);
		} else
		if (udah1 && !udah2) {
			if (a[pos] == 1 && b[pos] == 1) ans += DP(pos-1,1,0,0) + DP(pos-1,1,0,0) + DP(pos-1,0,0,0) + DP(pos-1,0,0,0);
			if (a[pos] == 1 && b[pos] == 0) ans += DP(pos-1,1,0,0) + DP(pos-1,0,0,0) + DP(pos-1,1,0,0) + DP(pos-1,0,0,0);
			if (a[pos] == 0 && b[pos] == 1) ans += DP(pos-1,1,0,0) + DP(pos-1,1,0,0);
			if (a[pos] == 0 && b[pos] == 0) ans += DP(pos-1,1,0,0) + DP(pos-1,1,0,0);
		} else
		if (!udah1 && udah2) {
			if (a[pos] == 1 && b[pos] == 1) ans += DP(pos-1,0,1,0) + DP(pos-1,0,1,0) + DP(pos-1,0,0,0) + DP(pos-1,0,0,0);
			if (a[pos] == 1 && b[pos] == 0) ans += DP(pos-1,0,1,0) + DP(pos-1,0,1,0);
			if (a[pos] == 0 && b[pos] == 1) ans += DP(pos-1,0,1,0) + DP(pos-1,0,1,0) + DP(pos-1,0,0,0) + DP(pos-1,0,0,0);
			if (a[pos] == 0 && b[pos] == 0) ans += DP(pos-1,0,1,0) + DP(pos-1,0,1,0);
		} else
		if (!udah1 && !udah2) {
			ans += 4 * DP(pos-1,0,0,0);
		}
	}	
	
	//printf("%d %d %d %d : %d\n",pos,udah1,udah2,udah3,ans);
	
	return mem[pos][udah1][udah2][udah3] = ans;
}

int main() {
	scanf("%lld",&t);
	for (tes=1 ; tes<=t ; tes++) {	
		scanf("%lld%lld%lld",&x,&y,&z);
		
		x--;
		y--;
		z--;
		
		for (i=0 ; i<=40 ; i++) {
			a[i] = (x % 2LL); x /= 2LL;
			b[i] = (y % 2LL); y /= 2LL;
			c[i] = (z % 2LL); z /= 2LL;
		}
		

		
		for (i=0 ; i<=40 ; i++) {
			mem[i][0][0][0] = -1;
			mem[i][0][1][0] = -1;
			mem[i][1][0][0] = -1;
			mem[i][1][1][0] = -1;
			mem[i][0][0][1] = -1;
			mem[i][0][1][1] = -1;
			mem[i][1][0][1] = -1;
			mem[i][1][1][1] = -1;
		}
		
		printf("Case #%lld: %lld\n",tes,DP(40,1,1,1));
	}
}