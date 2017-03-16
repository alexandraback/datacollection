#include <bits/stdc++.h>

#define sz(z) (int)z.size()
#define fo(i,a,b) for (auto (i) = (a); (i) != (b); (i)++)
#define mp make_pair
#define pb push_back

using namespace std;

int cache[30][30];

int dp (int num, int width) {
	if (cache[num][width] != 0) {
		return cache[num][width];
	}
	if (num == width) {
		cache[num][width] = width;
		return width;
	}
	int me = width+1;
	if (num - width >= width) {
		me = max(me, 1+dp(num-width,width));
	}
	cache[num][width] = me;
	return me;
}

int main() {
	int t;
	scanf("%d\n",&t);
	freopen("brattle.out","w",stdout);
	fo(_,1,t+1) {
		int r,c,w,ans;
		scanf("%d %d %d\n",&r,&c,&w);
		printf("Case #%d: %d\n",_,r*dp(c,w));
		continue;
		if (c-w>=1) {
			ans = c;
		}
		else if (w==1) {
			ans = c;
		}
		else if (w==2) {
			if (c==4) ans = 3;
			if (c==5) ans = 4;
			if (c==6) ans = 4;
			if (c==7) ans = 5;
			if (c==8) ans = 5;
			if (c==9) ans = 6;
			if (c==10) ans = 7;
		} else if (w==3) {
			if (c==5) ans = 4;
			if (c==6) ans = 4;
			if (c==7) ans = 5;

		}
	}

	return 0;
}
