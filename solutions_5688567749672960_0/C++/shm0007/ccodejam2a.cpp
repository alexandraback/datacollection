/*
Shamim Ehsan
SUST CSE 12
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
#include<algorithm>
#include<sstream>
#define PI (2* acos(0))
#define pb push_back
#define ll long long
using namespace std;
//int X[]= {0,0,1,-1};
//int Y[]= {-1,1,0,0};
//int X[]= {0,0,1,1,1,-1,-1,-1};
//int Y[]= {-1,1,0,1,-1,0,1,-1};
int rev(int num)
{
    int temp=0;
    while(num)
    {
        temp*=10;
        temp+=num%10;
        num/=10;
    }
//    cout<<tecmp;

    return temp;
}
int vis[1000010];
    int dist[1000010];

int bfs(int en)
{

    memset(vis,0,sizeof vis);
    memset(dist,0,sizeof dist);
    queue<int>Q;

    Q.push(1);
    vis[1]=1;
    if(en==1)
        return 0;
    while(!Q.empty())
    {
//        puts("a");
        int u=Q.front();
        Q.pop();
        int v=u+1;
        if(vis[v]==0)
        {
            Q.push(v);
            vis[v]=1;
            dist[v]=dist[u]+1;
            if(v==en)
                return dist[v];
        }
        v=rev(u);
        if(vis[v]==0)
        {
            Q.push(v);
            vis[v]=1;
            dist[v]=dist[u]+1;
            if(v==en)
                return dist[v];
        }
    }

    return -1;
}
int main()
{

    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.txt","w",stdout);

    int t;
    int n;

    scanf("%d",&t);
    for(int cs=1; cs<=t; cs++)
    {

        scanf("%d",&n);
        printf("Case #%d: %d\n",cs,bfs(n)+1);
    }
    return 0;
}


