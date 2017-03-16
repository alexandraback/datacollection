#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

#define ran 1111

int T, n, WTF;
int a[ran];
vector<int> _a[ran];
bool v[ran];
int vv[ran];

void dfs(int x) {
	if(v[x]) return;
	v[x] = true;
	dfs(a[x]);
	for(int i=0;i<_a[x].size();i++)
		dfs(_a[x][i]);
}

int detect(int x, int forbid) {
	int res = 1;
	for(int i=0;i<_a[x].size();i++) {
		int nxt = _a[x][i];
		if(nxt == forbid) continue;
		res = max(res, detect(nxt, x) + 1);
	}
	return res;
}

int solve(int x) {
	dfs(x);
	
	memset(vv, 0, sizeof vv);
	vv[x] = 1;
	int p = a[x], cnt = 2;
	while (!vv[p]) {
		vv[p] = cnt;
		cnt++;
		p=a[p];
	}
	int cycle = cnt-vv[p];
	if(cycle>2) return cycle;
	
	int u = p, v = a[p];
	WTF += detect(u, v) + detect(v, u);
	return 0;
}

int main() {
	scanf("%d",&T);
	for(int _ = 1; _<=T; _++) {
		scanf("%d", &n);
		for(int i=1;i<=n;i++) _a[i].clear();
		for(int i=1;i<=n;i++) {
			scanf("%d", &a[i]);
			_a[a[i]].push_back(i);
		}
		
		int ans = 0;
		WTF = 0;
		memset(v, false, sizeof v);
		for(int i=1;i<=n;i++)
			if (!v[i]) 
				ans = max(ans, solve(i));
		
		printf("Case #%d: %d\n", _, max(ans, WTF));
	}
	
	return 0;
}