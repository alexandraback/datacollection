#include<cstdio>
#include <algorithm>
using namespace std;
int s[202];
int p[202];
double r[202];

int main()
{
    int t, n, v;
    scanf("%d",&t);
    for (int ti=1; ti<=t; ti++)
    {
        scanf("%d",&n);
        v = 0;
        for (int i=0; i<n; i++)
        {
            scanf("%d",&s[i]);
            p[i] = s[i];
            v += s[i];
        }
        sort(p, p+n);
        double minv = p[0];
        int left = v;
        for (int i=0; i<n; i++)
        {
            if (p[i] < p[i+1])
            {
                int need = (p[i+1] - p[i])*(i+1);
                if (need <= left)
                {
                    left -= need;
                    p[i] = p[i+1];
                    minv = p[i];
                }
                else
                {
                    minv = double(p[i]) + double(left)/double(i+1);
                    left = 0;
                    break;
                }
            }
        }
        if (left > 0)
            minv = double(p[n-1]) + double(left)/double(n);
            
        for (int i=0; i<n; i++)
            if (double(s[i]) >= minv)
                r[i] = 0.0;
            else
                r[i] = (minv-double(s[i]))*100.0/double(v);

        printf("Case #%d: ", ti);
        for (int i=0; i<n-1; i++)
            printf("%lf ",r[i]);
        printf("%lf\n", r[n-1]);
    }
}

