#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct heap{
    const static int len=1005;
    int head[len],next[len*len],key[len*len],pos;
    void clear()
    {
        pos=0;
        memset(head,-1,sizeof(head));
    }
    void add(int s,int e)
    {
        key[pos] =e;
        next[pos] = head[s];
        head[s] = pos++;
    }
}heap;

bool flag,v[1005];
void dfs(int s)
{
    v[s]=1;
    if(flag)return;
    for(int i = heap.head[s];i !=-1;i = heap.next[i])
    {
        int e=heap.key[i];
        if(v[e])
        {
            flag = true;
            return;
        }
        dfs(e);
    }
}
int main()
{
    //freopen("1.in","r",stdin);
    //freopen("2.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int ca = 1; ca <= t; ca++)
    {
       int n;
       scanf("%d",&n);
       flag =false;

       heap.clear();
       for(int i =1; i<=n;i++)
       {
            int m;
            scanf("%d",&m);
            while(m--)
            {
                int e;
                scanf("%d",&e);
                heap.add(e,i);
            }
       }
       for(int i=1;i<=n;i++)
       {
           if(flag)break;
           memset(v,0,sizeof(v));
           dfs(i);
       }
       if(flag)
            printf("Case #%d: Yes\n",ca);
        else
            printf("Case #%d: No\n",ca);
    }
    return 0;
}
