#include <stdio.h>

int hc[1000][1000];
int hf[1000][1000];
int c[1000][1000][4];
int mm[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int dis[1000][1000];
int que[1<<20][2];
int inq[1000][1000];

int main(){
    int tt,TT,n,m,H,i,j,k,x,y,d,p,q,dx,dy;
    scanf("%d",&TT);
    for( tt=0; tt<TT; tt++ ) {
        scanf("%d %d %d",&H,&n,&m);
        for( i=0; i<n; i++ ) {
            for( j=0; j<m; j++ ) {
                scanf("%d",&hc[i][j]);
            }
        }
        for( i=0; i<n; i++ ) {
            for( j=0; j<m; j++ ) {
                scanf("%d",&hf[i][j]);
            }
        }
        for( i=0; i<n; i++ ) {
            for( j=0; j<m; j++ ) {
                for( k=0; k<4; k++ ) {
                    x=i+mm[k][0];
                    y=j+mm[k][1];
                    if(x>=0 && y>=0 && x<n && y<m){
                        if(hf[i][j]<=hc[x][y]-50 && hf[x][y]<=hc[x][y]-50 && hf[x][y]<=hc[i][j]-50){
                            d=H-(hc[x][y]-50); //H-d<=hc[x][y]-50
                            if(d<0) d=0;
                            c[i][j][k]=d;
                        }else{
                            c[i][j][k] = 1000000000;
                        }
                    }else{
                        c[i][j][k] = 1000000000;
                    }
                }
            }
        }
        que[0][0]=que[0][1]=0;
        p=0; q=-1;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                dis[i][j]=1000000000;
                inq[i][j]=0;
            }
        }
        dis[0][0]=0;
        inq[0][0]=1;
        while(p!=q){
            q=(q+1)&((1<<20)-1);
            x=que[q][0];
            y=que[q][1];
            inq[x][y]=0;
            for(k=0;k<4;k++){
                if(c[x][y][k]==1000000000) continue;
                d=dis[x][y]>c[x][y][k]?dis[x][y]:c[x][y][k];
                if(d!=0){
                    if(H-d>=hf[x][y]+20){
                        d+=10;
                    }else{
                        d+=100;
                    }
                }
                dx=x+mm[k][0];
                dy=y+mm[k][1];
                if(d<dis[dx][dy]){
                    dis[dx][dy]=d;
                    if(!inq[dx][dy]){
                        inq[dx][dy]=1;
                        p=(p+1)&((1<<20)-1);
                        que[p][0]=dx;
                        que[p][1]=dy;
                    }
                }
            }
        }
        printf("Case #%d: %.1f\n",tt+1,dis[n-1][m-1]/10.0);
    }
    return 0;
}
