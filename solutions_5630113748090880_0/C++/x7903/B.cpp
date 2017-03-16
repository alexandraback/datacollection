#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <fstream>
using namespace std;

int a[10000];
int t,x,n;

int main()
{
    ofstream fp("B.out");
    scanf("%d",&t);
    for (int cas=1;cas<=t;++cas)
    {
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        for (int i=1;i<=2*n-1;++i)
        {
            for (int j=1;j<=n;++j)
            {
                scanf("%d",&x);
                a[x]^=x;
            }
        }
        fp<<"Case #"<<cas<<":";
        for (int i=0;i<=2500;++i)
        {
            if (a[i]>0) fp<<" "<<i;
        }
        fp<<endl;
    }
    return 0;
}
