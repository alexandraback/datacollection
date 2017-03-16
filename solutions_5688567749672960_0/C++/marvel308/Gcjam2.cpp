#include<stdio.h>
#include<queue>
using namespace std;
bool visited[1000005]={0};
int ans[1000005]={0};
int rev(int x)
{
    int s=0;
    while(x>0)
    {
        s=s*10+x%10;
        x/=10;
    }
    return s;
}
int main()
{
    int t,i,test=1;
    scanf("%d",&t);
    queue<int> q;
    q.push(1);
    visited[1]=1;
    ans[1]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(!visited[u+1] && u+1<=1000000)
        {
            q.push(u+1);
            visited[u+1]=true;
            ans[u+1]=ans[u]+1;
        }
        int v=rev(u);
        if(!visited[v] && v<=1000000)
        {
            q.push(v);
            visited[v]=true;
            ans[v]=ans[u]+1;
        }
    }
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("Case #%d: %d\n",test,ans[n]);
        test++;
    }
    return 0;
}
