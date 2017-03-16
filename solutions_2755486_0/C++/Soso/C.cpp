#include<cstdio>
#include<algorithm>
using namespace std;
int T,n,b[1000000],d,dd,ds,dp,e,w,s,N,k,ac,tmn,tmx,p,ok;
struct attack{
       int d,w,e,s;
       bool operator < (const attack& tt) const{return d<tt.d;}
}a[1000000];
int mn(int u,int v){
    if (u<v) return u;
    return v;    
}
int mx(int u,int v){
    return ((u>v)?u:v);    
}
int main(){
    scanf("%d",&T);
    for (int o=1; o<=T; o++){
        scanf("%d",&N); k=0; tmn=0;
        for (int i=1; i<=N; i++){
            scanf("%d%d%d%d%d%d%d%d",&d,&n,&w,&e,&s,&dd,&dp,&ds);
            for (int j=1; j<=n; j++){
                a[++k].d=d; a[k].w=w; a[k].e=e; a[k].s=s;
                tmn=mn(tmn,a[k].w);
                d+=dd; w+=dp; e+=dp; s+=ds;
            }
        }
        sort(a+1,a+k+1);
        for (int i=1; i<=k; i++){
            a[i].w-=tmn; a[i].e-=tmn;    
            a[i].w*=2; a[i].e*=2;
        }
        for (int i=0; i<=20000; i++) b[i]=0;
        ac=1; p=1;
        for (int i=2; i<=k; i++){
            if (a[i].d!=a[i-1].d){
               for (int j=p; j<i; j++){
                   for (int l=a[j].w; l<=a[j].e; l++){
                       b[l]=mx(b[l],a[j].s);
                   }
               }
               p=i;                      
            }
            ok=0;
            for (int j=a[i].w; j<=a[i].e; j++)
                if (b[j]<a[i].s) ok=1;
            ac+=ok;
        }
        printf("Case #%d: %d\n",o,ac);
    }
    return 0;
}
