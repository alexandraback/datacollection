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

LL T, m, n, q, w, mi, ma, cnt, s, t, fi, cc, e, r, z, x, an, ans, y;
LL c[1000];

struct aa{
	LL day;
	LL m;
	LL start;
	LL end;
	LL str;
	LL delday;
	LL delmove;
	LL delstr;
};

struct bb{
	LL day;
	LL q, w;
	LL h;
};

bool ss(bb x, bb y){
	return (x.day < y.day);
}

aa a[10000];
bb b[100000];


int main(){
	scanf("%lld", &T);
	for (LL rr = 1; rr <= T; rr++){
		memset(c, 0, sizeof(c));
		printf("Case #%lld: ", rr);
		scanf("%lld", &n);
		for (LL i=0; i<n; i++){
			scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &a[i].day, &a[i].m, &a[i].start, &a[i].end, &a[i].str, &a[i].delday, &a[i].delmove, &a[i].delstr);
			a[i].start += 500;
			a[i].end += 500;
		}
		LL cnt = 0;
		for (LL i=0; i<n; i++){
			for (LL j=0; j<a[i].m; j++){
				b[cnt].day = a[i].day + j*a[i].delday;
				b[cnt].q = a[i].start + j*a[i].delmove;
				b[cnt].w = a[i].end + j*a[i].delmove;
				b[cnt].h = a[i].str + j*a[i].delstr;
				cnt++;
			}
		}
		sort(b, b+cnt, ss);
/*		
		if (rr == 1){
			printf("%lld\n", cnt);
			for (LL i=0; i<cnt; i++)
				printf("%lld %lld %lld %lld\n", b[i].day, b[i].q, b[i].w, b[i].h);
		}
*/		
		LL ans = 0;
		for (LL i=0; i<cnt; i++){
			for (LL j=b[i].q; j<b[i].w; j++)
				if (b[i].h > c[j]){
					ans++;
					break;
				}
			if (i+1<cnt && b[i+1].day != b[i].day){
				for (LL j=i; j>=0; j--){
					for (LL k=b[j].q; k<b[j].w; k++)
						c[k] = max(c[k], b[j].h);
					if (j == 0 || b[j].day != b[j-1].day)
						break;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
