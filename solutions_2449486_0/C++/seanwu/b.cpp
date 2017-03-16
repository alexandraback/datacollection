#include <stdio.h>

int c[100][100];
int u[100][100];

int main(){
    int tt,TT,n,m,i,j,k,f,flag;
    scanf("%d",&TT);
    for( tt=0; tt<TT; tt++ ){
        scanf("%d %d",&n,&m);
        for( i=0; i<n; i++ ){
            for( j=0; j<m; j++ ){
                scanf("%d",&c[i][j]);
                u[i][j]=0;
            }
        }
        flag=1;
        for( i=1; i<=100; i++ ){
            for( j=0; j<n; j++ ){
                f=0;
                for( k=0; k<m; k++ ){
                    if(c[j][k]<=i){
                        f++;
                    }
                }
                if(f==m){
                    for( k=0; k<m; k++ ){
                        u[j][k]=i;
                    }
                }
            }
            for( j=0; j<m; j++ ){
                f=0;
                for( k=0; k<n; k++ ){
                    if(c[k][j]<=i){
                        f++;
                    }
                }
                if(f==n){
                    for( k=0; k<n; k++ ){
                        u[k][j]=i;
                    }
                }
            }
            for( j=0; j<n; j++ ){
                for( k=0; k<m; k++ ){
                    if(c[j][k]<=i && u[j][k]!=i){
                        flag=0;
                        goto out;
                    }
                }
            }
        }
out:
        printf("Case #%d: %s\n",tt+1,flag?"YES":"NO");
    }
    return 0;
}
