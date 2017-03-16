#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int N = 7; //
int T;
int round=0;
int mapg[N][N];
int mapd[N][N];
int r,c,m;
int fin;
int dir[8][2]={-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};
int cnt;
int visited[N][N];
int kx,ky;

bool check(int x,int y)
{
	return (x>=1 && x<=r && y>=1 && y<=c);
}

void calc_mapg()
{
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			for(int k=0;k<8;k++){
				int x=i+dir[k][0];
				int y=j+dir[k][1];
				if(check(x,y))
					mapg[i][j]++;
			}
}

bool place_at(int x,int y)
{
	mapd[x][y]=-1;
	mapg[x][y]=0;
	for(int k=0;k<8;k++){
		int nx=x+dir[k][0];
		int ny=y+dir[k][1];
		if(check(nx,ny)){
			if(mapg[nx][ny]>0) mapg[nx][ny]--;
			if(mapd[nx][ny]!=-1)mapd[nx][ny]++;
		}
	}
	return true;
}

void flood_fill(int x,int y)
{
	cnt++;
	visited[x][y]++;
	if(mapd[x][y]!=0) return;
	for(int k=0;k<8;k++){
		int nx=x+dir[k][0];
		int ny=y+dir[k][1];
		if(check(nx,ny) && mapd[nx][ny]!=-1 && !visited[nx][ny])
			flood_fill(nx,ny);
	}
}

int check_map()
{
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++){
			if(mapd[i][j]==0){
				cnt=0;
				kx=i,ky=j;
				memset(visited,0,sizeof(visited));
				flood_fill(i,j);
				if(cnt==r*c-m) return 1;
				return 0;
			}
		}
}

void dfs(int x,int y,int left)
{
	int tmpg[N][N],tmpd[N][N];
	int nx,ny;
	if(y==1 && x==r+1){
		if(left==0)
			fin=check_map();
			if(fin==1){
				for(int i=1;i<=r;i++){
					for(int j=1;j<=c;j++){
						if(i==kx && j==ky) printf("c");
						else if(mapd[i][j]<0) printf("*");
						else printf(".");
					}
					printf("\n");
				}
			}
		return;
	}
	if(y==c) nx=x+1,ny=1;
	else nx=x,ny=y+1;
	if(r*c-c*(x-1)-y>=left)
		dfs(nx,ny,left); //do not place
	if(fin) return;
	if(left){
		memcpy(tmpg,mapg,sizeof(tmpg));
		memcpy(tmpd,mapd,sizeof(tmpd));
		if(place_at(x,y))
			dfs(nx,ny,left-1);
		if(fin) return;
		memcpy(mapg,tmpg,sizeof(mapg));
		memcpy(mapd,tmpd,sizeof(mapd));
	}
}

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("mine.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		fin=0;
		scanf("%d%d%d",&r,&c,&m);
		printf("Case #%d:\n",++round);
		if(r*c==m+1){
			for(int i=1;i<=r;i++){
				for(int j=1;j<=c;j++){
					if(i==r && j==c) printf("c");
					else printf("*");
				}
				printf("\n");
			}
			continue;
		}
		memset(mapg,0,sizeof(mapg));
		memset(mapd,0,sizeof(mapd));
		calc_mapg();
		dfs(1,1,m);		
		if(!fin) printf("Impossible\n");
	}
	return 0;
}