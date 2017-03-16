#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int solveSmall(int A, int B, int K){
	int res = 0;
	for(int i=0;i<A;i++){
		for(int j=0;j<B;j++){
			if((i&j) < K) res++;
		}
	}
	return res;
}

long long solveLarge(int A, int B, int K){
	long long dp[2][2][2][2];
	memset(dp, 0, sizeof(dp));
	dp[0][1][1][1] = 1;
	for(int i=30;i>=0;i--){
		int cur = i%2, next = 1-cur;
		memset(dp[next], 0, sizeof(dp[next]));
		for(int smallA=0;smallA<2;smallA++){
			for(int smallB=0;smallB<2;smallB++){
				for(int smallK=0;smallK<2;smallK++){
					if(dp[cur][smallA][smallB][smallK] == 0) continue;
					for(int a=0;a<2;a++){
						if(smallA && !(A&(1<<i)) && a == 1) continue;
						int nA = smallA ? ((A>>i)&1) == a : 0;
						for(int b=0;b<2;b++){
							if(smallB && !(B&(1<<i)) && b == 1) continue;
							int nB = smallB ? ((B>>i)&1) == b : 0;
							if(smallK && !(K&(1<<i)) && a == 1 && b == 1) continue;
							int nK = smallK ? ((K>>i)&1) == (a&b) : 0;
							dp[next][nA][nB][nK] += dp[cur][smallA][smallB][smallK];
						}
					}
				}
			}
		}
	}
	return dp[1][0][0][0];
}

int main(){
	int T; cin >> T;
	for(int test=1;test<=T;test++){
		int A, B, K; cin >> A >> B >> K;
		printf("Case #%d: %lld\n", test, solveLarge(A, B, K));
	}
}
