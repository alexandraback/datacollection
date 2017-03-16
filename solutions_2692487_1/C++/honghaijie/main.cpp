#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

LL T,n,m;
LL a[1000];
LL now=0;
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    cin>>T;
    int cs=0;
    while (T--)
    {
        cin>>n>>m;
        for (LL i=0;i<m;i++)
            cin>>a[i];
        LL now=n;
        LL ans=1000000000;
        sort(a,a+m);
        for (LL k=0;k<=m;k++)
        {
            LL nowans=m-k;
            now=n;
            for (LL i=0;i<k;i++)
            {
                if (now<=a[i])
                {
                    if (now==1) { nowans+=1000000; break; }
                    while (now<=a[i])
                    {
                        now=now+now-1;
                        nowans++;
                    }
                }
                now+=a[i];
            }
            if (nowans<ans) ans=nowans;
        }
        printf("Case #%d: ",++cs);
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
