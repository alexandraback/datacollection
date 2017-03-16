#include <iostream>

using namespace std;

double a[1<<17];

int main()
{
    int t;
    cin >> t;

    cout.setf(ios::fixed);
    cout.precision(10);

    for (int tt=1; tt<=t; tt++)
    {
        int m, n;

        cin >> m >> n;
        for (int i=0; i<m; i++)
            cin >> a[i];

        double ans = n+2;

        double p = 1;
        for (int i=0; i<=m; i++)
        {
            ans = min(ans, m-i + n-i + 1 + (1-p) * (1 + n));
            p *= a[i];
        }

        cout << "Case #" << tt << ": " << ans << endl;
    }

    return 0;
}
