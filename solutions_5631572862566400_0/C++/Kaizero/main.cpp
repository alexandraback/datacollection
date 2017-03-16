#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int n, D[1010], Q[1010], w[1010], Deg[1010], Res, R2;
bool v[1010];
void Do(int a){
    int x = a, C = 0, M1 = 0, M2 = 0;
    while(1){
        v[x]=true;
        C++;
        if(M1<D[x]){
            M2=M1;M1=D[x];
        }
        else if(M2<D[x])M2=D[x];
        x=w[x];
        if(x==a)break;
    }
    if(C==2){
        Res += M1+M2;
    }
    else{
        R2 = max(R2, C);
    }
}
int main(){
    int TT, TC, i, h, t, x;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&TC);
    for(TT=1;TT<=TC;TT++){
        scanf("%d",&n);
        printf("Case #%d: ",TT);
        h=t=0;
        for(i=1;i<=n;i++)Deg[i]=0,D[i]=1,v[i]=false;
        for(i=1;i<=n;i++){
            scanf("%d",&w[i]);
            Deg[w[i]]++;
        }
        for(i=1;i<=n;i++)if(!Deg[i])Q[++t] = i;
        while(h<t){
            x = Q[++h];
            Deg[w[x]]--;
            if(D[w[x]]<D[x]+1)D[w[x]]=D[x]+1;
            if(!Deg[w[x]])Q[++t] = w[x];
        }
        for(i=1;i<=t;i++)v[Q[i]]=true;
        Res = R2 = 0;
        for(i=1;i<=n;i++){
            if(!v[i]){
                Do(i);
            }
        }
        printf("%d\n",max(Res,R2));
    }
}
