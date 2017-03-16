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

int T, m, n, q, w, mi, ma, cnt, s, t, fi, cc, e, r, z, x, an;
double a[1010], b[1010];

int main(){
	scanf("%d", &T);
	for (int rr = 1; rr <= T; rr++){
		printf("Case #%d: ", rr);
		scanf("%d", &m);
		for (int i=0; i<m; i++)
			scanf("%lf", &a[i]);
		for (int i=0; i<m; i++)
			scanf("%lf", &b[i]);
		sort(a, a+m);
		sort(b, b+m);
		q = 0;	cnt = 0;
		for (int i=0; i<m; i++){
			while (q < m){
				if (a[q] > b[i]){
					cnt++;
					q++;
					break;
				}
				q++;
			}
		}
		printf("%d ", cnt);
		cnt = 0; q = m-1;
		for (int i=m-1; i>=0; i--){
			if (a[i] > b[q]){
				cnt++;
			} else 
			q--;		
		}
		printf("%d\n", cnt);
	}
	return 0;
}
