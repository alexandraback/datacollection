#include <stdio.h>
#include <algorithm>
using namespace std;

const int G = 30;
int c[100][100];
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

int test(int n,int m,int r){
    if(n>m) swap(n,m);
    int s1 = 0;
    int d1 = 0;
    int md = n+m+n+m-4;
    for( int i=0; i<n; i++ ){
        int s2 = 0;
        int d2 = 0;
        for( int j=0; j<n; j++ ){
            if(i+j>=n) break;
            if(n*m-s1-s2-s1-s2>=r){
                md = min(md,n+m+n+m-4-d1-d2-d1-d2);
            }
            if(i && n*m-s1-s2-s1-s2+i>=r){
                md = min(md,n+m+n+m-4-d1-d2-d1-d2+1);
            }
            if(j && n*m-s1-s2-s1-s2+j>=r){
                md = min(md,n+m+n+m-4-d1-d2-d1-d2+1);
            }
            if(i && j && n*m-s1-s2-s1-s2+i+j>=r){
                md = min(md,n+m+n+m-4-d1-d2-d1-d2+2);
            }
            s2+=j+1;
            d2++;
        }
        s1+=i+1;
        d1++;
    }
    return md;
}

int main(){
    int TT,n,m,r,N,dz,md,d,x,y;
    scanf("%d",&TT);
    for( int tt=0; tt<TT; tt++ ){
        scanf("%d %d %d",&n,&m,&r);
        N = n*m;
        if(N<=G){
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
        }else{
            md = r;
            for( int x=2; x<=n; x++ ){
                for( int y=2; y<=m; y++ ){
                    if(x*y<r) continue;
                    d = test(x,y,r);
                    if(d<md) md = d;
                }
            }
            printf("Case #%d: %d\n",tt+1,md);
        }
    }
    return 0;
}
