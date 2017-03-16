#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int T,x,y,k;
int main()
{
    freopen("i.txt","r",stdin);
    freopen("o.txt","w",stdout);
    scanf("%d",&T);
    for(int I=1;I<=T;++I)
    {
        scanf("%d%d%d",&x,&y,&k); int ans=0;
        for(int i=0;i<x;++i)
            for(int j=0;j<y;++j) if((i&j)<k) ++ans;
        printf("%d\n",ans);
    }
    return 0;
}
