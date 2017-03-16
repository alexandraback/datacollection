#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int dig[100];

void output(int pos){
	for(int i = 2; i <= 10; ++i){
		int res = 0;
		for(int j = pos; ~j; --j){
			res = res * i + dig[j];
		}
		printf(" %d", res);
	}
	puts("");
}

void solve(int n, int m){
	memset(dig, 0, sizeof(dig));
	dig[0] = dig[n - 1] = 1;
	for(int i = 1; m; ++i){
		int up = i - 1;
		dig[i] = dig[n - 1 - i] = 1;
		for(int j = 0; j < (1 << up) && m; ++j, --m){
			for(int k = 0; k < up; ++k){
				if(j >> k & 1){
					dig[1 + k] = 1;
					dig[n - i + k] = 1;
				}
				else{
					dig[1 + k] = 0;
					dig[n - i + k] = 0;
				}
			}
			for(int k = n - 1; ~k; --k) printf("%d", dig[k]);
			output(i);
		}
	}
}

int main(){
//	freopen("out_c.txt", "w", stdout);
	int T, N, J, cases = 0;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &J);
		printf("Case #%d:\n", ++cases);
		solve(N, J);
	}
	return 0;
}
