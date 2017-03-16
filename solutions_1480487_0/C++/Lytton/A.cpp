#include <stdio.h>
#include <iostream>
using namespace std;

const double xx = 1e-8;

int t, n, a[250], tot;

bool check(int k, double lim, double s)
{
    bool flag = false;

    for (int i = 1;i <= n;++i)
        if (i != k && a[i] < lim)
        {
            s -= 1.0*(lim-a[i])/tot;
           // cout << s << tot << endl;
            flag = true;
            if (s < 0) break;
        }
    if (s > 0) return false;
    else if (s < 0) return true;
         else if (flag) return true;
            else return false;

}

void doit(int k)
{
    double mid, t, e, lim;

    t = 0; e = 1;
    while (e-t >= xx)
    {
        mid = (t+e)/2;
        lim = a[k] + 1.0*tot*mid;
        if (check(k,lim,1-mid)) e = mid;
        else t = mid;
    }
    cout << ' ' << t*100;
}

int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    scanf("%d",&t);
    for (int w = 1;w <= t;++w)
    {
        scanf("%d",&n);
        tot  = 0;
        for (int i = 1;i <= n;++i)
        {
            scanf("%d",&a[i]);
            tot += a[i];
        }
        cout <<"Case #" << w << ":";
        for (int i =1 ;i <= n;++i) doit(i);
        cout << endl;
    }
}
