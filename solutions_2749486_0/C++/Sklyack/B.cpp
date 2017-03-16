#include <cstdio>
#include <cstring>

const int MAXX=1000;
const int dc[4][2]={{0,1}, {0,-1}, {1,0}, {-1,0}};
const int dsym[4]={'N', 'S', 'E', 'W'};
int D[2*MAXX+1][2*MAXX+1], prev[2*MAXX+1][2*MAXX+1][2];
char sym[2*MAXX+1][2*MAXX+1];
int Q[(2*MAXX+1)*(2*MAXX+1)][2], head, tail;
const int MAXLEN=500;
char ans[MAXLEN+1];

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t, T;
	int x0, y0, d0, xf, yf, i, x, y;
	int tx;

	memset(D, -1, sizeof(D));
	memset(sym, 0, sizeof(sym));
	head=tail=0;
	x0=y0=MAXX;
	D[x0][y0]=0;
	Q[tail][0]=x0;
	Q[tail++][1]=y0;
	while(head<tail)
	{
		x0=Q[head][0];
		y0=Q[head][1];
		d0=D[x0][y0];
		++head;
		for(i=0; i<4; ++i)
		{
			x=x0+(d0+1)*dc[i][0];
			y=y0+(d0+1)*dc[i][1];
			if(0<=x && x<=2*MAXX && 0<=y && y<=2*MAXX && D[x][y]==-1)
			{
				D[x][y]=d0+1;
				prev[x][y][0]=x0;
				prev[x][y][1]=y0;
				sym[x][y]=dsym[i];
				Q[tail][0]=x;
				Q[tail++][1]=y;
			}
		}
	}

	scanf("%d", &T);
	for(t=1; t<=T; ++t)
	{
		scanf("%d%d", &xf, &yf);
		x=xf+MAXX;
		y=yf+MAXX;
		i=D[x][y]-1;
		ans[i+1]=0;
		for(; i>=0; --i)
		{
			ans[i]=sym[x][y];
			tx=prev[x][y][0];
			y=prev[x][y][1];
			x=tx;
		}
		printf("Case #%d: %s\n", t, ans);
	}
	return 0;
}
