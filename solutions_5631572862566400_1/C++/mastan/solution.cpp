#include <cstdio>
#include <algorithm>

using namespace std;


int nxt[1005];
int mx;
int n;
int valid[1005];
int len[1005];


void loop(int st,int cur,int len)
{
    if (st==cur)
    {
        mx=max(mx,len);
        return;
    }
    if (len>n)
        return;
    loop(st,nxt[cur],len+1);
}

void track(int st,int cur,int duz)
{
    if (valid[cur])
    {
        len[cur]=max(len[cur],duz);
        return;
    }
    if (duz>n)
        return;
    track(st,nxt[cur],duz+1);
}

void solvetp()
{
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
        scanf("%d",&nxt[i]);
    mx=0;
    for (int i=1; i<=n; i++)
        loop(i,nxt[i],1);
    for (int i=1; i<=n; i++)
    {
        len[i]=0;
        if (nxt[nxt[i]]==i)
            valid[i]=1;
        else
            valid[i]=0;
    }
    for (int i=1; i<=n; i++)
        track(i,i,0);
    int cand=0;
    for (int i=1; i<=n; i++)
        if (valid[i])
            cand=cand+1+len[i];
    printf("%d\n",max(cand,mx));

}

int main()
{
    freopen("D:/in.txt","r",stdin);
    freopen("D:/out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for (int it=1; it<=t; it++)
    {
        printf("Case #%d: ",it);
        solvetp();
    }

}
