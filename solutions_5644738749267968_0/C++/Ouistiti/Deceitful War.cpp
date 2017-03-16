#include <cstdio>
#include <algorithm>

using namespace std;

double a[1001];
double b[1001];

int main ()
{
    freopen ("Deceitful War14.in","r",stdin);
    freopen ("Deceitful War14.out","w",stdout);
    int t;
    scanf ("%d",&t);
    for (int g=1;g<=t;g++)
    {
        int n,l=0,war=-1,dec=0;
        scanf ("%d",&n);
        int maxx=n-1,minn=0;
        for (int i=0;i<n;i++)
            scanf ("%lf",&a[i]);
        for (int i=0;i<n;i++)
            scanf ("%lf",&b[i]);
        sort (a,a+n);
        sort (b,b+n);
        b[n] = 2;
        int i=0;
        while (l!=n+1)
        {
            while (b[l++]<a[i]);
            war++; i++;
        }
        for (int i=0;i<n;i++)
        {
            if (a[i]<b[minn]) maxx--;
            else
            {
                minn++;
                dec++;
            }
        }
        printf ("Case #%d: %d %d\n",g,dec,n-war);
    }
    scanf (" ");
    return 0;
}
