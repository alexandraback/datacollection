#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#define eps 1e-8
#define oo 1<<29
#define LL long long

using namespace std;

LL T, m, n, mi, ma, cnt, t, fi, cc, e, r, z, x, an, q, w, s;

struct aa{
	LL x, y;
};

LL dp[200][200];
aa a[200], b[200];

LL query(int x, int y, int type){
	LL re = 0;
	for (int i=x; i<y; i++)
		if (b[i].y == type)
			re += b[i].x;
	return re;
}


int main(){
	scanf("%lld", &T);
	for (int rr = 1; rr <= T; rr++){
		printf("Case #%d: ", rr);
		scanf("%lld%lld", &n, &m);
		for (int i=0; i<n; i++)
			scanf("%lld%lld", &a[i].x, &a[i].y);
		for (int i=0; i<m; i++)
			scanf("%lld%lld", &b[i].x, &b[i].y);
		if (n == 1){
			printf("%lld\n", min(a[0].x, query(0, m, a[0].y)));
		}else if (n == 2){
			an = 0; q = 0;
			if (a[0].y == a[1].y){
				printf("%lld\n", min(a[0].x + a[1].x, query(0, m, a[0].y)));
				return 0;
			}
			for (int i=0; i<=m; i++){
				for (int j=i; j<=m; j++){
					q = query(i, j, a[0].y);
					w = query(j, m, a[1].y);
					s = min(q, a[0].x) + min(w, a[1].x);
					an = max(an, s);
				}
			}
			printf("%lld\n", an);
		}else if (n == 3){
			an = 0; q = 0;
			if (a[0].y == a[1].y && a[1].y == a[2].y)
				an =  min(a[0].x + a[1].x + a[2].x, query(0, m, a[0].y));
			else if (a[0].y == a[1].y){
				for (int i=0; i<=m; i++){
					for (int j=i; j<=m; j++){
						q = query(i, j, a[0].y);
						w = query(j, m, a[2].y);
						s = min(q, a[0].x + a[1].x) + min(w, a[2].x);
						an = max(an, s);
					}
				}
			}
			else if (a[1].y == a[2].y){
				for (int i=0; i<=m; i++){
					for (int j=i; j<=m; j++){
						q = query(i, j, a[0].y);
						w = query(j, m, a[2].y);
						s = min(q, a[0].x) + min(w, a[2].x + a[1].x);
						an = max(an, s);
					}
				}
			}
			else if (a[0].y == a[2].y){
				an =  min(a[0].x + a[2].x, query(0, m, a[0].y));
			}
			for (int i=0; i<=m; i++){
				for (int j=i; j<=m; j++){
					for (int k=j; k<=m; k++){
						q = query(i, j, a[0].y);
						w = query(j, k, a[1].y);
						e = query(k, m, a[2].y);
						s = min(q, a[0].x) + min(w, a[1].x) + min(e, a[2].x);
						an = max(an, s);
					}
				}
			}
			printf("%lld\n", an);			
		}
	}
	/*		
				q = 0;
				for (int i=1; i<n; i++){
				if (b[i].y == a[0].y)
				dp[i][0] = min(a[0].x, b[i].x);
				}
				for (int i=1; i<n; i++){
				for (int j=1; j<m; j++){
				dp[i][j] = dp[i][j-1];
				}
				}
	 */
	return 0;
}
