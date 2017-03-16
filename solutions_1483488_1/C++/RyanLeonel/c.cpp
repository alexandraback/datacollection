#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int pow10[10];

int numdigits(int a)
{
    int a1 = a, n = 0;
    while (a1) { a1 /= 10; n++; }
    return n;
}

int recycle(int a, int n, int len)
{
    return ((a % pow10[n]) * pow10[len - n]) + (a / pow10[n]);
}

int main()
{
    bool found;
    int a, b, cnt, i, j, k, len, len1, n, r, rr, t;
    vector <int> r1;
    pow10[0] = 1; for (i = 1; i < 10; i++) pow10[i] = pow10[i - 1] * 10;
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    cin >> t;
    for (cnt = 1; cnt <= t; cnt++)
    {
        cin >> a; cin >> b;
        n = 0; len = numdigits(a); r1.resize(len);
        for (i = a; i <= b; i++)
        {
            for (j = 0; j < len; j++) r1[j] = 0;
            len1 = 0;
            for (j = 1; j < len; j++)
            {
                r = recycle(i, j, len);
                found = false;
                for (k = 0; k < len1; k++) if (r1[k] == r) found = true;
                if (!found) { r1[len1] = r; len1++; }
            }
            for (j = 0; j < len1; j++)
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
