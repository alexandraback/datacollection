#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int T; double C,F,X,t[100005],ans;
int main()
{
    freopen("i.txt","r",stdin);
    freopen("o.txt","w",stdout);
    scanf("%d",&T);
    for(int I=1;I<=T;++I)
    {
        scanf("%lf%lf%lf",&C,&F,&X); ans=X/2;
        for(int i=1;i<=(int)X+1;++i)
        {
            t[i]=t[i-1]+C/(2+F*(i-1));
            ans=min(ans,t[i]+X/(2+F*i));
        }
        printf("Case #%d: %.7lf\n",I,ans);
    }
    return 0;
}
