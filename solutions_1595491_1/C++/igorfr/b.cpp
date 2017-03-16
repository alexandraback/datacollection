#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main (void)
{
    int casos;
    scanf ("%d", &casos);

    for (int caso = 1; caso <= casos; ++caso)
    {
        int n, s, p;
        scanf ("%d %d %d", &n, &s, &p);

        vector<int> scores;
        for (int i = 0; i < n; ++i)
        {
            int x;
            scanf ("%d", &x);

            scores.push_back(x);
        }

        if (p == 0)
        {
            printf ("Case #%d: %d\n", caso, n);
            continue;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (scores[i] >= 3*p - 2)
            {
                ++ans;
                continue;
            }

            if (s && p > 1 && scores[i] >= 3*p - 4)
            {
                --s;
                ++ans;
            }
        }

        printf ("Case #%d: %d\n", caso, ans);
    }

    return 0;
}

