#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
int n,m;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int tt;
    scanf("%d",&tt);
    int a,b,k;
    for (int ii=1; ii<=tt; ii++)
    {
        int ans=0;
        scanf("%d%d%d",&a,&b,&k);
        for (int i=0; i<a; i++)
         for (int j=0; j<b; j++)
         if ((i&j)<k)
         {
            ans++;
         }
        printf("Case #%d: %d\n",ii,ans);
    }

    return 0;
}
