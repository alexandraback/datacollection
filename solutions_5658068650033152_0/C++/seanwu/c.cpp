#include <stdio.h>

int c[30][30];
int ss;

void dfs(int x,int y){
    if(c[x][y]) return;
    c[x][y] = 1;
    ss--;
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}

int main(){
    int TT,n,m,r,N,dz,md,d;
    scanf("%d",&TT);
    for( int tt=0; tt<TT; tt++ ){
        scanf("%d %d %d",&n,&m,&r);
        N = n*m;
        md = r;
        for( int z=0; z<(1<<N); z++ ){
            dz = z;
            for( int j=1; j<=m; j++ ){
                c[0][j] = c[n+1][j] = 1;
            }
            d = 0;
            for( int i=1; i<=n; i++ ){
                for( int j=1; j<=m; j++ ){
                    if(dz&1){
                        c[i][j] = 1;
                        d++;
                    }else{
                        c[i][j] = 0;
                    }
                    dz >>= 1;
                }
                c[i][0] = c[i][m+1] = 1;
            }
            if(d>=md) continue;
            ss = N;
            for( int i=1; i<=n; i++ ){
                dfs(i,1);
                dfs(i,m);
            }
            for( int i=1; i<=m; i++ ){
                dfs(1,i);
                dfs(n,i);
            }
            if(ss>=r){
                if(d<md){
                    md = d;
                }
            }
        }
        printf("Case #%d: %d\n",tt+1,md);
    }
    return 0;
}
