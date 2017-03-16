#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int tt=1; tt<=t; tt++)
    {
        int n, s, p;

        cin >> n >> s >> p;

        int ans = 0;

        for (int i=0; i<n; i++)
        {
            int x;
            cin >> x;

            if ((x + 2) / 3 >= p)
                ans++;

            if (x % 3 == 1 || x == 0)
                continue;

            if ((x + 2) / 3 == p-1 && s)
            {
                ans++;
                s--;
            }
        }

        cout << "Case #" << tt << ": " << ans << endl;
    }

    return 0;
}
