#include <cstdio>
#include <deque>

const int MAXN=200;
const int oo=1e9;
const int way[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

typedef std::pair<int,int> Pair;
typedef std::deque<Pair> Queue;
#define mp std::make_pair

int H,N,M;
int tceil[MAXN][MAXN],tfloor[MAXN][MAXN];
int best[MAXN][MAXN];

int can(int ax,int ay,int bx,int by)
{
	if (bx<0 || bx>=N || by<0 || by>=M)
		return oo;
	if (tfloor[ax][ay]+50>tceil[bx][by])
		return oo;
	if (tfloor[bx][by]+50>tceil[bx][by])
		return oo;
	if (tfloor[bx][by]+50>tceil[ax][ay])
		return oo;
	if (H+50<tceil[bx][by])
		return 0;
	return 50-(tceil[bx][by]-H);
}

void init()
{
	Queue q;
	q.push_back(mp(0,0));
	while(q.size())
	{
		Pair now=q.front();
		q.pop_front();
		int x=now.first,y=now.second;
		for(int i=0;i<4;i++)
		{
			int nx=x+way[i][0],ny=y+way[i][1];
			if (can(x,y,nx,ny)==0 && best[nx][ny]!=0)
			{
				best[nx][ny]=0;
				q.push_back(mp(nx,ny));
			}
		}
	}
}

void calcu()
{
	Queue q;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if (best[i][j]==0)
				q.push_back(mp(i,j));
	while(q.size())
	{
		Pair now=q.front();
		q.pop_front();
		int x=now.first,y=now.second;
		for(int i=0;i<4;i++)
		{
			int nx=x+way[i][0],ny=y+way[i][1];
			int need=can(x,y,nx,ny);
			if (need==oo)
				continue;
			int nd=std::max(best[x][y],need);
			int nh=H-nd;
			if (tfloor[x][y]+20<=nh)
				nd+=10;
			else
				nd+=100;
			if (nd<best[nx][ny])
			{
				best[nx][ny]=nd;
				if (nd<best[N-1][M-1])
					q.push_back(mp(nx,ny));
			}
		}
	}
}

void solve()
{
	scanf("%d%d%d",&H,&N,&M);
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			scanf("%d",tceil[i]+j);
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			scanf("%d",tfloor[i]+j);
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			best[i][j]=oo;
	best[0][0]=0;
	init();
	calcu();
	int ans=best[N-1][M-1];
	printf("%d.%d\n",ans/10,ans%10);
}

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}