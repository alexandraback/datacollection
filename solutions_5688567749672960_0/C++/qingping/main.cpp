#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
vector<int > tmp;
typedef pair<int,int> PII;
int rever(int x)
{
    tmp.clear();
    while(x)
    {
        tmp.push_back(x%10);
        x/=10;
    }
    int sum=0;
    for(auto& m:tmp)
    {
        sum=sum*10+m;
    }
    return sum;
}

int bfs(int x)
{
    queue<PII > q;
    vector<bool> vis(1011111);
    q.push(PII(1,1));
    vis[1]=true;
    while(!q.empty())
    {
        PII nowP=q.front();
        q.pop();
        if(nowP.first==x) return nowP.second;
        int now=nowP.first , step=nowP.second;
        if(!vis[now+1])
        {
            vis[now+1]=true;
            q.push(PII(now+1,step+1));
        }
        int reverNow=rever(now);
        if(!vis[reverNow])
        {
            vis[reverNow]=true;
            q.push(PII(reverNow,step+1));
        }
    }
    return -1;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; t++)
    {
        int x;
        scanf("%d",&x);
        int step=bfs(x);
        printf("Case #%d: ",t);
        if(step!=-1) cout<<step<<endl;
        else cout<<"cant!"<<endl;
    }
    return 0;
}
