#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int T; double C,F,X,t,ans;
int main()
{
    freopen("i.txt","r",stdin);
    freopen("o.txt","w",stdout);
    scanf("%d",&T);
    for(int I=1;I<=T;++I)
    {
        scanf("%lf%lf%lf",&C,&F,&X); ans=X/2; t=0;
        for(int i=1;i<=(int)X+1;++i)
        {
            t+=C/(2+F*(i-1));
            ans=min(ans,t+X/(2+F*i));
        }
        printf("Case #%d: %.7lf\n",I,ans);
    }
    return 0;
}
