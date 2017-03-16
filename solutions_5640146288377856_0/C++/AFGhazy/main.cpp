#include <bits/stdc++.h>
using namespace std;

int mask[100];

int main()
{
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("A-small-attempt1.out", "w", stdout);
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t)
    {
        int ans = 0,r , c, w, mn = 12345678;
        cin >> r >> c >> w;
        for(int i = 1; i <= c - w + 1; ++i)
        {
            mask[i-1] = (((1<<w) - 1) << (i-1));
        }
        for(int i = 0; i < (1<<c); ++i)
        {
            int tmp_i = i;
            int curr_mn = 0;
            while(tmp_i)
            {
                tmp_i -= (tmp_i & -tmp_i);
                curr_mn++;
            }
            int j = 0;
            for(; j < c - w + 1; j++)
            {
                if(mask[j] & i)
                {
                    continue;
                }
                else break;
            }
            if(j == c - w + 1)
            {
                mn = min(mn, curr_mn);

            }
        }
        if(c % w)
        {
            ans++;
        }
        ans += ((w - 1) + mn);
        cout << "Case #" << t << ": " << ans << endl;
    }
}
