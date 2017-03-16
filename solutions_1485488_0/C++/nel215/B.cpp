#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

#define REP(i,x) for(int i=0 ; i<(int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

struct Node{
	int y,x;
	int cost;
	int t;
	Node(int _y,int _x,int _c,int _t):y(_y),x(_x),cost(_c),t(_t){}
	bool operator<(const Node &n)const{
		return cost>n.cost;
	}
};

void solve(){
	const int DY[4] = {-1,0,1,0};
	const int DX[4] = {0,1,0,-1};
	int T;
	scanf("%d",&T);
	for(int cc=1 ; cc<=T ; cc++){
		int H,N,M;
		scanf("%d%d%d",&H,&N,&M);
		vector<vector<int> > F(N,vector<int>(M));
		vector<vector<int> > C(N,vector<int>(M));
		REP(y,N)REP(x,M)scanf("%d",&C[y][x]);
		REP(y,N)REP(x,M)scanf("%d",&F[y][x]);
		vector<vector<int> > used(N,vector<int>(M,0));
		queue<Node> que;
		que.push(Node(0,0,0,0));
		while(!que.empty()){
			Node n = que.front();que.pop();
			if(used[n.y][n.x])continue;
			used[n.y][n.x] = 1;
			REP(i,4){
				int ny = n.y+DY[i];
				int nx = n.x+DX[i];
				if(ny<0 || nx<0 || ny>=N || nx>=M)continue;
				int nowHeight = max(F[n.y][n.x],H-n.t);
				int nextHeight = max(F[ny][nx],H-n.t);
				// 1
				if(C[ny][nx]-nextHeight<50 || C[ny][nx]-nowHeight<50)continue;
				// 2
				if(C[n.y][n.x]-nextHeight<50)continue;
				que.push(Node(ny,nx,0,0));
			}
		}
		priority_queue<Node> pq;
		vector<vector<vector<int> > > visited(N,vector<vector<int> >(M,vector<int>(100*H+1,0)));
		REP(y,N)REP(x,M)if(used[y][x])pq.push(Node(y,x,0,0));
		while(!pq.empty()){
			Node n = pq.top();pq.pop();
			if(n.t>100*H || visited[n.y][n.x][n.t])continue;
			visited[n.y][n.x][n.t] = 1;
			if(N-1==n.y && M-1==n.x){
				printf("Case #%d: %.6f\n",cc,(double)n.cost/10.0);
				break;
			}
			REP(i,4){
				int ny = n.y+DY[i];
				int nx = n.x+DX[i];
				if(ny<0 || nx<0 || ny>=N || nx>=M)continue;
				int nowHeight = max(F[n.y][n.x],H-n.t);
				int nextHeight = max(F[ny][nx],H-n.t);
				// 1
				if(C[ny][nx]-nextHeight<50 || C[ny][nx]-nowHeight<50)continue;
				// 2
				if(C[n.y][n.x]-nextHeight<50)continue;
				if(nowHeight-F[n.y][n.x]>=20){
					pq.push(Node(ny,nx,n.cost+10,n.t+10));
				}else{
					pq.push(Node(ny,nx,n.cost+100,n.t+100));
				}
			}
			pq.push(Node(n.y,n.x,n.cost+1,n.t+1));
		}

	}
}

int main(){
	solve();
	return 0;
}
