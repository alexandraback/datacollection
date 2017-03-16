#include <bits/stdc++.h>

using namespace std;

int n,t,x,i,j,tes;
bool flag[10007];

int main() {
	scanf("%d",&t);
	for (tes=1 ; tes<=t ; tes++) {
		for (i=0 ; i<=10000 ; i++) flag[i] = false;
		scanf("%d",&n);
		for (i=0 ; i<2*n-1 ; i++) {
			for (j=0 ; j<n ; j++) {
				scanf("%d",&x);
				flag[x] = !flag[x];
			}
		}
		printf("Case #%d:",tes);
		for (i=0 ; i<=10000 ; i++) if (flag[i]) printf(" %d",i);
		printf("\n");
	}
}