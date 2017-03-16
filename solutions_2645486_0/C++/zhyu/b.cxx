#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100;
int v[N];
int n,t,r,e,res;

void dfs(int idx, int now, int tot) {
	if(idx == n+1) {
		res = max(res, tot);
		return;
	}
	for(int i=0;i<=now;i++) 
		dfs(idx+1, min(e, now-i+r), tot+v[idx]*i);
}

int main(void) {
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++) {
		scanf("%d%d%d",&e,&r,&n);
		for(int i=1;i<=n;i++) scanf("%d",v+i);
		res = 0;
		dfs(1,e,0);
		printf("Case #%d: %d\n",cas, res);
	}
	return 0;
}
