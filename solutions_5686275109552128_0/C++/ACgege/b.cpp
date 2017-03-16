#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int d[1100];

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("b.out","w",stdout);
    int T;
    scanf("%d",&T);

    for(int ca=1;ca<=T;ca++)
    {
        int n;
        scanf("%d",&n);

        int mx=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&d[i]);
            mx= max(mx,d[i]);
        }

       sort(d,d+n);

       int ans = 100000;

       for(int i=1;i<=mx;i++)
       {
           int cnt=i;
           for(int j=0;j<n;j++)
              if(d[j]>i)
           {
               cnt += (d[j]-1)/i;
           }

           ans =min(ans,cnt);
       }

       printf("Case #%d: %d\n",ca,ans);

    }
    return 0;
}
