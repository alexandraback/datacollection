#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <string>
#define MAXN 100
using namespace std;
struct NODE
{
    vector<int>next;
}node[MAXN];
bool v[MAXN];
int tmp;
void DFS(int x)
{
    if(tmp) return;
    v[x]=true;
    int i;
    for(i=0;i<node[x].next.size();++i)
    {
        int y=node[x].next[i];
        if(v[y]==true)
        {
            tmp=1;
            return;
        }
        else
        {
            DFS(y);
        }
        if(tmp) return;
    }
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A.out","w",stdout);
    int t,ca,i,j,n,m,a;
    scanf("%d",&t);
    for(ca=1;ca<=t;++ca)
    {
        scanf("%d",&n);
        for(i=1;i<=n;++i)
        {
            node[i].next.clear();
            scanf("%d",&m);
            for(j=0;j<m;++j)
            {
                scanf("%d",&a);
                node[i].next.push_back(a);
            }
        }
        tmp=0;
        for(i=1;i<=n;++i)
        {
            memset(v,0,sizeof(v));
            DFS(i);
            if(tmp) break;
        }

        printf("Case #%d: ",ca);
        if(tmp) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
