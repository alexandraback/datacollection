#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
double a[1005],b[1005];
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,Case=0;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%lf",&a[i]);
        for(int i=0;i<n;++i)
            scanf("%lf",&b[i]);
        sort(a,a+n);
        sort(b,b+n);
        int res=n,ans=0;
        for(int i=0,j=0;i<n&&j<n;)
            if(a[i]<b[j])++j,++i,--res;
            else ++j;
        for(int i=0,j=0;i<n&&j<n;)
            if(b[i]<a[j])++j,++i,++ans;
            else ++j;
        printf("Case #%d: %d %d\n",++Case,ans,res);
    }
    return 0;
}
