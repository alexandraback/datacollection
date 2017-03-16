#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t,x,r,c;
    scanf("%d",&t);
    for (int cas=1;cas<=t;++cas)
    {
        scanf("%d%d%d",&x,&r,&c);
        if (r>c) swap(r,c);
        bool flag=0;
        if (r>=(x+1)/2&&r*c%x==0) flag=1;
        if (x==4&&r==2) flag=0;
        printf("Case #%d: %s\n",cas,flag?"GABRIEL":"RICHARD");
    }
    return 0;
}
