#include <cstdio>
#include <utility>
#include <set>
using namespace std;
set <pair <int,int> > s1,s2;
int a[1010],b[1010];
bool vis[1010];
int getSmall(int limit)
{
    int ma=0,t;
    for (set <pair <int,int> >::iterator k=s1.begin();k!=s1.end();k++)
    {
        if (k->first>limit)
            break;
        if (b[k->second]>=ma)
            ma=b[t=k->second];
    }
    vis[t]=true;
    s1.erase(make_pair(a[t],t));
    return(1);
}
int getLarge(int x)
{
    int ret=1;
    if (!vis[x])
    {
        ret++;
        s1.erase(make_pair(a[x],x));
    }
    s2.erase(make_pair(b[x],x));
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        s1.clear();
        s2.clear();
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            s1.insert(make_pair(a[i],i));
            s2.insert(make_pair(b[i],i));
            vis[i]=false;
        }
        int ans=0,star=0;
        while (!s2.empty())
        {
            ans++;
            if (s2.begin()->first<=star)
            {
                star+=getLarge(s2.begin()->second);
                continue;
            }
            if (!s1.empty() && s1.begin()->first<=star)
            {
                star+=getSmall(star);
                continue;
            }
            ans=-1;
            break;
        }
        static int id=0;
        printf("Case #%d: ",++id);
        if (ans==-1)
            printf("Too Bad\n");
        else
            printf("%d\n",ans);
    }
    return(0);
}

