#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
struct unit{
	int x,y;
	int d;
	unit(int D=0,int X=0,int Y=0){x=X;y=Y;d=D;}
};
map<unit,int>Map[501];
//bool flag[501][502][502];
map<int ,map<int,bool> >flag[502];
bool f[101][101];
int off=250,cnt=0;
queue<unit>Q;
unit par[23][500][500];
void push(const unit &x,int d,int dx,int dy)
{
	if(d==21)return;
	unit y=unit(d+1,x.x+dx,x.y+dy);
	par[d+1][y.x+off][y.y+off]=unit(d,x.x,x.y);
	if(flag[y.d][y.x][y.y]==true)return;
	flag[y.d][y.x][y.y]=true;
	if(y.x>=0&&y.x<=100 && y.y>=0&&y.y<=100&&f[y.x][y.y]==false)
		f[y.x][y.y]=true,cnt++;
	Q.push(y);
}
void BFS(){
	flag[0][0][0]=true;
	cnt++;
	Q.push(unit(0,0,0));
	int Maxx=0;
	while(!Q.empty())
	{
		unit x=Q.front();Q.pop();
		if(x.x>Maxx)Maxx=x.x;
		push(x,x.d,x.d+1,0);
		push(x,x.d,-(x.d+1),0);
		push(x,x.d,0,x.d+1);
		push(x,x.d,0,-(x.d+1));
	}
	//printf("%d\n",Maxx);
}
void trace(int d,int x,int y)
{
//	printf("%d %d %d\n",d,x,y);
	if(d==0)return ;
	int fx=par[d][x+off][y+off].x,fy=par[d][x+off][y+off].y;
	trace(d-1,fx,fy);
	if(fx==x){
		if(fy > y)
			putchar('S');
		else putchar('N');
	}
	else if(fx>x)
		putchar('W');
	else putchar('E');
}
int main()
{
	BFS();
	for(int i=0;i<=100;i++)
		for(int j=0;j<=100;j++){
			bool got=false;
			for(int k=0;k<=21;k++)
				if(flag[k][i][j]==true){
					got=true;
				}
			if(!got)fprintf(stderr,"%d %d\n",i,j);
		}
	int T,w=1;
	scanf("%d",&T);
	while(T--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("Case #%d: ",w++);
		for(int i=1;i<=21;i++)
			if(flag[i][x][y]==true)
			{
				trace(i,x,y);
				break;
			}
		puts("");
	}
}
