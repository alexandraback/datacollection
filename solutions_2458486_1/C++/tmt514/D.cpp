#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define SZ(c) ((int)(c).size())

int key[500], K, N, lock[500];
int a[300][300], na[300];
int g[300][300], v[300], opened[300], lst[300][500];
void init() {
	for(int i=1;i<=200;i++) key[i] = 0;
	memset(g, 0, sizeof(g));
	memset(a, 0, sizeof(a));
	memset(v, 0, sizeof(v));
	memset(opened,0,sizeof(opened));
}

bool conntest() {
	int u[305]={}, q[305], qb=0, qe=0;
	for(int i=1;i<=N;i++) if(!opened[i] && key[lock[i]]) { u[i]=1; q[qe++] = i; }
	while(qb<qe) {
		int x = q[qb++];
		for(int i=1;i<=N;i++) if(!opened[i] && g[x][i] && !u[i]) u[q[qe++]=i]=1;
	}
	for(int i=1;i<=N;i++) if(!opened[i] && !u[i]) return false;
	return true;
}

void solve() {
	init();
	scanf("%d%d", &K, &N);
	for(int i=0,x;i<K;i++) { scanf("%d", &x); key[x]++; a[0][x]++; v[x]++; }
	for(int i=1;i<=N;i++) {
		scanf("%d", &lock[i]);
		scanf("%d", &na[i]);
		v[lock[i]]--;
		for(int j=0,x;j<na[i];j++) {
			scanf("%d", &x);
			lst[i][j] = x;
			a[i][x]++;
			v[x]++;
		}
	}
	for(int i=0;i<=N;i++)
		for(int j=1;j<=N;j++)
			if(i!=j && a[i][lock[j]])
				g[i][j] = 1;
	for(int i=1;i<=200;i++) if(v[i]<0) { puts(" IMPOSSIBLE"); fprintf(stderr, " IMPOSSIBLE\n"); return; }
	if(!conntest()) {puts(" IMPOSSIBLE");fprintf(stderr, " IMPOSSIBLE\n");  return;}
	vector<int> ans;
	for(int cnt=1;cnt<=N;cnt++) {
		int success = 0;
		for(int i=1;i<=N;i++) {
			if(opened[i] || key[lock[i]]==0) continue;
			opened[i] = 1;
			--key[lock[i]];
			for(int j=0;j<na[i];j++) ++key[lst[i][j]];
			if(conntest()) {success = 1; ans.push_back(i);break;}
			for(int j=0;j<na[i];j++) --key[lst[i][j]];
			++key[lock[i]];
			opened[i] = 0;
		}
		if(!success) { puts(" IMPOSSIBLE");fprintf(stderr, " IMPOSSIBLE\n");  return; }
	}
	FOR(it, ans) { printf(" %d", *it); }
	FOR(it, ans) { fprintf(stderr, " %d", *it); }
	fprintf(stderr, "\n");
	puts("");
}

int main(void) {
	int T;
	scanf("%d", &T);
	for(int cs=1;cs<=T;cs++) {
		printf("Case #%d:", cs);
		fprintf(stderr, "Case #%d: ", cs);
		solve();
	}
	return 0;
}
