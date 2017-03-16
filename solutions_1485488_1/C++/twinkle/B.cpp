#include <iostream>
#include <queue>
using namespace std;

struct rec{
	int x,y;
}que[1111111];



int n , m, h;

double dist[110][110];
int used[110][110];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
double up[110][110],down[110][110];


double calc(int nx,int ny,int tx,int ty,double t){
	double now = h - t * 10 , ans = 0;
	if(up[tx][ty] - now >= 50){
		if(t == 0)return 0;
		if(now - down[nx][ny] >= 20)return 1.0;
		else	return 10.0;
	}
	ans =( now - up[tx][ty] + 50.0 )/ 10.0;
	now = up[tx][ty]  - 50.0;
	if(now - down[nx][ny] >= 20)return ans + 1.0;
	else	return ans + 10.0;
}

void spfa(){
	for(int i = 1;i <= n; i++)
		for(int j = 1;j <= m; j ++){
			dist[i][j] = 999999999;
			used[i][j] = 0;
		}
	rec tmp,ptr;
	dist[1][1] = 0;
	used[1][1] = 1;
	que[1].x = 1;
	que[1].y = 1;
	int cl,op;
	cl = 1; op = 2;
	while(cl < op){
		tmp.x = que[cl].x;
		tmp.y = que[cl].y;
		int tx,ty;
		double t,delta;
		for(int i = 0 ; i < 4; i ++){
			tx = tmp.x + dx[i];
			ty = tmp.y + dy[i];
			if(tx < 1 || tx > n)continue;
			if(ty < 1 || ty > m)continue;
			if(up[tx][ty]-down[tx][ty] < 50)continue;
			if(up[tmp.x][tmp.y]-down[tx][ty]<50)continue;
			if(up[tx][ty]-down[tmp.x][tmp.y]<50)continue;
			t = dist[tmp.x][tmp.y];
			delta = calc(tmp.x,tmp.y,tx,ty,t);
			if(t+ delta < dist[tx][ty]){
				dist[tx][ty] = t + delta;
				if(used[tx][ty] == 0){
					que[op].x = tx;
					que[op].y = ty;
					op++;
					used[tx][ty] = 1;
				}
			}
		}
		used[tmp.x][tmp.y] = 0;
		cl++;
	}
	printf("%lf\n",dist[n][m]);
}


int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	int T;
	cin >> T;
	for(int Case = 1; Case <= T ; Case ++){
		cin >> h >> n >> m;
		for(int i = 1;i <= n; i ++){
			for(int j = 1;j <= m; j ++){
				cin >> up[i][j];
			}
		}
		for(int i = 1;i <= n; i ++){
			for(int j = 1;j <= m; j ++){
				cin >> down[i][j];
			}
		}
		printf("Case #%d: ",Case);
		spfa();
		
		
		
	}
	
	
	
	return 0;
}
