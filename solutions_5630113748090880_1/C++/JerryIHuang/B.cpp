#include <bits/stdc++.h>
using namespace std;

int cnt[3000], ans[200];

int main()
{
    int T, n, t;
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    cin >> T;
    for (int K = 1; K <= T; K++)
    {
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= 2 * n - 1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> t;
                cnt[t]++;
            }
        }
        int l = 0;
        for (int i = 1; i <= 2500; i++)
            if (cnt[i] % 2 == 1)
                ans[l++] = i;

        cout << "Case #" << K << ": ";
        for (int i = 0; i < l; i++)
            cout << ans[i] << (i == l-1 ? '\n' : ' ');
    }
    return 0;
}

