#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[200],sum;

bool check(int my,long double pmy)
{
    long double soc = pmy*0.01*(long double)sum+(long double)a[my];
    long double tot = pmy;
    for (int i = 0;i < n;i++)
        if (i != my)
        {
            long double pj = (soc-(long double)a[i])/(long double)sum*100;
            if (pj < 0) continue;
            tot += pj;
            if (tot > 100)  return true;
        }
    return false;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    scanf("%d",&n);
	    sum = 0;
	    for (int i = 0;i < n;i++)
	    {
	        scanf("%d",&a[i]);
	        sum += a[i];
	    }
	    long double l,r,mid;
	    printf("Case #%d: ",cas);
	    for (int i = 0;i < n;i++)
	    {
	        l = 0;
	        r = 100;
	        for (int tims = 0;tims <= 500;tims++)
            {
                mid = (l+r)/2.0;
                if (check(i,mid) == true)
                    r = mid;
                else
                    l = mid;
            }
            double res = l;
            printf("%.6f ",res);
	    }
	    printf("\n");
	}
	return 0;
}
