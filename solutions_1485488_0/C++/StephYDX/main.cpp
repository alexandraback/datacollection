#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long llong;

const int MAX = 15;
struct Edge{
	int x, y, h;
	Edge *next;
	Edge(){};
	Edge(int x, int y, int h, Edge *next):x(x), y(y), h(h), next(next){}
};
Edge edge[MAX * MAX * 4], *adj[MAX][MAX], *ne;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int H, N, M;
int C[MAX][MAX], F[MAX][MAX];
bool inmap(int x, int y){
	return 0 <= x && x < N && 0 <= y && y < M;
}
void addEdge(int x, int y){
	if(!inmap(x, y)) return;
	for(int i = 0;i < 4; ++i){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(!inmap(nx, ny)) continue;
		if(F[x][y] <= C[nx][ny] - 50 &&
		   F[nx][ny] <= C[nx][ny] - 50 &&
		   F[nx][ny] <= C[x][y] - 50){
			*ne = Edge(nx, ny, C[nx][ny] - 50, adj[x][y]);
			adj[x][y] = ne++;
		}
	}
}

struct Node{
	int x, y, h;
	Node(int x, int y, int h):x(x), y(y), h(h){}
};
bool operator < (const Node &u, const Node &v){
	return u.h < v.h;
}

bool vst[MAX][MAX];
int dist[MAX][MAX];
//const int NINF = 0x80808080;

double dij(){
	priority_queue<Node> pq;
	memset(vst, 0, sizeof(vst));
	memset(dist, 0x80, sizeof(dist));
	dist[0][0] = H;
	pq.push(Node(0, 0, H));
	while(!pq.empty()){
		Node cur = pq.top();
		pq.pop();
		int x0 = cur.x;
		int y0 = cur.y;
		int h0 = cur.h;
		if(vst[x0][y0]) continue;
		vst[x0][y0] = true;
		for(Edge *p = adj[x0][y0]; p; p = p -> next){
			int nx = p -> x;
			int ny = p -> y;
			int nh = p -> h;
			if(h0 <= nh) nh = h0;
			if(nh < H){
				if(nh >= F[x0][y0] + 20) nh -= 10;
				else nh -= 100;
			}
			if(nh > dist[nx][ny]){
				dist[nx][ny] = nh;
				pq.push(Node(nx, ny, nh));
			}
		}
	}
	return (H - dist[N - 1][M - 1]) / 10.;
}
int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("Bs0.txt", "w", stdout);
	//srand(time(0));
	int TT;
	scanf("%d", &TT);
	for(int cas = 1;cas <= TT; ++cas){
		scanf("%d %d %d", &H, &N, &M);
		for(int i = 0;i < N; ++i){
			for(int j = 0;j < M; ++j){
				scanf("%d", C[i] + j);
			}
		}
		for(int i = 0;i < N; ++i){
			for(int j = 0;j < M; ++j){
				scanf("%d", F[i] + j);
			}
		}
		
		memset(adj, 0, sizeof(adj));
		ne = edge;
		for(int i = 0;i < N; ++i){
			for(int j = 0;j < M; ++j){
				addEdge(i, j);
			}
		}
		printf("Case #%d: %.9f\n", cas, dij());

	}
	return 0;
}
