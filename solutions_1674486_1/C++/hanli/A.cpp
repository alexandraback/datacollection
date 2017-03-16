#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#define MAXN 1005
using namespace std;
vector<int> myvec[MAXN];
void init(int n)
{
    int i;
    for(i=0;i<=n;i++)
        myvec[i].clear();
}
bool flag;
bool used[MAXN];
void dfs(int x)
{
    int i,temp;
    used[x]=1;
    for(i=0;i<myvec[x].size();i++)
    {
        temp=myvec[x][i];
        if(used[temp]==1)
        {
            flag=1;
            return;
        }
        else dfs(temp);
    }
}
int main()
{
    int t;
    int n;
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int i,j;
    scanf("%d",&t);
    int k;
    int ttt;
    int casenum;
    for(casenum=1;casenum<=t;casenum++)
    {
        
        scanf("%d",&n);
        init(n);
        for(i=1;i<=n;i++)
        {
       
            scanf("%d",&k);
            for(j=1;j<=k;j++)
            {
                scanf("%d",&ttt);
                myvec[i].push_back(ttt);
            }
        }
        flag=0;
        for(i=1;i<=n;i++)
        {
            flag=0;
           memset(used,0,sizeof(used));
           dfs(i);
           if(flag==1)
               break;
        }
        if(flag==1)
        {
            printf("Case #%d: Yes\n",casenum);
        }else  printf("Case #%d: No\n",casenum);
    }
    
    
    return 0;
}
