#include <stdio.h>

double c[1000];

int main(){
    int tt,TT,n,i,j,k;
    double s,L,R,M,x,z;
    scanf("%d",&TT);
    for( tt=0; tt<TT; tt++ ){
        scanf("%d",&n);
        s=0;
        for( i=0; i<n; i++ ){ 
            scanf("%lf",&c[i]);
            s+=c[i];
        }
        printf("Case #%d:",tt+1);
        for( i=0; i<n; i++ ) {
            L=0;
            R=1;
            for( j=0; j<30; j++ ){
                M=(L+R)/2;
                x=c[i]+s*M;
                z=1-M;
                for( k=0; k<n; k++ ) {
                    if(k==i) continue;
                    if(c[k]<x){
                        z-=(x-c[k])/s;
                    }
                    if(z<0) break;
                }
                if(k==n){
                    L=M;
                }else{
                    R=M;
                }
            }
            printf(" %.6f",R*100);
        }
        puts("");
    }
    return 0;
}
