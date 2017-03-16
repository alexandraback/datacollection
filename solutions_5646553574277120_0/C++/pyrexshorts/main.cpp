#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, c, d, v, buf;
    cin >> t;
    for(int tt = 1; tt <= t; tt++)
    {
        cin >> c >> d >> v;
        bool can[31] = {0}, can2[31] = {0};
        bool powers[33] = {0};
        int log = 0;
        buf = v;
        can[0] = 1;
        for(int i = 0; i < d; i++)
        {
            cin >> buf;
            for(int j = 0; j <= v; j++)
                if(buf + i <= 30)
                    can2[buf + i] = 1;
            for(int j = 0; j <= v; j++)
                if(can2[j])
                    can[j] = 1;
            powers[buf] = 1;
        }

        int ans = 0;
        for(int i = 1; i <= v; i*=2)
        {
            fill(can2, can2 + 31, 0);
            bool g = 0;
            for(int i = 0; i <= v; i++)
                if(!can[i])
                    g = 1;
            if(!g)
                break;
            if(!powers[i])
            {
                ans++;
                int buf = i;
                for(int j = 0; j <= v; j++)
                if(buf + i <= 30)
                    can2[buf + i] = 1;
                for(int j = 0; j <= v; j++)
                    if(can2[j])
                        can[j] = 1;
            }
        }
        cout << "Case #" << tt << ": " << ans << "\n";
    }
    return 0;
}
