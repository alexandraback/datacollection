#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)

typedef long long lint;
typedef pair<int,int> pii;
typedef pair<lint,lint> pll;

const int INF = 0x3f3f3f3f;
const lint LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 100;

char board[MAXN][MAXN];
bool open[MAXN][MAXN];
bool foi[MAXN][MAXN];
int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {-1,-1,0,1,1,1,0,-1};
int R,C,M;

int dfs(int a,int b) {
    if(a>R || b>C || a<1 || b<1 || board[a][b] == '*') return 0;
    foi[a][b] = 1;
    int ret = 1;
    if(!open[a][b]) return ret;
    for(int i=0;i<8;++i) {
        int na = a+dx[i], nb = b+dy[i];
        if(!foi[na][nb]) ret += dfs(na,nb);
    }
    return ret;
}

bool check() {
    for(int a=1;a<=R;++a)
        for(int b=1;b<=C;++b)
            open[a][b] = 1;
    for(int a=1;a<=R;++a) {
        for(int b=1;b<=C;++b) {
            foi[a][b] = 0;
            if(board[a][b] == '*') {
                for(int i=0;i<8;++i)
                    open[a+dx[i]][b+dy[i]] = 0;
                open[a][b] = 0;
            }                            
            else board[a][b] = '.';
        }
    }
    int q = -1, numbered=0;
    bool stop = 0;
    for(int a=1;a<=R && !stop;++a) {
        for(int b=1;b<=C && !stop;++b) {
            if(open[a][b]) {
                q = dfs(a,b);
                board[a][b] = 'c';
                stop = 1;
            }
            else if(board[a][b] != '*') numbered++;
        }
    }
    bool found = 0;
    if(q == (R*C-M) || (!stop && numbered == 1)) {
        found = 1;
        if(!stop)
            for(int a=1;a<=R;++a)
                for(int b=1;b<=C;++b)
                    if(!open[a][b] && board[a][b] != '*')
                        board[a][b] = 'c';
    }    
    return found;
}

bool go(int r,int can,int left) {
    if(!left) {
        if(check()) return 1;
        return 0;
    }
    if(r > R || (R-r+1)*can < left) return 0;
    for(int a=1;a<=min(can,left);++a) board[r][a] = '*';
    for(int a=min(can,left);a>0;--a) {
        if(go(r+1,a,left-a)) return 1;
        board[r][a] = '.';
    }
    return 0;
}    

int main() {
    int t=1,T;
    for(scanf("%d",&T);t<=T;++t) {
        debug("t = %d...\n",t);
        scanf("%d%d%d",&R,&C,&M);
        for(int a=1;a<=R;++a)
            for(int b=1;b<=C;++b)
                board[a][b] = '.';
        printf("Case #%d:\n",t);
        if(!go(1,C,M)) printf("Impossible\n");
        else {
            for(int a=1;a<=R;++a) {
                for(int b=1;b<=C;++b) {
                    printf("%c",board[a][b]);
                }
                printf("\n");
            }
        }
    }        
    return 0;
}
