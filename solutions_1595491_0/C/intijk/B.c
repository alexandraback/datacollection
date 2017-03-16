#include <stdio.h>
int main()
{
    int T,N,S,p,i,j,m;
    double x;
    int t[105];
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d%d%d",&N,&S,&p);
        for(j=0;j<N;j++){
            scanf("%d",&t[j]);
        }
        
        m=0;
        for(j=0;j<N;j++){
            if(t[j]%3==0){
                if(t[j]/3>=p){
                    m++;
                }else if(t[j]/3+1>=p && S>0 && t[j]>0){
                    m++;
                    S--;
                }
            }else if(t[j]%3==1){
                if(t[j]/3+1>=p){
                    m++;
                }
            }else if(t[j]%3==2){
                if(t[j]/3+1>=p){
                    m++;
                }else if(t[j]/3+2>=p && S>0){
                    m++;
                    S--;
                }
            }
        }
        printf("Case #%d: %d\n",i+1,m);
    }
}
