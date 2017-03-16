#include <cstdio>
#include <cstdlib>
#include <cstring>
int t,id;
double c,f,x,ans,v;

int main()
{
    freopen("B-small-attempt1.in","r",stdin);freopen("b.out","w",stdout);
    scanf("%d",&t);
    for (id=1;id<=t;id++)
    {
        scanf("%lf%lf%lf",&c,&f,&x);
        ans=0;v=2;
        while (x/v>x/(v+f)+c/v)
        {
            ans+=c/v;
            v+=f;
        }
        ans+=x/v;
        printf("Case #%d: %0.9f\n",id,ans);
    }
    return 0;
}
