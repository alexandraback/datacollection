#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;

#define S second
#define F first
#define mp make_pair
typedef pair<int, int> PII;
#define pb push_back
typedef long long ll;
const int INF = 2147483647;

const int N = 2010;

int n, fri[N], pick[N], vis[N], ans;

bool check(int stp){
	for(int i = 0; i < stp; ++i) {
		int ok = 0;
		if(fri[pick[i]]!=pick[(i+1)%stp] && fri[pick[i]] != pick[(i-1+stp)%stp]) return 0;
	}
	return 1;
}

void ran(int stp){
	if(stp > 0){
		if(check(stp))ans = max(ans, stp);
		if(stp == n) return;
	}
	for(int i = 1; i <= n; ++i) if(!vis[i]){
		pick[stp] = i;
		vis[i] = 1;
		ran(stp+1);
		vis[i] = 0;
	}
}

int main () {
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; ++tt){
		cin >> n;
		for(int i = 1; i <= n; ++i) scanf("%d", fri+i);
		ans = 1;
		memset(vis, 0, sizeof(vis));
		ran(0);
		printf("Case #%d: %d\n", tt, ans);
	}
}