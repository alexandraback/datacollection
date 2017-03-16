#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int caseNum = 1; caseNum <= t; caseNum++)
    {
        int a, n;
        cin >> a >> n;
        vector<long long> m(n);
        for (int i = 0; i < n; i++)
            cin >> m[i];
        sort(m.begin(), m.end());

        int best = n;
        long long cura = 0;
        long long curs = a;
        for (int i = 0; i < n; i++)
        {
            if (curs > m[i])
            {
                curs += m[i];
            }
            else
            {
                if (cura + (n - i) < best)
                {
                    best = cura + n - i;
                }

                if (curs == 1)
                    break;

                while (curs <= m[i])
                {
                    curs = curs * 2 - 1;
                    cura++;
                }

                curs += m[i];
            }

            if (cura + (n - i - 1) < best)
                best = cura + n - i - 1;
        }

        cout << "Case #" << caseNum << ": " << best << endl;
    }
    return 0;
}
