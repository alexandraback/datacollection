#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <utility>
#include <cassert>
#define x first
#define y second
#define mp(X,Y) make_pair(X,Y)
#define MAX 2000
#define DEL 1000

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int X, Y;
int vis[MAX][MAX];
int p[MAX][MAX];
int c[MAX][MAX];
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};

void dijkstra(){
	for(int i = 0; i < MAX; i++)
		for(int j = 0; j < MAX; j++)
			vis[i][j] = c[i][j] = p[i][j] = -1;
	c[DEL][DEL] = 0;
	set <piii> s;
	s.clear();
	s.insert(mp(0, mp(DEL, DEL)));
	while(!s.empty()){
		pii pa = s.begin()->y;
		s.erase(s.begin());
		if(vis[pa.x][pa.y] != -1)
			continue;
		if(pa.x == X+DEL && pa.y == Y+DEL)
			break;
		vis[pa.x][pa.y] = 1;
		//printf("%d %d\n", pa.x, pa.y);
		for(int k = 0; k < 4; k++){
			int d = c[pa.x][pa.y]+1;
			int i = pa.x+d*di[k], j = pa.y+d*dj[k];
			if(i < 0 || i >= MAX || j < 0 || j >= MAX)
				continue;
			if(c[i][j] == -1 || c[i][j] > c[pa.x][pa.y]+1){
				p[i][j] = k;
				c[i][j] = d;
				s.insert(mp(d, mp(i, j)));
			}
		}
	}
}

void bt(int i, int j){
	if(i == DEL && j == DEL)
		return;
	int d = c[i][j];
	bt(i-di[p[i][j]]*d, j-dj[p[i][j]]*d);
	if(p[i][j] == 0)
		printf("W");
	if(p[i][j] == 1)
		printf("E");
	if(p[i][j] == 2)
		printf("S");
	if(p[i][j] == 3)
		printf("N");
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		scanf("%d%d", &X, &Y);
		dijkstra();
		assert(c[X+DEL][Y+DEL] != -1 && c[X+DEL][Y+DEL] < 500);
		//printf("%d\n", c[X+DEL][Y+DEL]);
		printf("Case #%d: ", t);
		bt(X+DEL, Y+DEL);
		printf("\n");
	}
	return 0;
}
