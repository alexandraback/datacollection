//pB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

const int N = 2000;
struct QQ{
	int a, b;
}p[N];
int n, bln[N], nx, ny, x[5*N], y[5*N], ans;

bool success(){
	int i = 0, j = 0, cur = 0;
	std::sort(x, x + nx);
	std::sort(y, y + ny);
	while ((i < nx && x[i] <= cur) || (j < ny && y[j] <= cur)){
		while (i < nx && x[i] <= cur){
			cur++;
			i++;
		}
		while (j < ny && y[j] <= cur){
			cur += 2;
			j++;
		}
	}
	return i>=nx && j>=ny;
}
void dfs(int cur){
	if (cur >= n){
		nx = 0;
		ny = 0;
		for (int i = 0; i < n; i++){
			if (bln[i]){
				x[nx++] = p[i].a;
				x[nx++] = p[i].b;
			} else 
				y[ny++] = p[i].b;
		}
		if (success()){
			if (ans == -1) ans = nx + ny;
			if (nx + ny < ans) ans = nx + ny;
		}
		return ;
	}
	bln[cur] = 0;
	dfs(cur + 1);
	bln[cur] = 1;
	dfs(cur + 1);
}
void solve(int nT){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d", &p[i].a, &p[i].b);
	ans = -1;
	dfs(0);
	printf("Case #%d: ", nT);
	if (ans == -1) puts("Too Bad");
	else printf("%d\n", ans);
}
int main(){
	int nT;
	scanf("%d", &nT);
	for (int i = 1; i <= nT; i++)
		solve(i);
//	while(1);
	return 0;
}
