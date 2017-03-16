#include <stdio.h>
#include <string.h>
using namespace std;
int f[11][11];
int solve(int c, int w){
	if(f[c][w])	return f[c][w];
	if(w==c)	return f[c][w] = c;
	if(2*w>c)	return f[c][w] = w+1;
	return f[c][w] = solve(c-w, w) + 1;
}
int main()
{
	// freopen("in.txt", "r", stdin);
	// freopen("ou.txt", "w", stdout);
	int t, kase=0;
	scanf("%d", &t);
	while(t--){
		int r, c, w;
		scanf("%d%d%d", &r, &c, &w);
		printf("Case #%d: %d\n", ++kase, solve(c, w));
	}
	return 0;
}