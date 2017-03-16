#include <bits/stdc++.h>

using namespace std;

int t,tes,n,x;
int a[1000007],ans[1000007];

void BF(int pos, int udah) {
	if (x == 0) return;
	if (pos == n+1) {
		if (udah % 6 == 0) {
			long long i;
			
			for (i=2 ; i<=10 ; i++) {
				if (i % 2 == 1) ans[i] = 2; else
				if (i % 3 == 1) ans[i] = 3; else {
					long long y = 0;
					long long z = 1;
					long long j;
					for (j=n ; j>=1 ; j--) {
						if (a[j] == 1) y += z;
						z *= i;
					}
					j = 2;
					while (y % j != 0 && j < 500) j++;
					if (j >= 500) return;
					ans[i] = j;
				}
			}
			
			for (i=1 ; i<=n ; i++) printf("%d",a[i]);
			for (i=2 ; i<=10 ; i++) printf(" %d",ans[i]);
			printf("\n");
			x--;
		}
		if (x == 0) return;
	} else if (pos == n) {
		a[pos] = 1;
		if (x == 0) return;
		BF(pos+1,udah+1);
		if (x == 0) return;
		a[pos] = 0;
		if (x == 0) return;
	} else {
		a[pos] = 1;
		if (x == 0) return;
		BF(pos+1,udah+1);
		if (x == 0) return;
		a[pos] = 0;
		if (x == 0) return;
		BF(pos+1,udah);
		if (x == 0) return;
	}
}

int main() {
	scanf("%d",&t);
	for (tes=1 ; tes<=t ; tes++) {
		scanf("%d%d",&n,&x);
		printf("Case #%d:\n",tes);
		a[1] = 1;
		BF(2,1);
	}
}