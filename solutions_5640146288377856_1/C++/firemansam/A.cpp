#include<bits/stdc++.h>
using namespace std;
int tcs, ans, r, c, w, grd[100][100], rt;
int main(){
	scanf("%i", &tcs);
	for(int tc=1;tc<=tcs;tc++){
		ans = 0;
		memset(grd, 0, sizeof grd);
		scanf("%i%i%i", &r, &c, &w);
		for(int i=0;i<r;i++){
			for(int j=w-1;j<c;j+=w){
				ans++;
				grd[i][j] = 1;
				rt = max(c - j - 1, 0);
			}
		}
		/*for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				printf("%i", grd[i][j]);
			}
			puts("");
		}*/
		ans += w;
		if (rt==0) ans--;
		printf("Case #%i: %i\n", tc, ans);
	}
}