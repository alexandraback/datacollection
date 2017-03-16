#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int fi[1100], next[1100], ed[1100], flag[1100], dui[1100];
bool biao[1100], ans;

int main()
{
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int t, n, m, q, w, x, tou, wei, k, j;
    cin >> t;
    for (int qw = 1; qw <= t; qw ++)
    {
        memset(fi, 0, sizeof(fi));
        memset(next, 0, sizeof(next));
        m = 0;
        cin >> n;
        ans = false;
        for (int i = 1; i <= n; i ++)
        {
            cin >> w;
            for (int k = 1;k <= w; k ++)
            {
                cin >> x;
                m ++;
                ed[m] = x;
                next[m] = fi[i];
                fi[i] = m;
            }
        }
        for (int i = 1; i <= n; i ++)
        {
            ans = false;
            memset(flag, 0, sizeof(flag));
            tou = 0;
            wei = 1;
            dui[wei] = i;
            memset(biao, true, sizeof(biao));
            biao[i] = false;
            while (tou != wei){
                tou ++;
                j = fi[dui[tou]];
                while (j != 0){
                    flag[ed[j]] ++;
                    if (flag[ed[j]] > 1){
                        ans = true;
                        break;
                    }
                    if (biao[ed[j]] == true)
                    {
                        wei ++;
                        dui[wei] = ed[j];
                    }
                j = next[j];
                if (ans == true) break;
                }
            }
            if (ans == true) break;
        }
        if (ans == true) cout << "Case #" << qw << ": " << "Yes" << endl;
            else cout << "Case #" << qw << ": " << "No" << endl;

    }
    return 0;
}
