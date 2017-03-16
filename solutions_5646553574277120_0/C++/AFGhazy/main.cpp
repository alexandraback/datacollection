#include <bits/stdc++.h>
using namespace std;

int a[100];

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t)
    {
        int ans = 0;
        int c, d, v;
        cin >> c >> d >> v;
        for(int i = 0; i < d; ++i)
        {
            cin >> a[i];
        }
            int V = 0;
            for(int i = 1; i < (1<<d); ++i)
            {
                int cur = 0;
                for(int j = 0; j < d; ++j)
                {
                    if((i>>j)&1)
                    {
                        cur += a[j];
                    }
                }
                V |= (1<<(cur - 1));
            }
            if(V == ((1<<v)-1))
            {

            }
            else
            {
                ans++;
            }

        cout << "Case #" << t << ": " << ans << endl;
    }
}
