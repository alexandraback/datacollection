#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 22;
int f[N][N][N];
int mem[N][N], mem2[N][N];
int solve_row(int c, int w){
	if(mem[c][w])	return mem[c][w];
	if(2*w>c)	return mem[c][w] = 1;
	return mem[c][w] = 1 + solve_row(c-w, w);
}
int solve_col(int c, int w){
	if(mem2[c][w])	return mem2[c][w];
	if(w==c)	return mem2[c][w] = c;
	if(2*w>c)	return mem2[c][w] = w+1;
	return mem2[c][w] = solve_col(c-w, w) + 1;
}
int solve(int r, int c, int w){
	if(f[r][c][w])	return f[r][c][w];
	return f[r][c][w] = solve_row(c, w) * (r-1) + solve_col(c, w);
}
int main()
{
	// freopen("in.txt", "r", stdin);
	// freopen("tt.txt", "w", stdout);
	int t, kase=0;
	scanf("%d", &t);
	while(t--){
		int r, c, w;
		scanf("%d%d%d", &r, &c, &w);
		printf("Case #%d: %d\n", ++kase, solve(r, c, w));
	}
	return 0;
}