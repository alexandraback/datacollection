#include <bits/stdc++.h>
using namespace std;

#define fo(x,y,z) for(int x=y;x<z;x++)
int c, d, v, used[35], dp[35];

int main(){
	int tc;
	scanf(" %d ", &tc);
	fo(z,1,tc+1){
		printf("Case #%d: ", z);
		scanf("%d %d %d", &c, &d, &v);
		fo(i,0,v+1){
			dp[i] = 0;
			used[i] = 0;
		}
		dp[0] = 1;
		fo(i,0,d){
			int a;
			scanf("%d", &a);
			used[a] = 1;
			for(int j=v; j >= 0; j--) if(dp[j] && j+a <= v) dp[j+a] = 1;	  
		}
		int ans = 0;
		fo(i,1,v+1){
			if(!dp[i]){
				ans++;
				for(int j=v; j >= 0; j--) if(dp[j] && j+i <= v) dp[j+i] = 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
