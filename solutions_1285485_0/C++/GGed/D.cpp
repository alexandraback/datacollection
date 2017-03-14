#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define CLR(a,x) memset(a, x, sizeof(a))
using namespace std;

int tc_, n, m, d, xa, xb, ya, yb, x, y, ret, ok, l;
int px[13005], py[13005], pd[13005];
char s[35];

int sgn(int x){
	if (x > 0) return 1;
	if (x < 0) return -1;
	return 0;
}

int main(){
	scanf("%d", &tc_);
	FOE(tc,1,tc_){

		scanf("%d%d%d", &n, &m, &d);
		FOR(i,0,n){
			scanf("%s", s);
			FOR(j,0,m)
			if (s[j] == 'X'){
				xa = i*2 - 1;
				xb = 2*n - 4 - xa;
				ya = j*2 - 1;
				yb = 2*m - 4 - ya;
			}
		}
		
		n -= 2, m -= 2;
		l = 0;
		FOE(i,-50,50)
		FOE(j,-50,50){
			x = (n<<1) * (i/2);
			y = (m<<1) * (j/2);
			if ((i & 1) && i > 0) x += xa;
			if ((i & 1) && i < 0) x -= xb;
			if ((j & 1) && j > 0) y += ya;
			if ((j & 1) && j < 0) y -= yb;
			if ((i || j) && x * x + y * y <= d * d){
				px[l] = x, py[l] = y, pd[l++] = x * x + y * y;
			}
		}
		
		ret = 0;
		FOR(i,0,l){
			ok = 1;
			FOR(j,0,l)
			if (pd[j] < pd[i] && px[i] * py[j] == py[i] * px[j] &&
			sgn(px[i]) == sgn(px[j]) && sgn(py[i]) == sgn(py[j])){
				ok = 0;
				break;
			}
			ret += ok;
		}
		printf("Case #%d: %d\n", tc, ret);
	}
	return 0;
}
