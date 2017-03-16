#include <stdio.h>
#include <iostream>
using namespace std;

int tot, t,n;
int f[10000000],a[30];
bool g[20];


void doit()
{
    int s ,ss;

    for (int i = 1;i <= tot;++i) f[i] = 0;
    f[0] = 1;
    for (int i = 1;i <= n;++i)
        for (int j = tot;j >= a[i];--j)
            f[j] += f[j-a[i]];
      //  cout << tot << endl;
    for (s = 1;s <= tot;++s)
    {
        if (f[s] >= 2) break;
      //  cout << s << ' ' << f[s] << endl;
    }
  //  cout << s << endl;
    if (s > tot || f[s] < 2)
    {
        cout << "Impossible\n";
    }
    else {
            ss = s;
            int fl = false;
            for (int i = 1;i <= n;++i) g[i] = false;

            for (int i = 1;i <= n;++i)
            {
                if (s >= a[i] && f[s-a[i]])
                {
                    s -= a[i];
                    if (fl) cout << ' ';
                    cout << a[i];
                    fl= true;
                    g[i] = true;
                }
                if (s == 0) break;
            }
            cout << endl;
            fl = false;
            for (int i = 1;i <= n;++i)
                if (ss >= a[i] && f[ss-a[i]] && !g[i])
                {
                    ss -= a[i];
                    if (fl) cout << ' ';
                    cout << a[i];
                    fl= true;
                }
            cout << endl;

         }
}

int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    cin >> t;
    for (int w = 1;w <= t;++w)
    {
        cin >> n; tot = 0;
        for (int i = 1;i <= n;++i)
        {
            cin >> a[i];
            tot += a[i];
        }
        cout << "Case #" << w << ":" << endl;
        doit();
    }
}
