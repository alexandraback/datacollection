#include<stdio.h>
#define N 30
using namespace std;
int r,c,w,ans,t[N],tt[N];
void solve(){
    int i,j,a,b,ax,bx;
    for(i=0;i<=w;i++) t[i]=tt[i]=0;
    t[w]=w; tt[w]=1;
    for(i=w+1;i<=c;i++){
        t[i]=c; tt[i]=c;
        for(j=0;j<i;j++){
            a=j; b=i-j-1;
            ax=-1; bx=-1;
            if(a>=w){
                ax=t[a]+tt[b]+1;
            }
            if(b>=w){
                bx=tt[a]+t[b]+1;
            }
            tt[i]=tt[i]>tt[a]+tt[b]+1?tt[a]+tt[b]+1:tt[i];
            if(ax!=-1) t[i]=t[i]>ax?ax:t[i];
            if(bx!=-1) t[i]=t[i]>bx?bx:t[i];
        }
    }
    ans=tt[c]*(r-1)+t[c];
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tn,test;
    scanf("%d",&tn);
    for(test=1;test<=tn;test++){
        printf("Case #%d: ",test);
        scanf("%d %d %d",&r,&c,&w);
        solve();
        printf("%d\n",ans);
    }
    return 0;
}
