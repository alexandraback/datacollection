#include <iostream>

using namespace std;

int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int t;
    scanf("%d",&t);
    int n,p,s;
    for (int tt = 1 ; tt <=t ;tt++)
    {
        int ans = 0;
        scanf("%d%d%d",&n,&s,&p);
        int pp = p*3-2;
        int ppp = p*3-4;
        int a[10000];
        for (int i = 0 ;i < n ;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for (int i = n-1 ;i >= 0 ;i--)
        {
            if (a[i] == 0 && p != 0 ) break;
            if (a[i] >= pp) ans++;
            else
            {
                if (s >0&&a[i]>=ppp)
                {
                      s--;
                      ans++;
                }
                else
                break;
                
            }
        }
        printf("Case #%d: %d\n",tt,ans);
        
    }
}
