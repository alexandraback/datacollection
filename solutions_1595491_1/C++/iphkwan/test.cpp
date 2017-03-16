#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[110];
int main()
{
    //freopen("t.in","r",stdin);
    //freopen("t.txt","w",stdout);
    int t,n,s,p,ans;
    scanf("%d",&t);
    for(int z=1;z<=t;z++)
    {
        scanf("%d%d%d",&n,&s,&p);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        ans = 0;
        sort(a,a+n);
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]%3==0)
            {
                if(a[i]/3 >= p)
                    ans++;
                else
                {
                    if(s>0 && a[i]/3>=p-1 && a[i]>0 && a[i]/3+1<=10)
                    {
                        ans++;
                        s--;
                    }
                }
            }
            if(a[i]%3==1)
            {
                if(a[i]/3+1>=p)
                    ans++;
            }
            if(a[i]%3==2)
            {
                if(a[i]/3+1>=p)
                    ans++;
                else
                {
                    if(s>0 && a[i]/3>=p-2 && a[i]/3+2<=10)
                    {
                        ans++;
                        s--;
                    }
                }
            }
        }
        printf("Case #%d: %d\n",z,ans);
    }
    return 0;
}
