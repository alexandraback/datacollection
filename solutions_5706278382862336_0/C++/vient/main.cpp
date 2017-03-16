#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

bool is_power_of_two(long long x)
{
    bool ans = true;
    while (x)
    {
        ans &= (x == 1 || (x != 1 && !(x & 1)));
        x >>= 1;
    }
    return ans;
}

long long gcd(long long a, long long b)
{
    return (b ? gcd(b, a % b) : a);
}

int main()
{
    ifstream cin("A-small-attempt0.in");
    ofstream cout("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    for (int stepnum = 1; q; q--, stepnum++)
    {
        cout << "Case #" << stepnum << ": ";
        long long a, b, g;
        char c;
        cin >> a >> c >> b;
        g = gcd(a, b);
        a /= g;
        b /= g;
        if (!is_power_of_two(b))
            cout << "impossible";
        else
        {
            long long num = 0, now = 1;
            while (now <= a)
            {
                now <<= 1;
                num++;
            }
            cout << (int)(log2((long double)b) + 0.5) - num + 1;
        }
        cout << '\n';
    }
    return 0;
}
