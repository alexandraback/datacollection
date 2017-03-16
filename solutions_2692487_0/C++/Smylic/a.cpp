#include <iostream>
#include <algorithm>

using namespace std;

int a[1024];

int main()
{
    int t;
    cin >> t;
    for (int tt=1; tt<=t; tt++)
    {
        int n, x;
        cin >> x >> n;
        for (int i=0; i<n; i++)
            cin >> a[i];
        sort(a, a+n);
        int ans = n;
        int cur = 0;
        for (int i=0; i<n; )
        {
            if (a[i] < x)
                x += a[i++];
            else
            {
                x += x-1;
                cur++;
                if (x == 1)
                    break;
            }
            ans = min(ans, cur + n-i);
        }
        cout << "Case #" << tt << ": " << ans << endl;
    }
    return 0;
}
