#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int T,n,m;
int a[1000];
int now=0;
int main()
{
    freopen("A-small-attempt3.in","r",stdin);
    freopen("A-small-attempt3.out","w",stdout);
    cin>>T;
    int cs=0;
    while (T--)
    {
        cin>>n>>m;
        for (int i=0;i<m;i++)
            cin>>a[i];
        int now=n;
        int ans=1000000000;
        sort(a,a+m);
        for (int k=0;k<=m;k++)
        {
            int nowans=m-k;
            now=n;
            for (int i=0;i<k;i++)
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
