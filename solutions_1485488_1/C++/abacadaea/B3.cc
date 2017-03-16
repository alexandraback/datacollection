#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <assert.h>
#include <string>
#include <fstream>
#include <queue>
#include <deque>

using namespace std;

//ifstream fin("B3.in");
//ifstream fin("B-small-attempt0.in");
ifstream fin("B-large.in");
FILE * fout = fopen("B3.out","w");

struct Loc{
    int x,y,h;
    Loc(int a, int b, int c){x=a; y=b; h=c;}
    Loc(){}  
};

bool operator<(Loc a, Loc b){
    return a.h<b.h;
}

const int MAX=105, inf=1000000000, mx[]={-1,1,0,0},my[]={0,0,-1,1};
int N,M,H;
int board[MAX][MAX][2];
int best[MAX][MAX];
bool vis[MAX][MAX];

priority_queue<Loc> pq;

bool leg(int a, int b){
    return (a>=0 and b>=0 and a<N and b<M);
}

bool bad(int a, int b){
    return (board[a][b][1]-board[a][b][0]<50);
}

int minl(int a, int b){
    return (board[a][b][1]-50);
}

bool legal(int c, int d,int a, int b, int h){
    int lo=max(max(h,board[a][b][0]),board[c][d][0]);
    //cout << a << " " << b << " " << h <<" " << lo << " " << board[a][b][1] << endl;
    int hi=min(board[a][b][1],board[c][d][1]);
    return (hi>=lo+50);
}

bool wlegal(int c,int d, int a, int b, int h){
    if(h<20+board[c][d][0]) return false;
    //return (board[a][b][1]>=h+50);
    return (legal(c,d,a,b,h));
}

void ff(){
    bzero(vis,sizeof(vis));
    deque<Loc> q;
    q.clear();
    q.push_back(Loc(0,0,H));
    best[0][0]=H;
    vis[0][0]=true;
    while(!q.empty()){
	Loc cur=q[0]; q.pop_front();
	//cout << cur.x << " " << cur.y << endl;
	pq.push(cur);
	for(int i=0; i<4; i++){
	    int nx=cur.x+mx[i], ny=cur.y+my[i];
	    if(!leg(nx,ny)) continue;
	    if(vis[nx][ny]) continue;
	    if(!legal(cur.x,cur.y,nx,ny,H)) continue;
	    vis[nx][ny]=true;
	    q.push_back(Loc(nx,ny,H));
	    best[nx][ny]=H;
	}
    }
}

void djik(){
    bzero(vis,sizeof(vis));
    while(!pq.empty()){
	Loc cur=pq.top(); pq.pop();
	if(vis[cur.x][cur.y]) continue;
	vis[cur.x][cur.y]=true;
	int ch=best[cur.x][cur.y];
	for(int i=0; i<4; i++){
	    int nx=cur.x+mx[i], ny=cur.y+my[i];
	    if(!leg(nx,ny)) continue;
	    if(vis[nx][ny]) continue;
	    if(bad(nx,ny)) continue;
	    int nh=min(ch, minl(nx,ny));
	    int dh=inf;
	    if(legal(cur.x,cur.y,nx,ny,nh)){
		dh=100;
	    }
	    if(wlegal(cur.x,cur.y,nx,ny,nh)){
		dh=10;
	    }
	    //cout << cur.x << " " << cur.y << " " << nx << " "<< ny << " "<<nh << endl;
	    //assert(dh!=inf);
	    if(dh==inf) continue;
	    if(best[nx][ny]<nh-dh){
		best[nx][ny]=nh-dh;
		pq.push(Loc(nx,ny,best[nx][ny]));
	    }
	}
    }
}

void solve(int t){
    fin >> H>> N >> M;
    for(int k=1; k>=0; k--){
	for(int i=0; i<N; i++){
	    for(int j=0; j<M; j++){
		fin >> board[i][j][k];	    
		best[i][j]=-inf;
	    }
	}
    }
    //assert(pq.empty());
    
    bzero(vis,sizeof(vis));
    ff();
    djik();
    fprintf(fout,"Case #%d: ",t);
    double res = ((double)H-(double)best[N-1][M-1])/10.0;
    fprintf(fout,"%.1f\n", res);
}

int main(){
    int T; fin >> T;
    for(int i=0; i<T; i++){
	solve(i+1);
    }
}
