#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
using namespace std ;

const int ALPHA = 1000;
const int MAXN = 2000;
const int oops = 1<<20;
const int dr[] = {-1,0,1,0};
const int dc[] = {0,-1,0,1};



class Cell
{
public:
	int i,j,cost;
	Cell(){}
	Cell(int i,int j,int cost = 0):i(i),j(j),cost(cost){}
};


bool vis[MAXN+5][MAXN+5];
int path[MAXN+5][MAXN+5];
Cell prev[MAXN+5][MAXN+5];
map<pair<int,int>, char> direction;


bool within(int i,int j)
{
	if (i < -ALPHA || j < -ALPHA || i > ALPHA || j > ALPHA)return 0;
	return 1;
}
int sign(int x)
{
	if (x < 0)return -1;
	if (x > 0)return 1;
	return 0;
}
int bfs(Cell sink)
{
	memset(vis,0,sizeof(vis));
	for (int c=0;c<=MAXN;c++)
		for (int c2=0;c2<=MAXN;c2++)
			path[c][c2] = oops;
	prev[0][0] = Cell(-1,-1);
	queue<Cell> q;
	Cell cur (0,0,0);
	q.push(cur);
	path[cur.i][cur.j] = cur.cost;
	vis[cur.i][cur.j] = true;
	while (!q.empty()){
		cur = q.front();
		q.pop();
		//printf("%d,%d :%d\n",cur.i,cur.j,cur.cost);
		if (cur.i == sink.i && cur.j == sink.j)return cur.cost;
		for (int dir=0;dir<4;dir++){
			Cell t (cur.i+dr[dir]*(cur.cost+1),cur.j+(dc[dir]*(cur.cost+1)),cur.cost+1);
			if (!within(t.i,t.j))continue;
			if (vis[t.i+ALPHA][t.j+ALPHA])continue;
			vis[t.i+ALPHA][t.j+ALPHA] = true;
			prev[t.i+ALPHA][t.j+ALPHA] = cur;
			q.push(t);
		}
	}
	return -1;
}


void preProcess()
{
	direction[make_pair(-1,0)] = 'W';
	direction[make_pair( 1,0)] = 'E';
	direction[make_pair(0,-1)] = 'S';
	direction[make_pair(0, 1)] = 'N';
	return ;
}

int main()
{
	freopen("pogo.in","r",stdin);
	freopen("pogo.out","w",stdout);
	int c,c2;
	preProcess();
	int tests;
	scanf("%d",&tests);
	for (int test=1;test<=tests;test++){
		printf("Case #%d: ",test);
		Cell sink;
		scanf("%d%d",&sink.i,&sink.j);
		bfs(sink);
		//printf("%d\n",bfs(sink));
		vector<char> seq;
		
		for (Cell cell = sink ; cell.i!=0 || cell.j!=0 ; ){
			Cell pre = prev[cell.i+ALPHA][cell.j+ALPHA];
			Cell diff = Cell(sign(cell.i-pre.i),sign(cell.j-pre.j));
			seq.push_back(direction[make_pair(diff.i,diff.j)]);
			cell = pre;
		}
		for (c=seq.size()-1;c>=0;c--)
			printf("%c",seq[c]);
		printf("\n");
	}
	
	
	return 0;
}
