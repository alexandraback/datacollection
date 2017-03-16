#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<list>
using namespace std;
double a[1005],b[1005];
double aa[1005],bb[1005];
int main()
{
    int t,ca=0;
    freopen("D-small-attempt2.in","r",stdin);
    freopen("out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%lf",a+i);
        for(int i=0;i<n;++i)
            scanf("%lf",b+i);
        sort(a,a+n);
        sort(b,b+n);
//        for(int i=0;i<n;++i)
//            printf("%lf ",a[i]);
//        puts("");
//        for(int i=0;i<n;++i)
//            printf("%lf ",b[i]);
//        puts("");
        int ans=0,ans1=0;
        int r=0,s=0;
        for(int i=0;i<n;++i)
            if(a[r]<b[s])
                r++,s++;
            else
            {
                while(a[r]>b[s]&&(s<n))
                    s++,ans1++;
                r++,s++;
                if(s==n)
                    break;
            }
        //ans1=n-r;
        r=n-1,s=n-1;
        int p=0;
        for(int i=0;i<n;++i)
            if(a[r]>b[s])
                ans++,r--,s--;
            else s--;
        printf("Case #%d: %d %d\n",++ca,ans,ans1);
    }
}
