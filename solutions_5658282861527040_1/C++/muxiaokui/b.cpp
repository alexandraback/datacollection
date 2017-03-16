#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a;
int b;
int k;
int main()
{
   // freopen("mao.in","r",stdin);
   // freopen("out.txt","w",stdout);
    int T,n;
    scanf("%d",&T);int ans=0;
    for(int cs=1; cs<=T; cs++)
    {
        ans=0;
        scanf("%d%d%d",&a,&b,&k);
        for(int t=0;t<a;t++)
        {
            for(int tt=0;tt<b;tt++)
            {
                if((t&tt)<k)ans++;
            }
        }
        printf("Case #%d: %d\n",cs,ans);
    }
}
