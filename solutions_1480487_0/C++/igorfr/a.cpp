#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

// Problem A

int main (void)
{
    int casos;
    scanf ("%d", &casos);

    for (int caso = 1; caso <= casos; ++caso)
    {
        printf ("Case #%d:", caso);

        int n;
        vector<int> s;
        int total = 0;

        scanf ("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            int x;
            scanf ("%d", &x);
            s.push_back(x);

            total += x;
        }
        
        for (int i = 0; i < n; ++i)
        {
            double lo = 0, hi = 1;
            while (hi - lo > 1e-11)
            {
                double mid = (hi + lo) / 2;

                double score = s[i] + total * mid;

                double sum = 0;
                for (int j = 0; j < n; ++j)
                {
                    if (j == i) continue;
                    double k = max((score - s[j]) / total, 0.0);
                    sum += k;
                }

                //printf ("%d %f %f %f\n", i, mid, sum, sum + mid);
                if (sum + mid > 1) hi = mid;
                else lo = mid;
            }

            printf (" %f", 50*(lo + hi));
        }
        printf ("\n");
    }

    return 0;
}

