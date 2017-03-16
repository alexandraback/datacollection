#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
int calc(int s1,int t1,int s2,int t2)
{
    return((720LL-s1)*t1<=(360LL-s2)*t2);
}
pair <int,int> a[20];
ll ma[20],mi[20];
int calc(int n)
{
    mi[0]=1LL<<60;
    for (int i=1;i<=n;i++)
        mi[i]=min(mi[i-1],(720LL-a[i].second)*a[i].first);
    for (int i=n;i;i--)
        ma[i]=max(ma[i-1],(360LL-a[i].second)*a[i].first);
    for (int i=1;i<=n;i++)
        if (mi[i]>ma[i+1])
            return(i-1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            int s,k,t;
            scanf("%d%d%d",&s,&k,&t);
            for (int j=0;j<k;j++)
                a[++m]=make_pair(t+j,s);
        }
        sort(a+1,a+m+1);
        static int id=0;
        printf("Case #%d: %d\n",++id,calc(m));
    }
    return(0);
}

