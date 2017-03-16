#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define BARSUK_ALEXEY_PSKOV

int tests;

bool isOk(vector<int> & v, int lim)
{
    bool used[lim + 1];
    memset(used, false, sizeof(used));
    used[0] = true;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = lim; j >= 0; j--)
            if (used[j] && j + v[i] < lim + 1)
                used[j + v[i]] = true;
    }

    bool ok = true;
    for (int i = 1; i <= lim; i++)
        ok &= used[i];

    return ok;
}

int main()
{
#ifdef BARSUK_ALEXEY_PSKOV
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    cin >> tests;
    for (int t = 1; t <= tests; t++)
    {
        int c, d, v;
        cin >> c >> d >> v;
        vector<int> dd;
        for (int i = 0; i < d; i++)
        {
            int num; cin >> num;
            dd.push_back(num);
        }
        sort(dd.begin(), dd.end());

        int answer = 0;
        while (!isOk(dd, v))
        {
            int left = 0;
            for (int i = 0; i < dd.size(); i++)
            {
                if (left >= dd[i])
                    left += dd[i];
                else if (left + 1 == dd[i])
                    left += dd[i];
                else break;
            }
            if (left < v)
            {
                answer++;
                dd.push_back(left + 1);
                sort(dd.begin(), dd.end());
            }
        }

        cout << "Case #" << t << ": " << answer << endl;
    }

    return 0;
}

