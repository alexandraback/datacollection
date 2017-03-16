#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>

#define pb push_back
#define mkp make_pair

using namespace std;

const int maxn = 1000001;

int vis[maxn];
int q[maxn];

int rev(int x)
{
    int r = 0;
    while(x)
    {
        int t = x%10;
        r = 10*r + t;
        x/=10;
    }
    return r;
}
void bfs()
{
    vis[1] = 1;
    int front =1,tail = 0;
    q[++tail] = 1;
    while(tail>=front)
    {
        int t= q[front++];
        if(t+1<maxn&&vis[t+1]==0)
        {
            q[++tail] = t+1;
            vis[t+1] = vis[t]+1;
        }
        if(rev(t)<maxn&&vis[rev(t)]==0)
        {
            q[++tail] = rev(t);
            vis[rev(t)] = vis[t]+1;
        }
    }
    //puts("end");
    //for(int i=1;i<maxn;i++)
      //  printf("vis[%d]=%d\n",i,vis[i]);
}
int main()
{
    //printf("%d\n",rev(432));
    bfs();
    int t,a,cas = 0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&a);
        printf("Case #%d: %d\n",++cas,vis[a]);
    }
}
