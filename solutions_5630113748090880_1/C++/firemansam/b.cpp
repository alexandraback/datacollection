#include <bits/stdc++.h>
using namespace std;
int n, tcs, grd[2510];
int main(){
	scanf("%i", &tcs);
	for(int tc=1;tc<=tcs;tc++){
		scanf("%i", &n);
		memset(grd, 0, sizeof grd);
		int a;
		for(int i=0;i<(n*2)-1;i++){
			for(int j=0;j<n;j++){
				scanf("%i", &a);
				grd[a]++;
			}
		}
		printf("Case #%i:", tc);
		for(int i=0;i<2505;i++){
			if(grd[i] % 2 > 0 && grd[i]) printf(" %i", i);
		}
		puts("");
	}
}