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

int T, m, n, mi, ma, cnt, t, fi, cc, e, r, z, x, an;
int a[300];
double b[300], q, s, w;
int c[300];

int main(){
	scanf("%d", &T);
	for (int rr = 1; rr <= T; rr++){
		printf("Case #%d: ", rr);
		memset(c, 0, sizeof(c));
		scanf("%d", &m);
		double ss = 0, tss;
		for (int i=0; i<m; i++){
			scanf("%d", &a[i]);
			ss += a[i];
		}
		cnt = 0;
		n = m;
		tss = 2 * ss;
		while (cnt < 1000){
			s = tss /(double)(n);
			q = 0;
			for (int i=0; i<m; i++){
				if (c[i] == 0){
					b[i] = (s-a[i]);
				}
			}
			for (int i=0; i<m; i++){
				if (b[i] <= 0 && c[i] == 0){
					b[i] = 0;
					c[i] = 1;
					tss -= a[i];
					n--;				
				}
			}
			cnt++;
		}
		w = 0;
		for (int i=0; i<m; i++)
			w += b[i];
		for (int i=0; i<m; i++)
			printf("%.10f%c", (double)(b[i]*100)/w, i==m-1?'\n':' ');
	}
	return 0;
}
