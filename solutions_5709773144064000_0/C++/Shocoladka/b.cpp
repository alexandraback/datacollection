#include <iostream>
#include <fstream>

using namespace std;

#define ld long double

ld c, f, x;

ld solve(int n)
{
    ld ans = 0;
    for(int i = n - 1; i >= 0; i--)
        ans += 1 / (2 + i * f);
    ans *= c;
    ans += x / (2 + n * f);
    return ans;
}

int main()
{
    ifstream cin("input");
    ofstream cout("output");

    int t;
    cin >> t;
    cout.precision(20);
    for(int k = 0; k < t; k++)
    {
        cin >> c >> f >> x;
        ld ans;
        int l = 0, r = 1e6, m1, m2;
        while(r - l > 2)
        {
            m1 = l + (r - l) / 3;
            m2 = l + 2 * (r - l) / 3;
            if(solve(m1) < solve(m2))
                r = m2;
            else
                l = m1;
        }
        cout << "Case #" << k + 1 << ": "  << min(min(solve(l), solve(l + 1)), solve(l + 2)) << endl;
    }

    return 0;
}
