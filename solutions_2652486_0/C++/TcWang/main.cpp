#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int R,N,M,K,value[20],product[20];
bool hit[20],flag;

void sear(int v,int sum) {
    if (v>N) {
        //    printf("%d ",sum);
        for (int i=1;i<=K;i++)
            if (product[i]==sum) hit[i]=true;
        return;
    }
    sear(v+1,sum);
    sear(v+1,sum*value[v]);
}

bool judge() {
    memset(hit,0,sizeof(hit));
    sear(1,1);
    //printf("\n");
    //for (int i=1;i<=K;i++) printf("%d ",hit[i]);
    //printf("\n");
    for (int i=1;i<=K;i++) if (!hit[i]) return false;
    return true;
}

void dfs(int v,int s) {
    if (v>N) {
        //for (int i=1;i<=N;i++) printf("%d ",value[i]);
        //printf("\n");
        if (flag) return;
        if (judge()) {
                flag=true;
                for (int i=1;i<=N;i++) printf("%d",value[i]);
                printf("\n");
        }
        return;
    }
    if (flag) return;
    for (int i=s;i<=M;i++) {
        value[v]=i;
        dfs(v+1,i);
    }

}

int main()
{
    int T;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&T);
    for (int cases=1;cases<=T;cases++) {
        printf("Case #%d:\n",cases);
        scanf("%d%d%d%d",&R,&N,&M,&K);
        for (int r=1;r<=R;r++) {
            for (int i=1;i<=K;i++) scanf("%d",&product[i]);
            //for (int i=1;i<=K;i++) printf("%d ",product[i]);
            flag=false;
            dfs(1,2);
            //for (int i=1;i<=N;i++) printf("%d",value[i]);
            //printf("\n");
        }
    }
    return 0;
}
