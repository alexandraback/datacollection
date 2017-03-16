#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int numdigits(int a)
{
    int a1 = a, n = 0;
    while (a1) { a1 /= 10; n++; }
    return n;
}

int recycle(int a, int n)
{
    int a0 = numdigits(a), aa, i;
    vector <int> a1, a2;
    a1.resize(a0); a2.resize(a0);
    aa = a; for (i = 0; i < a0; i++) { a1[i] = aa % 10; aa /= 10; }
    for (i = 0; i < n; i++) a2[i] = a1[a0 - n + i];
    for (i = n; i < a0; i++) a2[i] = a1[i - n];
    aa = 0; for (i = a0 - 1; i >= 0; i--) { aa *= 10; aa += a2[i]; }
    return aa;
}

int main()
{
    bool found;
    int a, b, cnt, i, j, k, n, r, rr, t;
    vector <int> r1;
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    cin >> t;
    for (cnt = 1; cnt <= t; cnt++)
    {
        cin >> a; cin >> b;
        n = 0;
        for (i = a; i <= b; i++)
        {
            rr = 0; r1.resize(rr);
            for (j = 1; j < numdigits(i); j++)
            {
                r = recycle(i, j);
                found = false;
                for (k = 0; k < rr; k++) if (r1[k] == r) found = true;
                if (!found) { rr++; r1.resize(rr); r1[rr - 1] = r; }
            }
            for (j = 0; j < rr; j++)
            {
                if ((r1[j] > i) && (r1[j] <= b))
                {
                    //printf("%d %d\n", i, r1[j]);
                    n++;
                }
            }
        }
        cout << "Case #" << cnt << ": " << n << endl;
    }
    return 0;
}
