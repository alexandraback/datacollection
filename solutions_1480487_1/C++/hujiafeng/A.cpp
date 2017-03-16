#include<iostream>
#include<memory.h>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<cmath>
#define eps 1e-9
using namespace std;
int a[1000];
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("a.out","w",stdout);
    int ca,i,n,j;
    double ans[1000];
    cin>>ca;
    for(int z=1; z<=ca; z++)
    {
        cout<<"Case #"<<z<<":";
        scanf("%d",&n);
        int flag=0,k=-1;
        int sum=0;
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        for (i = 0; i < n; ++i)
        {
            double r = 1.06, l= 0,tmp,p,mid;
            while(r - l > 1e-9)
            {
                mid = (l + r) / 2;
                bool flag = false;
                tmp = 0;
                p = a[i] + sum*mid;
                for ( j = 0; j < n; ++j)
                {
                    if (i == j) continue;
                    tmp += max(0.0, (p - a[j])*1.0 / sum + eps);
                }
                if (tmp >= 1-mid+eps) flag = false;
                else  flag = true;
                if(flag)  l = mid;
                else r = mid;
            }
            ans[i] = l*100;
        }
        for (int i = 0; i < n; ++i)
        {
            printf(" %.6f",ans[i]);
        }
        puts("");
    }
    return 0;
}
