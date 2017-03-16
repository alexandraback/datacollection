#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("B-large.in","r", stdin);
    freopen("B-large.out","w", stdout);
    int t,n,a[10005],b[10005],mx,x,y,z,cs=1;
    scanf("%d",&t);

    while(t--)
    {
        memset(b,0,sizeof(b));
        scanf("%d",&n);

        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a, a+n);

        b[a[n-1]]=n;
        mx= a[n-1];

        for(int i=n-2; i>=0; i--)
        {
            if(a[i]!= a[i+1]) b[a[i]]=i+1;
        }

        for(int i=1; i<=2000; i++)
        {
            if(b[i]==0) b[i]= b[i-1];
        }

        for(int i=1; i<=2000; i++)
        {
            z=0;
            for(int j=b[i]; j<n; j++)
            {
                y=a[j]-i;
                z+= y/i;
                if(y%i) z++;
            }
            x=i+z;
            mx=min(mx,x);
        }

        printf("Case #%d: %d\n",cs++,mx);
    }
}
