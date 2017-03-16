#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[1000];

int main()
{
    int t,n,s,p,sum,ans,ca=0;
    int i,j;
    freopen("B-large.in","r",stdin);
    freopen("gb.out","w",stdout);
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d%d",&n,&s,&p);
        for (i=0;i<n;i++)
        scanf("%d",&a[i]);
        sort(a,a+n);
        sum=ans=0;
        for (i=0;i<n;i++)
        {
            if (a[i]%3==0)
            {
                if (a[i]/3>=p) ans++;
                else if (a[i]/3+1>=p && sum<s && a[i]/3+1<=a[i])
                {
                    ans++;
                    sum++;
                }
            }
            else if (a[i]%3==1)
            {
                if (a[i]/3+1>=p) ans++;
            }
            else
            {
                if (a[i]/3+1>=p) ans++;
                else if (a[i]/3+2>=p && sum<s)
                {
                    sum++;
                    ans++;
                }
            }
        }

        printf("Case #%d: %d\n",++ca,ans);
    }
}
