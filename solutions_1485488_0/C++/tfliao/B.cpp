#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long int uint64;
#define MAXN 110
#define L 50
#define MAXT 10000000

int way[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int M, H, N;
int c[ MAXN ][ MAXN ];
int f[ MAXN ][ MAXN ];
bool can[ MAXN ][ MAXN ];

double dis[ MAXN ][ MAXN ];
bool isvisit[ MAXN ][ MAXN ];

bool islegal( int x, int y ){
	return (x >= 0 && y >= 0 && x < N && y < M);
}

struct S{
	int x, y;
};
vector<S> s;
struct T{
	int x1, x2;
	int y1, y2;
	double t;
	bool isTen;

};

struct Node{
	int x, y;
	double t;
	double h;
	bool operator < (const Node &in)const{
		return in.t < t;
	}
};

T e[ MAXN ][ MAXN ][4];

void collectS(){
	memset(isvisit, false, sizeof(isvisit));

	queue<S> q;
	S start;
	start.x = 0;
	start.y = 0;
	q.push(start);
	//BFS
	while(!q.empty()){
		S now = q.front();
		q.pop();

		isvisit[now.x][now.y] = true;
		s.push_back( now );

		for(int i = 0;i < 4; i++){
			int nx = now.x + way[ i ][ 0 ];
			int ny = now.y + way[ i ][ 1 ];
			if( islegal(nx, ny) == false )continue;
			if(isvisit[nx][ny]) continue;
			if( e[now.x][now.y][i].t == 0 ){
				S next;
				next.x = nx;
				next.y = ny;
				q.push(next);
			}
		}
	}
}

bool inq[ MAXN ][ MAXN ];	//此node目前是否在queue中

bool SPFA(S startp){
	queue<Node> q;

	//initial
	memset(inq, false, sizeof(inq));

	//initialization，將所有distance設為最大值
	memset(isvisit, false, sizeof(isvisit));

	for( int i = 0;i < N; i++ ){
		for( int j = 0;j < M; j++ ){
			dis[i][j] = 1e17;
		}
	}

	//push the first node into queue
	inq[startp.x][startp.y] = true;
	dis[startp.x][startp.y] = 0;
	//if(startp.x != 2 || startp.y != 0) return 1e16;
	Node start;
	start.h = H;
	start.x = startp.x;
	start.y = startp.y;
	start.t = 0;
	dis[startp.x][startp.y] = 0;
	q.push(start);

	//BFS計算
	while(!q.empty()){
		Node now = q.front();
		q.pop();

		//pop出來的node就將inq設定為false
		inq[now.x][now.y] = false;
		//printf("%d %d = %lf %lf\n", now.x, now.y, now.t, now.h);

		for(int i = 0;i < 4; i++){
			int nx = now.x + way[ i ][ 0 ];
			int ny = now.y + way[ i ][ 1 ];
			if( islegal(nx, ny) == false )continue;

			Node next;
			next.h = now.h;

			double tt;
			double min_H = min( (double)c[now.x][now.y], (double)c[nx][ny] );
			double max_L = max( (double)f[now.x][now.y], (double)f[nx][ny] );
			if( min_H < max_L + 50 ){
				continue;
			} else if( min_H >= max( max_L, now.h ) + 50 ){
				tt = 0;
				if( now.h - (double)f[now.x][now.y] < 20 ){
					tt += 10;
				} else {
					tt += 1;
				}
				next.h = now.h - 10;

			} else {
				double need = 50 - ((double)min_H - now.h);
				next.h = now.h - need - 10;
				tt = need / 10 ;
				///printf("%lf\n", need);
				if( next.h - (double)f[now.x][now.y] < 20 ){
					tt += 10;
				} else {
					tt += 1;
				}
				//printf("%lf %lf\n", next.h, now.h);

			}
			double nt = now.t + tt;
			if( dis[nx][ny] > nt ){
				dis[nx][ny] = nt;
				//printf("%d %d (%lf)= %lf\n", nx, ny, next.h, nt);

				if( !inq[nx][ny] ){
					inq[nx][ny] = true;

					next.x = nx;
					next.y = ny;
					next.t = dis[nx][ny];
					q.push(next);	//push in next node
				}
			}
		}
	}
	return true;
}

double dijkstra(S startp){
	if(startp.x != 2 || startp.y != 0) return 1e16;

	//initialization，將所有distance設為最大值
	memset(isvisit, false, sizeof(isvisit));

	for( int i = 0;i < N; i++ ){
		for( int j = 0;j < M; j++ ){
			dis[i][j] = 1e17;
		}
	}

	priority_queue<Node> q;

	Node start;
	start.x = startp.x;
	start.y = startp.y;
	start.t = 0;
	dis[startp.x][startp.y] = 0;
	q.push(start);

	//BFS
	while(!q.empty()){
		Node now = q.top();
		q.pop();

		isvisit[now.x][now.y] = true;

		//printf("%d %d = %lf %lf\n", now.x, now.y, now.t, now.h);

		if(now.x == N - 1 && now.y == M - 1)
			return now.t;

		for(int i = 0;i < 4; i++){
			int nx = now.x + way[ i ][ 0 ];
			int ny = now.y + way[ i ][ 1 ];
			if( islegal(nx, ny) == false )continue;
			if(isvisit[nx][ny]) continue;

			Node next;
			next.h = now.h;

			double tt;
			double min_H = min( (double)c[now.x][now.y], (double)c[nx][ny] );
			double max_L = max( (double)f[now.x][now.y], (double)f[nx][ny] );
			if( min_H < max_L + 50 ){
				continue;
			} else if( min_H >= max( max_L, now.h ) + 50 ){
				tt = 0;
				if( now.h - (double)f[now.x][now.y] < 20 ){
					tt += 10;
				} else {
					tt += 1;
				}

			} else {
				double need = 50 - ((double)min_H - now.h);
				next.h = now.h - need;
				tt = need / 10 ;
				//printf("%lf\n", need);
				if( next.h - (double)f[now.x][now.y] < 20 ){
					tt += 10;
				} else {
					tt += 1;
				}

			}

			double nt = now.t + tt;

			if( dis[nx][ny] > nt ){
				dis[nx][ny] = nt;
				Node next;
				next.x = nx;
				next.y = ny;
				next.t = dis[nx][ny];
				q.push(next);	//push in next node
			}
		}
	}
	return -1;
}


int main() {
	int cases;		// number of cases
	int caseID = 1;	// case ID, start from 1

	// freopen("input", "r", stdin);
	//freopen("output", "w", stdout);
	scanf("%d", &cases);
	while (cases--) {

		scanf("%d%d%d", &H, &N, &M);
		for( int i = 0;i < N; i++ ){
			for( int j = 0;j < M; j++ ){
				scanf("%d", &c[i][j]);
			}
		}
		for( int i = 0;i < N; i++ ){
			for( int j = 0;j < M; j++ ){
				scanf("%d", &f[i][j]);
			}
		}

		s.clear();
		memset( e, 0, sizeof(e) );
		memset( can, false, sizeof(can) );

		for( int i = 0;i < N; i++ ){
			for( int j = 0;j < M; j++ ){
				for( int k = 0; k < 4; k++ ){
					int nx = i + way[ k ][ 0 ];
					int ny = j + way[ k ][ 1 ];
					if( islegal( nx, ny ) == false ) continue;

					e[i][j][k].x1 = i;
					e[i][j][k].y1 = j;
					e[i][j][k].x2 = nx;
					e[i][j][k].y2 = ny;
					int min_H = min( c[i][j], c[nx][ny] );
					int max_L = max( f[i][j], f[nx][ny] );
					e[i][j][k].isTen = false;

					if( min_H < max_L + 50 ){
						e[i][j][k].t = MAXT;
						//printf("1 (%d %d %d) %d %d => %d %d = %lf\n", min_H, max_L, H, i, j, nx, ny, e[i][j][k].t);
					} else if( min_H >= max( max_L, H ) + 50 ){
						e[i][j][k].t = 0;
						//printf("2 (%d %d %d) %d %d => %d %d = %lf\n", min_H, max_L, H, i, j, nx, ny, e[i][j][k].t);
					} else {
						int need = 50 - (min_H - H);
						e[i][j][k].t = (double)(need) / (double)(10) ;
						if( min_H - 50 - f[i][j] < 20 ){
							e[i][j][k].t += 10;
							e[i][j][k].isTen = true;
						}
						//printf("3 (%d %d %d) %d %d => %d %d = %lf %d\n", min_H, max_L, H, i, j, nx, ny, e[i][j][k].t, e[i][j][k].isTen);
					}


				}
			}
		}

		collectS();

		double ans = 1e17;
		for( int i = 0;i < (int)s.size(); i++ ){
			//printf("%d %d \n", s[i].x, s[i].y);
			SPFA(s[i]);
			//dijkstra(s[i]);
			double tmp = dis[N-1][M-1];
		//	printf("[%d %d] == %lf \n", s[i].x, s[i].y, tmp);
			ans = min( tmp, ans );
		}
//
//		double tmp = dijkstra();
//					printf("%d %d == %lf \n", s[i].x, s[i].y, tmp);
//					ans = min( tmp, ans );


		printf("Case #%d: %lf\n", caseID++, ans);
	}
	return 0;
}
