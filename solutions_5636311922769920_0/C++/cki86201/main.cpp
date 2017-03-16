#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()

void solve(int tc){
	printf("Case #%d: ", tc);
	int K, C, S; scanf("%d%d%d", &K, &C, &S);
	if(S * C < K){
		printf("IMPOSSIBLE\n");
		return;
	}
	for(int i=0;i<(K+C-1)/C;i++){
		ll a = 0;
		for(int j=0;j<C;j++){
			int k = min(i * C + j, K-1);
			a = a * K + k;
		}
		printf("%lld ", a+1);
	}
	puts("");
}

int main(){
	int Tc; scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve(tc);
	}
	return 0;
}