#include<cstdio>
#include<cstdlib>
#include<cstring>
#define N 1
#define W 2
#define S 3
#define E 4
#define SN struct node
SN
{
	int x;
	int y;
	int d;
};
SN que[1000005];
int dis[750][750];
int qf,qe;
int visit[750][750];
int pre[750][750];
using namespace std;
int main(void)
{
	int T;
	int x,y;
	scanf("%d",&T);
	int i,j,k;
	for(i=1;i<=T;i++)
	{
		scanf("%d %d",&x,&y);
		x = x+101;
		y = y+101;
		
		memset(visit,0,sizeof(visit));
		memset(visit,0,sizeof(pre));
		memset(visit,0,sizeof(dis));
		qf = qe = 0;
		que[0].x = 101;
		que[0].y = 101;
		que[0].d = 0;
		qe++;
		visit[101][101] = 1;
		while(qf!=qe&&visit[x][y]==0)
		{
			SN u = que[qf++];
			int d = u.d+1;
			int ux = u.x;
			int uy = u.y;	
			
			if(ux>d&&visit[ux-d][uy]==0)
			{
				visit[ux-d][uy] = 1;
				que[qe].x = ux-d;
				que[qe].y = uy;
				que[qe].d = d;
				qe++;
				pre[ux-d][uy] = W;
				dis[ux-d][uy] = d;
			}
			if(uy>d&&visit[ux][uy-d]==0)
			{
				visit[ux][uy-d] = 1;
				que[qe].x = ux;
				que[qe].y = uy-d;
				que[qe].d = d;
				qe++;
				pre[ux][uy-d] = S;
				dis[ux][uy-d] = d;
			}
			if(ux+d<250&&visit[ux+d][uy]==0)
			{
				visit[ux+d][uy] = 1;
				que[qe].x = ux+d;
				que[qe].y = uy;
				que[qe].d = d;
				qe++;
				pre[ux+d][uy] = E;
				dis[ux+d][uy] = d;
			}
			if(uy+d<250&&visit[ux][uy+d]==0)
			{
				visit[ux][uy+d] = 1;
				que[qe].x = ux;
				que[qe].y = uy+d;
				que[qe].d = d;
				qe++;
				pre[ux][uy+d] = N;
				dis[ux][uy+d] = d;
			}
		}
		int stack[1000];
		int sn = 0;
		int sd = dis[x][y];
		int kn =0;
		
		while(sd>0)
		{
			
			stack[sn++] = pre[x][y];
			
			switch(pre[x][y])
			{
				case N: y = y-sd; 
				break;
				case S: y = y+sd; 
				break;
				case W: x = x+sd; 
				break;
				case E: x = x-sd; 
				break;
			}
			sd--;
			
		}
		printf("Case #%d: ",i);
		for(j = sn-1;j>=0;j--)
		switch(stack[j])
		{
			case N:printf("N");
			break;
			case W:printf("W");
			break;
			case E:printf("E");
			break;
			case S:printf("S");
			break;
		}
		printf("\n");
	}


}
