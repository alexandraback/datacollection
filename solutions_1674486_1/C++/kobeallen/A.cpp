#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int N=1010;

int nodeNum;
bool hash[N];
bool edge[N][N];

bool DFS(int now)
{
    hash[now]=true;
    int i;
    for(i=1;i<=nodeNum;i++)
    {
        if(edge[now][i]==true)
        {
            if(hash[i]==false)
            {
                int result=DFS(i);
                //printf("%d %d\n",now, result);
                if(result==true)
                    return true;
            }
            else
                return true;
        }
    }
    return false;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w+",stdout);
    int i,j,k;
    int edgeNum;
    int inDegree[N];
    queue<int> Q;
    int cas,c=1;
    scanf("%d",&cas);
    while(c<=cas)
    {
        memset(edge, 0, sizeof(edge));
        memset(inDegree, 0, sizeof(inDegree));
        scanf("%d",&nodeNum);
        for(i=1;i<=nodeNum;i++)
        {
            scanf("%d",&edgeNum);
            for(j=0;j<edgeNum;j++)
            {
                scanf("%d",&k);
                inDegree[k]++;
                edge[i][k]=true;
            }
        }
        bool ans=false;
        for(i=1;i<=nodeNum;i++)
        {
            if(inDegree[i]==0)
                Q.push(i);
        }
        while(!Q.empty())
        {
            memset(hash,0,sizeof(hash));
            int root=Q.front();
            Q.pop();
            if(DFS(root)==true)
            {
                ans=true;
                break;
            }
        }
        if(ans==true)
            printf("Case #%d: Yes\n",c);
        else
            printf("Case #%d: No\n",c);
        c++;
    }
    return 0;
}
