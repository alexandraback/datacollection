#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int a[110];

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    int T;
    scanf("%d",&T);
    for (int t=1;t<=T;t++)
    {
        int c,d,v;
        scanf("%d%d%d",&c,&d,&v);
        memset(a,0,sizeof(a));
        for (int i=0;i<d;i++)
            scanf("%d",&a[i]);
        int now=0;
        long long tar=1;
        int ans=0;
        while (tar<=v)
        {
            if (now==d || a[now]>tar)
            {
                ans++;
                tar+=tar*c;
            }
            else
            {
                tar+=a[now]*c;
                now++;
            }
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
