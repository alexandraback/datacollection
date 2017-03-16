#include <iostream>

using namespace std;

int main()
{
    int tt;
    cin >> tt;
    for (int tc = 1; tc <= tt; tc++)
    {
        int n, x, y;
        cin >> n >> x >> y;
        if (x == 0)
        {
            if (n >= (y + 2) * (y + 1) / 2)
                cout << "Case #" << tc << ": 1" << endl;
            else
                cout << "Case #" << tc << ": 0" << endl;
            continue;
        }
        int xa = x;
        if (xa < 0)
            xa *= -1;
        x = xa;
        int minNeed = y + 1 + (((xa + y) * (xa + y - 1)) / 2);
        if (minNeed > n)
        {
            cout << "Case #" << tc << ": 0" << endl;
            continue;
        }
        n -= minNeed;
        int maxNeed = xa + y;
        if (n >= maxNeed)
        {
            cout << "Case #" << tc << ": 1" << endl;
            continue;
        }
        n = min(n, maxNeed);
        double tmp = 1, ans = 0, tmp2 = 1;
        for (int i = 0; i < y + 1; i++)
            tmp /= 2;
        ans += tmp;
        for (int r = 1; r <= n && r < maxNeed; r++)
        {
            tmp *= ((r + y) / (2.0 * r));
            ans += tmp;
        }
        cout.precision(10);
        cout << "Case #" << tc << ": " << fixed << ans << endl;
    }
}
