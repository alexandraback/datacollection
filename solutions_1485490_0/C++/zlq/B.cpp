#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 105;
typedef long long llg;

llg T, n, m, a[4], A[4], b[N], B[N], tb[N], tB[N];
int Case = 0;

int main(){
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld%lld", &n, &m);
		memset(a, -1, sizeof(a));
		memset(A, -1, sizeof(A));
		for(int i = 1; i <= n; i++)  scanf("%lld%lld", &a[i], &A[i]);
		for(int i = 1; i <= m; i++)  scanf("%lld%lld", &b[i], &B[i]);
		llg ans = 0;
		for(int i = 1; i <= m; i++)
			for(int j = i; j <= m; j++) {
				for(int k = 1; k <= m; k++) {
					tb[k] = b[k]; tB[k] = B[k];
				}
				llg xx, sum = 0;
				xx = a[1];
				for(int k = 1; k <= i; k++) {
					if(A[1]==tB[k] && tb[k]>0) {
						llg tt = min(tb[k], xx);
						xx -= tt;
						tb[k] -= tt;
						sum += tt;
					}
				}
				xx = a[2];
				for(int k = i; k <= j; k++) {
					if(xx == -1)  break;
					if(A[2]==tB[k] && tb[k]>0) {
						llg tt = min(tb[k], xx);
						xx -= tt;
						tb[k] -= tt;
						sum += tt;
					}
				}
				xx = a[3];
				for(int k = j; k <= m; k++) {
					if(xx == -1)  break;
					if(A[3]==tB[k] && tb[k]>0) {
						llg tt = min(tb[k], xx);
						xx -= tt;
						tb[k] -= tt;
						sum += tt;
					}
				}
				ans = max(ans, sum);
			}
		printf("Case #%d: %lld\n", ++Case, ans);
	}
	return  0;
}










