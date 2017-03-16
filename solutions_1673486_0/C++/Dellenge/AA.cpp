#include "iostream"
using namespace std;
#define DATASIZE 100002
double p[DATASIZE];
int main()
{
    int t, h;
    freopen("A-small.in","r",stdin);
    freopen("A-small.out","w",stdout);
    scanf("%d",&t);
    h  = 0;
    while( h < t)
    {
        int i, a, b;
        scanf("%d%d",&a,&b);
        for( i=0; i<a; i++)
        {
            scanf("%lf",&p[i]);
        }
        double allright = 1.0;
        double good = 1 + b + 1;
        for( i=0; i<=a; i++)
        {
            int tp1 = (a - i) + ( b - i + 1);
            int tp2 = (a - i) + ( b - i + 1) + b + 1;
            double tempexp = tp1 * allright + tp2 * (1 - allright);
            allright *= p[i];
            if( tempexp < good)
                good = tempexp;
        }
        printf("Case #%d: %.6f\n",++h,good);
    }
    return 0;
}