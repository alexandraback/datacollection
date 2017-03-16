#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for(int (i)=(s);(i)<(e);++(i))

using namespace std;
typedef long long LL;

int TC;
int N, M, H;
int c[105][105], f[105][105];
int t[105][105], t2[105][105];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int qx[10005], qy[10005],qh,qt;
bool inq[105][105];


int inter(int a,int b,int c,int d){
  //  printf("%d %d %d %d\n", a,b,c,d);
    return max(min(b,d) - max(a,c) , 0);
}

void dfs(int x,int y){
   // printf("dfs %d %d\n", x,y);
    t[x][y] = 0;
    for (int i=0;i<4;++i){
        int fx = x + dx[i];
        int fy = y + dy[i];
        if (fx>=0 && fx<N && fy>=0 && fy<M){
            if (t[fx][fy] > 0 && \
                inter( max(H,f[x][y]), c[x][y], max(H,f[fx][fy]), c[fx][fy] ) >= 50){
                
                dfs(fx,fy);
            }
        }
    }
}

int main(){
    scanf("%d", &TC);
    for (int tc=1;tc<=TC;++tc){
        scanf("%d%d%d", &H, &N, &M);
        
        for (int i=0;i<N;++i){
            for (int j=0;j<M;++j){
                scanf("%d", &c[i][j]);
            }
        }
        
        for (int i=0;i<N;++i){
            for (int j=0;j<M;++j){
                scanf("%d", &f[i][j]);
                
                t2[i][j] = t[i][j] = (1<<30);
            }
        }
        
        dfs(0,0);
        
        for (int h=0;h<=400000;++h){
          //  printf("h = %d\n", h);
            for (int x=0;x<N;++x){
                for (int y=0;y<M;++y){
                    t[x][y] = min(t[x][y], t2[x][y]);
                    t2[x][y] = (1<<30);
                }
            }
            
            if (t[N-1][M-1] <= h) break;
            
            for (int x=0;x<N;++x){
                for (int y=0;y<M;++y){
                    for (int k=0;k<4;++k){
                        int fx = x + dx[k];
                        int fy = y + dy[k];
                        if (!(fx>=0 && fx<N && fy>=0 && fy<M)) continue;
                        
                        if (t[x][y]<=h && inter( max(H-h,f[x][y]), c[x][y], max(H-h,f[fx][fy]), c[fx][fy] ) >= 50){
                        
                            if (H-h-f[x][y] >= 20){
                                t2[fx][fy] = min(t2[fx][fy], h + 10);
                       // printf("inter = %d %d %d %d %d\n", H,h,f[x][y],x,y);
                            }else{
                                t2[fx][fy] = min(t2[fx][fy], h + 100);
                            }
                        }
                    }
                }
            }
        }
        
        printf("Case #%d: %f\n", tc, t[N-1][M-1]/10.0);
    }


    return 0;
}
