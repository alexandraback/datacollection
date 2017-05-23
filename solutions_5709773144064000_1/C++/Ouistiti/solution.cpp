#include <cstdio>

int main ()
{
    freopen ("Cookie Clicker Alpha11.in","r",stdin);
    freopen ("Cookie Clicker Alpha11.out","w",stdout);
    int t;
    scanf ("%d",&t);
    for (int g=1;g<=t;g++)
    {
        double c,f,x;
        scanf ("%lf %lf %lf",&c,&f,&x);
        double div=2,ans=x/2,sum=0;
        int i=0;
        while (1)
        {
            sum+=c/div;
            div+=f;
            if (sum+x/div<ans)
                ans = sum+x/div;
            else
                break;
        }
        printf ("Case #%d: %.7lf\n",g,ans);
    }
    scanf (" ");
    return 0;
}
