#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
freopen("A-small-attempt0(1).in","r",stdin);
freopen("A-small-attempt0.out","w",stdout);
	int a[210];
	int t,n;
	scanf("%d",&t);
	for(int k = 1; k <= t;  k ++) {
		scanf("%d",&n);
		int sum = 0;
		for(int i = 1; i <= n; i ++) {
			scanf("%d",&a[i]);
			sum += a[i];
		}
		printf("Case #%d:",k);
		for(int i = 1; i <= n; i ++) {
			double ans = 1;
			double eps = 1e-8;
			double lt = 0, rt = 1,mid;
			while(lt + eps <= rt) {
				mid = (lt + rt)/2;
				double sumx = mid;
				for(int j = 1; j <= n; j ++) {
					if(i == j) continue;
					double left = 0, right = 1 - sumx,md,x = -1;
					while(left + eps <= right) {
						md = (left + right) / 2;
						if(a[i] + sum * mid <= a[j] + sum * md) {
							right = md - eps;
							x = md;
						}
						else left = md + eps;
					}
					if(x == -1) {
						sumx = 2;
						break;
					}
					sumx += x;
				}
				if(sumx > 1) {
					rt = mid - eps;
					ans = mid;
				}
				else lt = mid + eps;
			}
			printf(" %.10lf",ans * 100);
		}
		printf("\n");

	}
	return 0;
}


