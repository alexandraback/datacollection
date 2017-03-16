#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;
set <int> M;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        ll ans=0;
        for (int i=n;i<=m;i++)
        {
            int p=1,tmp=i,num=0;
            while (tmp)
            {
                tmp/=10;
                p*=10;
                num++;
            }
            p/=10;
            tmp=i;
            M.clear();
            for (int j=1;j<=num;j++)
            {
                bool flag=true;
                if (tmp%10==0)
                    flag=false;
                tmp=tmp/10+tmp%10*p;
                if (flag && tmp>i && tmp<=m && !M.count(tmp))
                    ans++;
                M.insert(tmp);
            }
        }
        static int id=0;
        printf("Case #%d: %lld\n",++id,ans);
    }
    return(0);
}

