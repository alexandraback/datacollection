#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int H,n,m;

int dir[4][2] = {-1,0,0,1,1,0,0,-1};

int fl[100][100];
int ce[100][100];
bool done[100][100];
double best[100][100];

struct node
{
	int x,y;
	double t;

	node(int _x = 0, int _y = 0, double _t = 0.0)
	{
		x = _x; y = _y; t = _t;
	}

	bool operator< (const node& n2) const
	{
		return t>n2.t;
	}
};

void moveCost(int x, int y, int nextX, int nextY, int H, double& waitTime, int& moveTime)
{
	int ce1 = ce[x][y], ce2 = ce[nextX][nextY];
	int fl1 = fl[x][y], fl2 = fl[nextX][nextY];
	int hfl1 = max(fl[x][y], H), hfl2 = max(fl[nextX][nextY], H);
	hfl1 = min(hfl1, ce1), hfl2 = min(hfl2, ce2);

	if (ce2-fl2<50) { moveTime = -1; return; }
	if (ce2-fl1<50) { moveTime = -1; return; }
	if (ce1-fl2<50) { moveTime = -1; return; }

	waitTime = 0;

	if (ce2-hfl2<50)
	{
		int new_hfl2 = ce2-50;
		waitTime = (hfl2-new_hfl2)/10.0;
		H -= 10*waitTime;
	}

	if (H-fl[x][y]>=20) moveTime = 1;
	else moveTime = 10;
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int T;
	cin>>T;
	for(int tt=1;tt<=T;tt++)
	{
		memset(done,0,sizeof(done));
		memset(best,0,sizeof(best));
		memset(fl,0,sizeof(fl));
		memset(ce,0,sizeof(ce));

		cin>>H>>n>>m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>ce[i][j];

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>fl[i][j];

		done[0][0] = true;
		best[0][0] = 0;

		priority_queue<node> q;

		while(!q.empty()) q.pop();

		q.push(node(0,0));

		while(!q.empty()&&!done[n-1][m-1])
		{
			node head = q.top();
			q.pop();
			for(int dd = 0;dd<4;dd++)
			{
				int nextX = head.x + dir[dd][0], nextY = head.y + dir[dd][1];
				if (nextX<0||nextY<0||nextX>=n||nextY>=m) continue;

				if (!done[nextX][nextY])
				{
					double waitTime;
					int moveTime;
					moveCost(head.x, head.y, nextX, nextY, H, waitTime, moveTime);

					if (moveTime!=-1&&waitTime<1e-5)
					{
						done[nextX][nextY] = true;
						best[nextX][nextY] = 0.0;
						q.push(node(nextX,nextY));
					}
				}
			}
		}

		if (done[n-1][m-1])
		{
			printf("Case #%d: %.1f\n", tt, best[n-1][m-1]);
			continue;
		}

		while(!q.empty()) q.pop();

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if (done[i][j]) q.push(node(i,j));

		while(!q.empty()&&!done[n-1][m-1])
		{
			node head = q.top();
			q.pop();
			done[head.x][head.y] = true;
			best[head.x][head.y] = head.t;

			for(int dd = 0;dd<4;dd++)
			{
				int nextX = head.x + dir[dd][0], nextY = head.y + dir[dd][1];
				if (nextX<0||nextY<0||nextX>=n||nextY>=m) continue;

				if (!done[nextX][nextY])
				{
					double waitTime;
					int moveTime;
					moveCost(head.x, head.y, nextX, nextY, H-10*head.t, waitTime, moveTime);

					if (moveTime!=-1)
					{
						q.push(node(nextX,nextY,head.t+waitTime+moveTime));
					}
				}
			}
		}

		if (!done[n-1][m-1]) printf("wtf?\n");
		printf("Case #%d: %.1f\n", tt, best[n-1][m-1]);

	}
	return 0;
}
