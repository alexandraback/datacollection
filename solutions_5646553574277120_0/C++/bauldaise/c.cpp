#include <iostream>
#include <cstdio>
using namespace std;

void cans(int test, int ans)
{
    cout << "Case #" << test << ": " << ans << endl;
}


int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);

    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        long long curmax = 0;
        long long ans = 0;
        long long C, D, V;
        cin >> C >> D >> V;
        for (int i = 0; i <= D; i++)
        {
            int a;
            if (i == D) a = V + 1;
            else cin >> a;
            while(a > curmax + 1)
            {
                curmax += C * (curmax + 1);
                ans++;
            }
            curmax += C * a;
        }
        cans(tt, ans);
    }
    return 0;
}
