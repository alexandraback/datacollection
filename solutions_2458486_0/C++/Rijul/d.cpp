#pragma warning (disable: 4786)
#pragma comment (linker, "/STACK:0x800000")

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<map>
#include<vector>
using namespace std;

#define maxm 50
#define maxn (1<<21)

int on(int n,int k){
    return (n|(1<<k));
}
int off(int n,int k){
    return (n-(n&(1<<k)));
}
bool chck(int n,int k){
    return (n&(1<<k));
}

vector<int>v[maxm];
map<int,int>map1;
int K,n,req[maxm],dp[maxn],pre[maxn];
bool fl[maxn];

int cal(int mask);
void print(int mask);

int main(){

    int i,j,k,l,test,t=1;

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d",&test);

    while(test--){

        map1.clear();
        memset(fl,0,sizeof(fl));
        for(i=0;i<=n;i++){
            v[i].clear();
        }

        scanf("%d %d",&K,&n);

        for(i=1;i<=K;i++){
            scanf("%d",&j);
            map1[j]++;
        }

        for(i=0;i<n;i++){
            scanf("%d %d",&req[i],&k);
            for(j=1;j<=k;j++){
                scanf("%d",&l);
                v[i].push_back(l);
            }
        }

        printf("Case #%d:",t++);
        if(cal(0)){
            print(0);
            printf("\n");
        }
        else printf(" IMPOSSIBLE\n");

    }

    return 0;
}

void print(int mask){

    if(mask==(1<<n)-1) return ;

    printf(" %d",pre[mask]+1);
    print(on(mask,pre[mask]));
}

int cal(int mask){

    if(mask==(1<<n)-1) return 1;

    if(fl[mask]) return dp[mask];
    fl[mask]=1;

    int i,j,k,l;
    for(i=0;i<n;i++){
		if(chck(mask,i)) continue;
        k=req[i];
        if(map1[k]){
            map1[k]--;
            for(j=0;j<v[i].size();j++){
                l=v[i][j]; map1[l]++;
            }
            if(cal(on(mask,i))){
                pre[mask]=i; return dp[mask]=1;
            }
            map1[k]++;
            for(j=0;j<v[i].size();j++){
                l=v[i][j]; map1[l]--;
            }
        }
    }

    return dp[mask]=0;

}
