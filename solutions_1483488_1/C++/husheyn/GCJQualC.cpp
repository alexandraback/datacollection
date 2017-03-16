#include <iostream>
#include <string.h>
using namespace std;

typedef long long LL;

int t, a, b;
int digit[10], len;
int flag[2000005];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        memset(flag, 0, sizeof(flag));
        cin >> a >> b;
        LL ans = 0;
        for(int j = a; j <= b; j++)
        {
            len = 0;
            int t = j;
            len = 0;
            while (t)
            {
                digit[len++] = t % 10;
                t /= 10;
            }
            for(int k = len - 1; k >= 0; k--)
            {
                int cur = 0;
                for(int l = k - 1; l >= 0; l--) cur = cur * 10 + digit[l];
                for(int l = len - 1; l >= k; l--) cur = cur * 10 + digit[l];
                if (cur > j && a <= cur && cur <= b && flag[cur] != j)
                {
                    ans++;
                    flag[cur] = j;
                }
            }
        }
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}
