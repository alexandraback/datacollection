#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=11;
struct PP{
    int j,p,s;
    PP(int j=-1,int p=-1,int s=-1):j(j),p(p),s(s){}
}pp[N*N*N];
int num[3][N][N];
int n,j,p,s,k;
int aa[N*N*N],n1;
int ans[N*N*N],n2;

void dfs(int id){
    //printf("%d\n",id);
    if(id==n){
        if(n1>n2){
            for(int i=0;i<n1;i++)ans[i]=aa[i];
            n2=n1;
        }
        return ;
    }
    int x=num[0][pp[id].j][pp[id].p]+1;
    int y=num[1][pp[id].j][pp[id].s]+1;
    int z=num[2][pp[id].p][pp[id].s]+1;
    if(x<=k&&y<=k&&z<=k){
        num[0][pp[id].j][pp[id].p]++;
        num[1][pp[id].j][pp[id].s]++;
        num[2][pp[id].p][pp[id].s]++;
        aa[n1++]=id;
        dfs(id+1);
        n1--;
        num[0][pp[id].j][pp[id].p]--;
        num[1][pp[id].j][pp[id].s]--;
        num[2][pp[id].p][pp[id].s]--;
    }
    dfs(id+1);
}

int main(){
#ifdef gh546
freopen("b.in","r",stdin);
freopen("b.out","w",stdout);
#endif // gh546
    int T;scanf("%d",&T);
    int cas=1;
    while(T--){
        scanf("%d%d%d%d",&j,&p,&s,&k);
        n=0;
        for(int i1=0;i1<j;i1++){
            for(int p1=0;p1<p;p1++){
                for(int s1=0;s1<s;s1++){
                    pp[n++]=PP(i1,p1,s1);
                }
            }
        }
        //printf("%d\n",n);
        memset(num,0,sizeof(num));
        n1=0;n2=0;
        dfs(0);
        printf("Case #%d: %d\n",cas++,n2);
        for(int i=0;i<n2;i++){
            printf("%d %d %d\n",pp[ans[i]].j+1,pp[ans[i]].p+1,pp[ans[i]].s+1);
        }
    }
    return 0;
}
