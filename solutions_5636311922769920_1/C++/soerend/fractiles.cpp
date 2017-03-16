#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull pow(ull a, ull b)
{
    if (b == 0)
        return 1;
    return a * pow(a,b-1);
}

ull find(ull k, ull c, ull i)
{
    if (c == 1)
        return i;
    return (i-1) * pow(k,c-1) + find(k,c-1,i);
}

ull findc(ull k, ull c) {
    ull res = 0;
    for (int i = 2; i <= c; ++i)
        res += (i-1) * pow(k,c-i);
    return res + 1;
}

int main()
{
    int t;
    cin >> t;
    for (int x = 1; x <= t; ++x)
    {
        ull k, c, s;
        cin >> k >> c >> s;
        if (s < (k+c-1)/c)
            cout << "Case #" << x << ": IMPOSSIBLE" << endl;
        else {
            cout << "Case #" << x << ":";
            int z = 1;
            ull cur = 0;
            for (int i = 1; i <= k; ++i) {
                if (z == c) {
                    cout << " " << cur+i;
                    z = 1;
                    cur = 0;
                    continue;
                }
                if (i == k && z < c) {
                    while (z < c) {
                        cur += (i-1) * pow(k,c-z);
                        ++z;
                    }
                    cout << " " << cur+i;
                    break;
                }
                cur += (i-1) * pow(k,c-z);
                ++z;
            }
            cout << endl;
        }
    }
}
