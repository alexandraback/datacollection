#include <bits/stdc++.h>
using namespace std;

int T, TC = 1, N;
int memo[1 << 17];
string awal[1005], akhir[1005];
int dp(int bitmask){
	if(memo[bitmask] != -1) return memo[bitmask];
	int ret = 0;
	for(int i = 0; i < N; i++){
		if(!(bitmask & (1 << i))){
			int haha = 0;
			bool ketemuDepan = 0, ketemuBelakang = 0;
			for(int j = 0; j < N; j++){
				if((bitmask & (1 << j)) && awal[i] == awal[j]) ketemuDepan = 1;
			}
			for(int j = 0; j < N; j++){
				if((bitmask & (1 << j)) && akhir[i] == akhir[j]) ketemuBelakang = 1;
			}
			if(ketemuDepan && ketemuBelakang) haha++;
			ret = max(ret, dp(bitmask | (1 << i))+haha);
		}
	}
	return memo[bitmask] = ret;
}
int main(){
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(int i = 0; i < N; i++) cin >> awal[i] >> akhir[i];
		memset((memo), -1, sizeof(memo));		
		int ans = dp(0);
		printf("Case #%d: %d\n", TC++, ans);
	}
	return 0;
}
