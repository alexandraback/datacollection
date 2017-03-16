#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <set>
#include <stack>
#include <queue>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FE(a,b) for(__typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<int, int>
#define PDI pair<double, pair<int, int> >
#define x first
#define y second

using namespace std;

int N, M;
double H, F[110][110], C[110][110], T[110][110];
bool V[110][110];
bool V2[110][110];
priority_queue<PDI> Q;
PII loc;
double time1, time2;

bool inb(int x, int y){
    return 0<=x && x<N && 0<=y && y<M;
}

void visit(int x, int y){
    if(V[x][y] || max(F[loc.x][loc.y], F[x][y]) + 50.0 > min(C[loc.x][loc.y], C[x][y]))
        return;
    time2 = max(time1, (H - C[x][y] + 50.0) / 10.0);
    if(H - time2 * 10.0 - F[loc.x][loc.y] >= 20.0)
        time2 += 1.0;
    else
        time2 += 10.0;
    Q.push(PDI(-time2, PII(x,y)));
}

int t;

void dfs(int,int);

void visit2(int x, int y, int lx, int ly){
    if(V2[x][y] || max(F[lx][ly], F[x][y]) + 50.0 > min(C[lx][ly], C[x][y]) || H + 50.0 > C[x][y])
        return;
    dfs(x, y);
}

void dfs(int x, int y){
    V2[x][y] = 1;
    if(inb(x+1, y)) visit2(x+1, y, x, y);
    if(inb(x-1, y)) visit2(x-1, y, x, y);
    if(inb(x, y+1)) visit2(x, y+1, x, y);
    if(inb(x, y-1)) visit2(x, y-1, x, y);
}

int main(){
	scanf("%d", &t);
	FWD(ttt,1,t+1){
		scanf("%lf %d %d", &H, &N, &M);
		FWD(i,0,N)
            FWD(j,0,M)
                scanf("%lf", &C[i][j]);
    	FWD(i,0,N)
            FWD(j,0,M){
                scanf("%lf", &F[i][j]);
                V[i][j] = 0;
                V2[i][j] = 0;
            }
        dfs(0,0);
        FWD(i,0,N)
            FWD(j,0,M)
                if(V2[i][j])
                    Q.push(PDI(0.0, PII(i,j)));
        while(!Q.empty()){
            loc = Q.top().y;
            time1 = -Q.top().x;
            Q.pop();
            if(V[loc.x][loc.y])
                continue;
            T[loc.x][loc.y] = time1;
            V[loc.x][loc.y] = 1;
            if(inb(loc.x+1, loc.y)) visit(loc.x+1, loc.y);
            if(inb(loc.x-1, loc.y)) visit(loc.x-1, loc.y);
            if(inb(loc.x, loc.y+1)) visit(loc.x, loc.y+1);
            if(inb(loc.x, loc.y-1)) visit(loc.x, loc.y-1);
        }
        printf("Case #%d: %lf\n", ttt, T[N-1][M-1]+0.0000000000001);
	}
	return 0;
}
