#include<iostream>
#include<string>
#include<queue>

using namespace std;
bool vis[205][205][205];
#define mk(a,b) make_pair((a),(b))

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
string dir = "WSEN";
struct ss
{
	int x,y,lvl;
	ss(int x=0,int y=0,int lvl=0):x(x),y(y),lvl(lvl){}
};
int dstx,dsty;

string bfs()
{
	vector< ss > q;
	vector<int> p;
	string path = "#";
	q.push_back( ss(100,100,1) );
	vis[100][100][1] = true;
	p.push_back(-1);
	int i;
	for (i = 0; i < q.size(); ++i)
	{
		ss cur = q[i];
		int j;
		for ( j = 0; j < 4; ++j)
		{
			int nx = cur.x+dx[j]*cur.lvl;
			int ny = cur.y+dy[j]*cur.lvl;
			int nl = cur.lvl + 1;
			if (nx>-1 && nx<=200 && ny >-1 && ny<= 200 && !vis[nx][ny][nl])
			{
				vis[nx][ny][nl] = true;
				q.push_back( ss(nx,ny,nl) );
				p.push_back(i);
				path += dir[j];
				if (nx == dstx && ny == dsty) break;
			}
		}
		if( j < 4 )
			break;
	}
	
	i = p.size() - 1;
	string res;
	while (p[i] != -1)
	{
		//res.Add(q[i]);
		res+=path[i];
		i = p[i];
	}
	reverse(res.begin(), res.end());
	return res;
}

int main()
{
	freopen("in.txt","rt",stdin);
	freopen("out_B.txt","wt",stdout);
	int TC;
	scanf("%d",&TC);
	for(int tc=1;tc<=TC;tc++)
	{
		scanf("%d %d",&dstx,&dsty);
		dstx+=100;
		dsty+=100;
		memset(vis,0,sizeof(vis));
		printf("Case #%d: %s\n",tc,bfs().c_str());
	}
	return 0;
}