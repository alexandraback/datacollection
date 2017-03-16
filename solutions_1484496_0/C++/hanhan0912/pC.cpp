#include <cstdio>

int n, fail, nx, ny, sx, sy, x[600], y[600], p[600];

void dfs(int cur){
	if (sx == sy && nx && ny){
		fail = false;
		printf("%d", x[0]);
		for (int i = 1; i < nx; i++) printf(" %d", x[i]);
		puts("");
		printf("%d", y[0]);
		for (int i = 1; i < ny; i++) printf(" %d", y[i]);
		puts("");
		return ;
	}
	if (cur >= n) return ;
	int done = false, d2 = false;
	if (nx && ny){
		dfs(cur + 1);
		d2 = 1;
	}
	if (nx && !ny){
		y[ny++] = p[cur];
		sy += p[cur];
		dfs(cur + 1);
		sy -= p[cur];
		ny--;
		done = 1;
		if (!fail) return ;
	}
	x[nx++] = p[cur];
	sx += p[cur];
	dfs(cur + 1);
	sx -= p[cur];
	nx--;
	if (!fail) return ;
	if (!done){
		y[ny++] = p[cur];
		sy += p[cur];
		dfs(cur + 1);
		sy -= p[cur];
		ny--;
		if (!fail) return ;
	}
	if (!d2)
		dfs(cur + 1);
}
void solve(){
	fail = true;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);
	sx = sy = 0;
	dfs(0);
	if (fail) puts("Impossible");
}
int main(){
	int nT;
	scanf("%d", &nT);
	for (int i = 1; i <= nT; i++){
		printf("Case #%d:\n", i);
		solve();
	}
//	while(1);
	return 0;
}
