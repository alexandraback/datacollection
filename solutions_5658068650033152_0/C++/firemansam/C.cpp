#include <bits/stdc++.h>
using namespace std;
int tcs, n, m, k, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int reduce(int x, int y, int k){
	int ct = x * y, s = 1, sv = 0;
	while(ct > k){
		ct -= s;
		if(sv % 4 == 0) s++;
		sv++;
	}
	return sv;
}
int g(int x, int y){
	if(x == 1) return y;
	if(y == 1) return x;
	return max((x * y) - ((x - 2) * (y - 2)), 0);
}
int main(){
	scanf("%i", &tcs);
	for(int tc = 1; tc <= tcs; tc++){
		scanf("%i%i%i", &n, &m, &k);
		int ans = 1<<30;
		/*if(k <= max(n, m)){
			ans = k;
		}else{*/
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(i * j < k) continue;
					///if((i * j) - k > 4) break;
					/*int mp[50][50] = {{0}};
					for(int l=0;l<i;l++){
						for(int g=0;g<j;g++){
							mp[l][g] = 1;
						}
					}
					reduce(i, j, k, mp);*/
					ans = min(ans, g(i, j) - reduce(i, j, k));
					//break;
				}
			}
		//}
		printf("Case #%i: %i\n", tc, ans);
	}
}