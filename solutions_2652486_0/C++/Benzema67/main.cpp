#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int val[100];
int R,N,M,K;
int main(){
    int t,T;
    int r,i,j,k;
    int dd[10];
    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("a.txt","w",stdout);
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d %d %d %d",&R,&N,&M,&K);
        printf("Case #1:\n");
        for(r=1;r<=R;r++){
            for(i=1;i<=K;i++) scanf("%d",&val[i]);
            for(i=1;i<1000;i++){
                j=i;
                int cou=0;
                while(j){
                    dd[cou++]=j%10;
                    j/=10;
                }
                if(cou!=N)continue;
                for(j=0;j<cou;j++) if(!(dd[j]>=2 && dd[j]<=M)) break;
                if(j!=cou) continue;
                bool vis[100];
                memset(vis,0,sizeof(vis));
                for(int kk=1;kk<=K;kk++){
                    if(val[kk]==1) vis[kk]=1;
                }
                for(j=0;j<cou;j++)
                    for(k=j+1;k<cou;k++){
                        int tem=dd[j]*dd[k];
                        for(int kk=1;kk<=K;kk++) if(val[kk]==tem) vis[kk]=1;
                    }
                for(j=0;j<cou;j++){
                    for(k=1;k<=K;k++) if(val[k]==dd[j]) vis[k]=1;
                }
                for(k=1;k<=K;k++) if(val[k]==dd[0]*dd[1]*dd[2]) vis[k]=1;

                for(j=1;j<=K;j++) if(vis[j]==0) break;
                if(j==K+1)break;
            }
            printf("%d\n",i);
        }
        //printf("Case #%d: %d\n",t,ans);
    }

    return 0;
}
