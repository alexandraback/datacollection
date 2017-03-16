#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
#define N 20
int r, c, n, di[]={-1, 1, 0, 0}, dj[]={0, 0, -1, 1};
char m[N][N], u[N][N];
void dfs(int i, int j)
{
	int k;
	if(u[i][j] || m[i][j]) return;
	n++;
	u[i][j]=1;
	for(k=0; k<4; k++)
	{
		int ii=i+di[k], jj=j+dj[k];
		if(ii>=0 && jj>=0 && ii<r && jj<c && !u[ii][jj] && !m[ii][jj]) dfs(ii, jj);
	}
}
int main()
{
	int ts;
	scanf("%d", &ts);
	for(int t=1; t<=ts; t++)
	{
		int i, j, k, v, h;
		scanf("%d%d%d", &r, &c, &k);
		v=r*c;
		for(h=0; h<(1<<(r*c)); h++)
		{
			for(i=0; i<r; i++)
				for(j=0; j<c; m[i][j]=(h>>(i*c+j))&1, u[i][j]=0, j++);
			n=0;
			for(i=0; i<r; dfs(i, 0), dfs(i, c-1), i++);
			for(i=0; i<c; dfs(0, i), dfs(r-1, i), i++);
			n=r*c-n;
			j=0;
			for(i=0; i<r*c; j+=(h>>i)&1, i++);
			if(n>=k) v=min(v, j);
		}
		printf("Case #%d: %d\n", t, v);
	}
	return 0;
}
