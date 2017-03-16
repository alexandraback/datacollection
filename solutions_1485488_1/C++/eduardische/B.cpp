#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 105
#define MYINF 2000000000 //CHECK IT!!!

struct coord
{
	int x, y;
};

char CanMove (int fa, int ca, int fb, int cb, int w)
{
	if ((w + 50 <= cb) && (fa + 50 <= cb) && (fb + 50 <= cb) && (fb + 50 <= ca)) return 1;
	else return 0;
}

int main ()
{
	int T, iT;
	scanf("%d",&T);
	static int a[MAXN][MAXN];
	static int f[MAXN][MAXN];
	static int c[MAXN][MAXN];
	static struct coord q[MAXN*MAXN];
	static char b[MAXN][MAXN];
	for (iT = 0; iT < T; iT++)
	{
		int N, M, W;
		scanf("%d %d %d",&W,&N,&M);
		int i, j;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				scanf("%d",&(c[i][j]));
			}
		}

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				scanf("%d",&(f[i][j]));
			}
		}
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				a[i][j] = MYINF;
			}
		}

		a[0][0] = 0;
		int r, w;
		r = 0; w = 1;
		q[0].x = 0;
		q[0].y = 0;
		int x, y;
		while (w > r)
		{
			x = q[r].x - 1;
			y = q[r].y;
			if ((x >= 0) && (x < N) && (y >= 0) && (y < M))
			{
				if ((CanMove(f[q[r].x][q[r].y], c[q[r].x][q[r].y], f[x][y], c[x][y], W)) && (a[x][y] == MYINF))
				{
					a[x][y] = 0;
					q[w].x = x;
					q[w].y = y;
					w++;
				}
			}

			x = q[r].x + 1;
			y = q[r].y;
			if ((x >= 0) && (x < N) && (y >= 0) && (y < M))
			{
				if ((CanMove(f[q[r].x][q[r].y], c[q[r].x][q[r].y], f[x][y], c[x][y], W)) && (a[x][y] == MYINF))
				{
					a[x][y] = 0;
					q[w].x = x;
					q[w].y = y;
					w++;
				}
			}

			x = q[r].x;
			y = q[r].y - 1;
			if ((x >= 0) && (x < N) && (y >= 0) && (y < M))
			{
				if ((CanMove(f[q[r].x][q[r].y], c[q[r].x][q[r].y], f[x][y], c[x][y], W)) && (a[x][y] == MYINF))
				{
					a[x][y] = 0;
					q[w].x = x;
					q[w].y = y;
					w++;
				}
			}

			x = q[r].x;
			y = q[r].y + 1;
			if ((x >= 0) && (x < N) && (y >= 0) && (y < M))
			{
				if ((CanMove(f[q[r].x][q[r].y], c[q[r].x][q[r].y], f[x][y], c[x][y], W)) && (a[x][y] == MYINF))
				{
					a[x][y] = 0;
					q[w].x = x;
					q[w].y = y;
					w++;
				}
			}

			r++;
		}

		memset(b,0,sizeof(b));

		while (!b[N-1][M-1])
		{
			i = 0; j = 0;
			int now = MYINF+1;
			for (x = 0; x < N; x++)
			{
				for (y = 0; y < M; y++)
				{
					if ((!b[x][y]) && (a[x][y] < now))
					{
						now = a[x][y];
						i = x; j = y;
					}
				}
			}
			b[i][j] = 1;
			int temp, w2;
			w2 = W - a[i][j];

			//printf("%d\n",w2);

			x = i - 1;
			y = j;
			if ((x >= 0) && (x < N) && (y >= 0) && (y < M))
			{
				if (CanMove(f[i][j], c[i][j], f[x][y], c[x][y], w2))
				{
					temp = a[i][j];
					if ((w2 - f[i][j]) >= 20) temp += 10;
					else temp += 100;
					if (temp < a[x][y]) a[x][y] = temp;
				}
				else
				{
					if (CanMove(f[i][j], c[i][j], f[x][y], c[x][y], -50))
					{
						int w3 = c[x][y] - 50;
						temp = (W - w3);
						if ((w3 - f[i][j]) >= 20) temp += 10;
						else temp += 100;
						if (temp < a[x][y]) a[x][y] = temp;
					}
				}
			}

			x = i + 1;
			y = j;
			if ((x >= 0) && (x < N) && (y >= 0) && (y < M))
			{
				//printf("A %d %d %d %d %d\n",f[i][j], c[i][j], f[x][y], c[x][y], w2);
				if (CanMove(f[i][j], c[i][j], f[x][y], c[x][y], w2))
				{
					//printf("B\n");
					temp = a[i][j];
					if ((w2 - f[i][j]) >= 20) temp += 10;
					else temp += 100;
					if (temp < a[x][y]) a[x][y] = temp;
				}
				else
				{
					if (CanMove(f[i][j], c[i][j], f[x][y], c[x][y], -50))
					{
						int w3 = c[x][y] - 50;
						temp = (W - w3);
						if ((w3 - f[i][j]) >= 20) temp += 10;
						else temp += 100;
						if (temp < a[x][y]) a[x][y] = temp;
					}
				}
			}

			x = i;
			y = j - 1;
			if ((x >= 0) && (x < N) && (y >= 0) && (y < M))
			{
				if (CanMove(f[i][j], c[i][j], f[x][y], c[x][y], w2))
				{
					temp = a[i][j];
					if ((w2 - f[i][j]) >= 20) temp += 10;
					else temp += 100;
					if (temp < a[x][y]) a[x][y] = temp;
				}
				else
				{
					if (CanMove(f[i][j], c[i][j], f[x][y], c[x][y], -50))
					{
						int w3 = c[x][y] - 50;
						temp = (W - w3);
						if ((w3 - f[i][j]) >= 20) temp += 10;
						else temp += 100;
						if (temp < a[x][y]) a[x][y] = temp;
					}
				}
			}

			x = i;
			y = j + 1;
			if ((x >= 0) && (x < N) && (y >= 0) && (y < M))
			{
				if (CanMove(f[i][j], c[i][j], f[x][y], c[x][y], w2))
				{
					temp = a[i][j];
					if ((w2 - f[i][j]) >= 20) temp += 10;
					else temp += 100;
					if (temp < a[x][y]) a[x][y] = temp;
				}
				else
				{
					if (CanMove(f[i][j], c[i][j], f[x][y], c[x][y], -50))
					{
						int w3 = c[x][y] - 50;
						temp = (W - w3);
						if ((w3 - f[i][j]) >= 20) temp += 10;
						else temp += 100;
						if (temp < a[x][y]) a[x][y] = temp;
					}
				}
			}
		}

		printf("Case #%d: %d.%d\n",iT+1,a[N-1][M-1]/10,a[N-1][M-1]%10);
	}
}
