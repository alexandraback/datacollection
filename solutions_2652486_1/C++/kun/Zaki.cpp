#include<algorithm>
#include<cstdio>
using namespace std;
int r,n,m,k,d,T,od;
long long x[13],g[200],s[] = {2,3,5,7},ct[4],tmp,tmp2,hv6,tmp3;
int main(){
    freopen("C-small-2-attempt2.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    printf("Case #1:\n");
        scanf("%d%d%d%d",&r,&n,&m,&k);
    while(r){
        for(int i=0;i<k;i++){
            scanf("%lld",&x[i]);
        }
        hv6=0;
        for(int i=0;i<4;i++){
            ct[i] = 0;
            for(int j=0;j<k;j++){
                 tmp = x[j];
                 tmp2 = 0;
                 while(tmp%s[i]==0){
                    tmp2++; tmp/=s[i];
                 }
                 ct[i] = max(tmp2,ct[i]);
            }
        }
        od = 0;
        for(int i=0;i<ct[3];i++) g[od++] = 7;
        for(int i=0;i<ct[2];i++) g[od++] = 5;
        for(int i=0;i<ct[1];i++) g[od++] = 3;
        while(ct[0]){
            if(ct[0] > 2) g[od++] = 8,ct[0]-=3;
            else if(ct[0] > 1) g[od++] = 4,ct[0] -=2;
            else g[od++] = 2,ct[0]--;
        } 
        while(od<n){
            g[od++] = 2;
        }
        while(od > n){
            for(int i=0;i<n;i++){
                if(g[i] == 3 && g[od-1]%2 == 0 ){
                    if(g[od]>2) g[od]/=2;
                    else od--;
                    g[i] = 6;
                    goto dd;
                }
            }
            dd:;
        }
        int u = 1;
        while(u){
            u = 0;
            for(int i=0;i<n;i++){
                if(g[i] == 8){
                    for(int j=i;j<n-1;j++)
                        if(g[j] == 2){
                            g[i] = g[j] = 4; u = 1;goto hh; 
                        }
                }
                
            }
            hh:;
        }
        for(int i=0;i<n;i++)
            printf("%lld",g[i]);printf("\n");
        r--;
    }
    return 0;
}
//
