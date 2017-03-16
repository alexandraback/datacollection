//Fruit of Light
//FoL CC
//Apple Strawberry

#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

#define For(i, n) for(int i = 0; i<(n); ++i)
#define ForEach(it, i) for(typeof i.begin() it = i.begin(); it!=i.end(); ++it)
#define INF 1023456789

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;

int N,M,V, strop[147][147], dno[147][147];
int stwas[147][147];
int dist[147][147];
vi starters;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int when_can_go(int y1, int x1, int y2, int x2, int time){
    if (y2<0 || x2<0 || y2>=N || x2>=M) return -1;
    int h1 = strop[y1][x1];
    int f1 = dno[y1][x1];
    int h2 = strop[y2][x2];
    int f2 = dno[y2][x2];
    int wl = V-time;
    
    if(h2-max(f1,f2)<50) return -1;
    if(h1-f2<50) return -1;
    return max(wl+50-h2,0);
}
bool can_go(int y1, int x1, int y2, int x2, int time){
    if (when_can_go(y1,x1,y2,x2,time)==0) return 1;
    return 0;
}
int move_time(int y, int x, int time){
   return (dno[y][x]+20<=V-time)?10:100;
}

void find_starters(){
    For(i,N) For(j,M) stwas[i][j] = 0;
    queue<int> F;
    stwas[0][0] = 1;
    F.push(0);
    F.push(0);
    starters.push_back(0);
    starters.push_back(0);

    int x,y, nx,ny;
    while(!F.empty()){
        y = F.front(); F.pop();
        x = F.front(); F.pop();
        For(d,4){
            ny = y+dy[d];
            nx = x+dx[d];
            if ((can_go(y,x,ny,nx,0)) && (stwas[ny][nx]==0)){
                stwas[ny][nx] = 1;
                F.push(ny);
                F.push(nx);
                starters.push_back(ny);
                starters.push_back(nx);
            }
        }
    }
}

void search_path(){
    priority_queue<piii> Q;
    For(i,N) For(j,M) {
        dist[i][j] = INF;
        stwas[i][j] = 0;
    }
    For(i,starters.size()/2){
        Q.push(piii(-0, pii(starters[2*i], starters[2*i+1])));
        dist[starters[2*i]][starters[2*i+1]] = 0;
    }
    int x,y,t, nx,ny,nt;
    while(!Q.empty()){
        t = -Q.top().first;
        y = Q.top().second.first;
        x = Q.top().second.second;
        Q.pop();
        if (stwas[y][x]) continue;
        stwas[y][x] = 1;

        For(d,4){
            ny = y+dy[d];
            nx = x+dx[d];
            if (when_can_go(y,x,ny,nx,t)>=0){
                nt = t + when_can_go(y,x,ny,nx,t);
                nt += move_time(y,x,nt);
                if (nt>=dist[ny][nx]) continue;
                dist[ny][nx] = nt;
                Q.push(piii(-nt,pii(ny,nx)));
            }
        }
    }
}


int extra(){
    scanf("%d%d%d",&V,&N,&M);
    For(i,N) For(j,M) scanf("%d", strop[i]+j);
    For(i,N) For(j,M) scanf("%d", dno[i]+j);
    
    starters = vi(0,0);
    find_starters();
    search_path();
    printf("%.1lf\n",0.1*dist[N-1][M-1]);
}

int main(){
    int T;
    scanf("%d",&T);
    For(i,T){
        printf("Case #%d: ",i+1);
        extra();
    }
}
