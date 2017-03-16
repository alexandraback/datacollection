#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("B1.in","r",stdin);
    freopen("B1.out","w",stdout);
    int cas;
    cin>>cas;
    long long n,m;
    for (int run=1;run<=cas;++run)
    {
        cin>>n>>m;
        cout<<"Case #"<<run<<":";
        if ((1LL<<(n-2))<m)
        {
            puts(" IMPOSSIBLE");
            continue;
        }
        puts(" POSSIBLE");
        if (1LL<<(n-2)==m)
        {
            for (int i=0;i<n;++i)
            {
                for (int j=0;j<n;++j)
                    putchar(j<=i?'0':'1');
                putchar('\n');
            }
            continue;
        }
        for (int i=0;i<n;++i)
        {
            for (int j=0;j<=i;++j) putchar('0');
            for (int j=i+1;j<n-1;++j) putchar('1');
            if (i<n-1)
            {
                if (i>0&&((m>>(i-1))&1))
                    putchar('1');
                else
                    putchar('0');
            }
            putchar('\n');
        }
    }
    return 0;
}
