#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int tm[2000007],s[27];
int resa[27],resb[27];
int n;
int main(){
    int t;
    int i,j,k,a,b,x,y;
    //freopen("in.txt","r",stdin);
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&t);
    for(j=1;j<=t;j++){
        memset(tm,-1,sizeof(tm));
        memset(resa,-1,sizeof(resa));
        memset(resb,-1,sizeof(resb));
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",s+i);
        }
        for(i=0;i<(1<<n);i++){
            a=0;
            for(k=0;k<n;k++){
                if(i & (1<<k))
                    a+=s[k];
            }
            if(tm[a]==-1) tm[a]=i;
            else{
                a=tm[a];
                b=i;
                break;
            }
        }
        printf("Case #%d:\n",j);
        for(i=0,x=0,y=0;i<n;i++){
            if(a & (1<<i))
                resa[x++]=s[i];
            if(b & (1<<i))
                resb[y++]=s[i];
        }
        for(i=0;i<x;i++){
            printf("%d",resa[i]);
            if(i==x-1) printf("\n");
            else printf(" ");
        }
        for(i=0;i<y;i++){
            printf("%d",resb[i]);
            if(i==y-1) printf("\n");
            else printf(" ");
        }
    }
}
