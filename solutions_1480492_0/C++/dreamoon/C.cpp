#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<set>
#include<queue>
#include<map>
using namespace std;
int S[64],P[64],cn,N,ty[64];
#define pb push_back
const double eps=1e-9;
struct data{
    int x,y;
    double l,r;
    bool operator<(const data& b)const{return l<b.l;}
    bool in(double v){return l<v&&v<r;}
}co[2555];
// S[x]<S[y]
void test(int x,int y){
    if(P[y]>=P[x]+5)return;
    co[cn++]=(data){x,y,max(0.,(P[x]-P[y]-5)*1./(S[y]-S[x])),(P[x]-P[y]+5)*1./(S[y]-S[x])};
}
vector<int>e[64],emp;
bool dfs(int x,int v){
    if(ty[x]){
        if(ty[x]!=v)return 0;
        return 1;
    }
    ty[x]=v;
    for(int i=0;i<e[x].size();i++){
        if(!dfs(e[x][i],-v))return 0;
    }
    return 1;
}
int kerker,fil[2555];
bool check(double v){
    int i;
    double mi[64];
    kerker++;
    for(i=0;i<N;i++)mi[i]=1e9;
    for(i=0;i<N;i++)e[i]=emp;
    for(i=0;i<cn;i++){
        if(co[i].in(v)){
            fil[i]=kerker;
            e[co[i].x].pb(co[i].y);
            e[co[i].y].pb(co[i].x);
            mi[co[i].x]=min(mi[co[i].x],co[i].l);
            mi[co[i].y]=min(mi[co[i].y],co[i].l);
        }
    }
    for(i=cn-1;i>=0;i--){
        if(co[i].l<=v&&co[i].r>mi[co[i].x]+eps){
            mi[co[i].x]=min(mi[co[i].x],co[i].l);
        }
        if(co[i].l<=v&&co[i].r>mi[co[i].y]+eps){
            mi[co[i].y]=min(mi[co[i].y],co[i].l);
        }
    }
    for(i=0;i<cn;i++){
        if(fil[i]==kerker)continue;
        if((co[i].l<=v&&co[i].r>mi[co[i].x]+eps)||(co[i].l<=v&&co[i].r>mi[co[i].y]+eps)){
            e[co[i].x].pb(co[i].y);
            e[co[i].y].pb(co[i].x);
        }
    }
    memset(ty,0,sizeof(ty));
    for(i=0;i<N;i++){
        if(ty[i]==0){
            if(dfs(i,1)==0)return 0;
        }
    }
    return 1;
}
int main(){
    int T,i,j,k,cs=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(i=0;i<N;i++){
            char tmp[4];
            scanf("%s%d%d",tmp,&S[i],&P[i]);
        }
        cn=0;
        for(i=0;i<N;i++)
            for(j=i+1;j<N;j++){
                if(S[i]==S[j]){
                    if(abs(P[i]-P[j])<5)co[cn++]=(data){i,j,-1e12,1e12};
                }
                else if(S[i]<S[j])test(i,j);
                else test(j,i);
            }
        sort(co,co+cn);
        //for(i=0;i<cn;i++){
        //    printf("(%d,%d,%lf,%lf)\n",co[i].x,co[i].y,co[i].l,co[i].r);
        //}
        for(i=0;i<cn;i++){            
            if(!check(co[i].l+eps))break;
        }
        printf("Case #%d: ",++cs);
        if(i==cn)puts("Possible");
        else printf("%.6lf\n",co[i].l);
    }
    return 0;
}
