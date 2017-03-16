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

int p[1010];
vector <int> v[1010];
int chk[1010];

int dfs(int x){
	int ret = 0;
	for(auto u : v[x]){
		ret = max(ret, dfs(u));
	}
	return ret + 1;
}

void solve(int tc){
	printf("Case #%d: ", tc);
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++)scanf("%d", p+i);
	for(int i=1;i<=n;i++)v[p[i]].pb(i);
	
	int len = 0;
	for(int i=1;i<=n;i++){
		memset(chk, 0, sizeof chk);
		chk[i] = 1;
		int t = i;
		while(1){
			if(chk[p[t]] != 0){
				len = max(len, chk[t] - chk[p[t]] + 1);
				break;
			}
			chk[p[t]] = chk[t] + 1;
			t = p[t];
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(p[p[i]] == i && i < p[i]){
			int j = p[i];
			ans += 2;
			int mx = 0;
			for(auto u : v[i])if(u != j)mx = max(mx, dfs(u));
			ans += mx; mx = 0;
			for(auto u : v[j])if(u != i)mx = max(mx, dfs(u));
			ans += mx;
		}
	}
	printf("%d\n", max(ans, len));
	for(int i=1;i<=n;i++)v[i].clear();
}

int main(){
	int Tc; scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve(tc);
	}
	return 0;
}