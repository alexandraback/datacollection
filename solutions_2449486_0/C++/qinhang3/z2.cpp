#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=110;

struct node
{
    int data;
    int y;
    int x;
};

node a[MAXN*MAXN];
int T,Y,X;
int Map[MAXN][MAXN];
int now[MAXN][MAXN];
int H[MAXN],L[MAXN];
bool flag;

void reset()
{
    memset(Map,0,sizeof(Map));
    memset(H,0,sizeof(H));
    memset(L,0,sizeof(L));
    memset(now,-1,sizeof(now));
    memset(a,0,sizeof(a));
    flag=true;
}

bool comp(node a,node b)
{
    return a.data>b.data;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&T);
    for (int t=1;t<=T;t++)
    {
        reset();
        int all=0;
        scanf("%d%d",&Y,&X);
        for (int y=1;y<=Y;y++)
            for (int x=1;x<=X;x++)
            {
                scanf("%d",&Map[y][x]);
                all++;
                a[all].data=Map[y][x];
                a[all].y=y;
                a[all].x=x;
            }
        sort(a+1,a+all+1,comp);
        for (int i=1;i<=all;i++)
        {
            node n=a[i];
            if (!H[n.y])
            {
                for (int i=1;i<=X;i++) now[n.y][i]=n.data;
                H[n.y]=true;
            }
            if (!L[n.x])
            {
                for (int i=1;i<=Y;i++) now[i][n.x]=n.data;
                L[n.x]=true;
            }
            if (now[n.y][n.x]!=n.data)
            {
                flag=false;
                break;
            }
        }
        printf("Case #%d: ",t);
        if (flag) printf("YES\n"); else printf("NO\n");
    }
}
