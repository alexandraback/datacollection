#include <cstdio>
#include <cstring>
#include <algorithm>

bool adj[60][60];

char zip[60][10];
int idx[60];
int N, M;
int ord[60];
bool vis[60];
bool over;
bool suc;
int ni;

void dfs (int now) {
	if (suc == true) return;
	if (ni == N) {
		suc = true;
		return;
	}
	//printf("from %d to %d\n", now, ord[ni]);
	//printf("  ni %d\n", ni);	
	//getchar();
	while (adj[now][ord[ni]] == true && suc != true) {
		ni++;
		dfs(ord[ni-1]);
	}
}
	
void chk () {
	
	/*for (int i = 0 ; i < N ; i++) {
		printf("%d ", ord[i]);
	}
	printf("\n");
	
	printf ("x\n");
	*/
	suc = false;
	ni = 1;
	dfs(ord[0]);
	if (suc == true) {
		over = true;
		for (int i = 0 ; i < N ; i++) {
			printf("%s", zip[ord[i]]);
		}
		printf("\n");
	}
	return;
}

void per (int dep) {
	if (over == true) return;
	if (dep == N) {
		chk();
		return;
	}
	for (int i = 0 ; i < N ; i++) {
		if (vis[i] == false) {
			vis[i] = true;
			ord[dep] = idx[i];
			per(dep+1);
			vis[i] = false;
		}
	}
}

bool cmp (int ida, int idb) {
	return strcmp(zip[ida], zip[idb]) < 0;
}

void init () {
	memset(adj, false, sizeof(adj));
	for (int i = 0 ; i < 60 ; i++) {
		idx[i] = i;
	}
	over = false;
	memset(vis, false, sizeof(vis));
}

int main () {
	int T;
	int tt = 1;
	scanf("%d", &T);
	while (T--) {
		init();
		scanf("%d%d", &N, &M);
		for (int i = 0 ; i < N ; i++) {
			scanf("%s", zip[i]);
		}
		for (int i = 0 ; i < M ; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			adj[a-1][b-1] = true;
			adj[b-1][a-1] = true;
		}
		std::sort(idx, idx+N, cmp);	
		
		/*for (int i = 0 ; i < N ; i++) {
			printf("%s\n", zip[idx[i]]);
		}*/
		printf("Case #%d: ", tt);
		tt++;
		per(0);
	}
	return 0;
}
