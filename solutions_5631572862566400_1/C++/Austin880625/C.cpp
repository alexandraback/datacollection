#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#define MAXN 1005

using namespace std;

int N;
int BFF[MAXN];
vector<int> RBFF[MAXN];
int ingame[MAXN];

int S;

int dfs(int now,int fa)
{
    int res=1;
    for(int i=0;i<RBFF[now].size();i++)
    {
        if(RBFF[now][i]==fa)continue;
        res=max(res,1+dfs(RBFF[now][i],now));
    }
    return res;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        scanf("%d",&N);
        printf("Case #%d:",kase);
        for(int i=0;i<MAXN;i++)RBFF[i].clear();
        for(int i=1;i<=N;i++)
        {
            scanf("%d",BFF+i);
            RBFF[BFF[i]].push_back(i);
        }
        int ANS=0;
        S=0;
        for(int i=1;i<=N;i++)
        {
            int now=i;
            int len=0;
            for(int j=1;j<=N;j++)ingame[j]=0;
            while(1)
            {
                len++;
                ingame[now]=1;
                if(BFF[now]==i)
                {
                    if(len==2)
                    {
                        S+=dfs(now,i)+dfs(i,now);
                    }
                    break;
                }

                if(ingame[BFF[now]]){len=0;break;}
                now=BFF[now];
            }
            ANS=max(ANS,len);
        }
        ANS=max(ANS,S/2);
        printf(" %d\n",ANS);
    }
    return 0;
}
