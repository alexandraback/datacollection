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
	int chk[2520] = {};
	int n; scanf("%d", &n);
	for(int i=0;i<n+n-1;i++){
		for(int j=0;j<n;j++){
			int x; scanf("%d", &x);
			chk[x] ^= 1;
		}
	}
	for(int i=1;i<=2500;i++)if(chk[i] == 1)printf("%d ", i);
	puts("");
}

int main(){
	int Tc; scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve(tc);
	}
	return 0;
}