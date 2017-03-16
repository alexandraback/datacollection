#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define NAME "Cs0"
#define UsingFile 1

int f[105][105];
int play(int x,int C,int y){
    if(x<=y)return min(y-1,x);
    return max(y-1,x-C*y);
}
void update(int &d,int p){
    if(d==-1)d=p;
    else cmin(d,p);
}
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    scanf("%d",&_T);
    for(int CA=1;CA<=_T;CA++){
        int C,D,V;
        scanf("%d%d%d",&C,&D,&V);
        vector<int>L;
        int ans=0;
        memset(f,-1,sizeof f);
        for(i=1;i<=D;i++){
            scanf("%d",&j);
            L.PB(j);
        }
        sort(L.OP,L.ED);
        if(L[0]!=1){
            L.PB(1);
            sort(L.OP,L.ED);
            ans++;
        }
        reverse(L.OP,L.ED);
        f[0][0]=V;
        for(i=0;i<L.SZ;i++){
            int le=L[i]+1;
            int re=V;
            if(i)re=L[i-1]-1;
            //le~re
            for(j=0;j<=32;j++)if(~f[i][j]){
                update(f[i+1][j],play(f[i][j],C,L[i]));
                int ll=le,rr=re,x=f[i][j];
                for(k=1;k<=32;k++){
                    int tmp=(x+1)%(C+1);
                    int yy=(x+1)/(C+1);
                    int ff=play(x,C,yy);
                    if(tmp)yy++;
                    if(ll<=yy&&yy<=rr){
                        update(f[i+1][j+k],play(ff,C,L[i]));
                        x=ff;rr=yy-1;
                    }else break;
                }
            }
        }
        for(j=0;j<=32;j++)if(f[L.SZ][j]==0){
            ans+=j;
            break;
        }
        printf("Case #%d: %d\n",CA,ans);
    }
    return 0;
}

