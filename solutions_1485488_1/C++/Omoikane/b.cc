#include <stdio.h>

int tt, T, h, m, n, c[100][100], f[100][100], t[100][100];

int test(int x1, int y1, int x2, int y2)
{
	if ((x2<0) || (x2>=m) || (y2<0) || (y2>=n)) return 0;
	if ((c[y1][x1]-f[y2][x2]<50) || (c[y2][x2]-f[y1][x1]<50) || (c[y2][x2]-f[y2][x2]<50)) return 0;
	if (c[y2][x2]-h<50) return 0;
	if (h-f[y1][x1]>=20) return 10;
	return 100;
}

void jump(int x, int y)
{
	if (!t[y][x]) return;
	t[y][x]=0;
	if (test(x, y, x-1, y)) jump(x-1, y);
	if (test(x, y, x+1, y)) jump(x+1, y);
	if (test(x, y, x, y-1)) jump(x, y-1);
	if (test(x, y, x, y+1)) jump(x, y+1);
}

int main()
{
	scanf(" %d", &T);
	for(int cs=1; cs<=T; cs++)
	{
		int tt=0;
		scanf(" %d %d %d", &h, &n, &m);
		for(int j=0; j<n; j++)
			for(int i=0; i<m; i++)
				scanf(" %d", &c[j][i]);
		for(int j=0; j<n; j++)
			for(int i=0; i<m; i++)
				scanf(" %d", &f[j][i]);
		for(int j=0; j<n; j++)
			for(int i=0; i<m; i++)
				t[j][i]=1000000000;
		jump(0, 0);
		while(tt<t[n-1][m-1])
		{
			tt++; h--;
			for(int j=0; j<n; j++)
				for(int i=0; i<m; i++)
				{
					int dummy;
					dummy=test(i, j, i-1, j);
					if ((dummy) && (tt+dummy<t[j][i-1]) && (t[j][i]<=tt))
					{
						// printf("%5d: (%3d) %d/%d -> %d/%d\n", tt, dummy, i, j, i-1, j);
						t[j][i-1]=tt+dummy;
					}
					
					dummy=test(i, j, i+1, j);
					if ((dummy) && (tt+dummy<t[j][i+1]) && (t[j][i]<=tt))
					{
						// printf("%5d: (%3d) %d/%d -> %d/%d\n", tt, dummy, i, j, i+1, j);
						t[j][i+1]=tt+dummy;
					}
					
					dummy=test(i, j, i, j-1);
					if ((dummy) && (tt+dummy<t[j-1][i]) && (t[j][i]<=tt))
					{
						// printf("%5d: (%3d) %d/%d -> %d/%d\n", tt, dummy, i, j, i, j-1);
						t[j-1][i]=tt+dummy;
					}
					
					dummy=test(i, j, i, j+1);
					if ((dummy) && (tt+dummy<t[j+1][i]) && (t[j][i]<=tt))
					{
						// printf("%5d: (%3d) %d/%d -> %d/%d\n", tt, dummy, i, j, i, j+1);
						t[j+1][i]=tt+dummy;
					}
				}
		}
		printf("Case #%d: %d.%d\n", cs, t[n-1][m-1]/10, t[n-1][m-1]%10);
	}
	return 0;
}
