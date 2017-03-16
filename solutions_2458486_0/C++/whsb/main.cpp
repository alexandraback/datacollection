#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

struct node
{
    int key;
    int num;
    int who[42];
}chest[30];

int N;
int key[250];
int ans[30];

bool used[(1<<20)+8];

bool dfs(int H,int state)
{
    if(used[state]) return false;
    used[state]=true;

    if(H==N)
    {
        return true;
    }

    for(int i=0;i<N;i++)
    {
        if((state&(1<<i))==0&&key[chest[i].key]>0)
        {
            key[chest[i].key]--;
            for(int j=0;j<chest[i].num;j++) key[chest[i].who[j]]++;
            ans[H]=i;
            if(dfs(H+1,state|(1<<i))) return true;
            for(int j=0;j<chest[i].num;j++) key[chest[i].who[j]]--;
            key[chest[i].key]++;
        }
    }
    return false;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int T;
    int K,x;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        memset(key,0,sizeof(key));
        memset(used,0,sizeof(used));
        scanf("%d%d",&K,&N);
        for(int i=0;i<K;i++)
        {
            scanf("%d",&x);
            key[x]++;
        }
        for(int i=0;i<N;i++)
        {
            scanf("%d",&chest[i].key);
            scanf("%d",&chest[i].num);
            for(int j=0;j<chest[i].num;j++)
            {
                scanf("%d",&chest[i].who[j]);
            }
        }
        printf("Case #%d:",cas);
        if(dfs(0,0))
        {
            for(int i=0;i<N;i++) printf(" %d",ans[i]+1);
            printf("\n");
        }
        else printf(" IMPOSSIBLE\n");
    }
    return 0;
}
