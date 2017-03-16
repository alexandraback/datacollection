#include <iostream>
using namespace std;

long long get_gcd(long long a, long long b)
{
    if(a == 0) return b;
    else if(b == 0) return a;

    return get_gcd(b % a, a);
}

int main()
{
    int t;
    cin >> t;
    for(int tcase = 1; tcase <= t; ++tcase)
    {
        char c;
        long long p, q;
        cin >> p >> c >> q;

        int res = 0;

        long long gcd = get_gcd(p, q);

        p = p / gcd;
        q = q / gcd;

        long long tmp = q;
        while(tmp % 2 == 0)
        {
            tmp = tmp / 2;
        }

        if(tmp == 1)
        {
            res = 1;
            long long x = 2;

            while(true)
            {
                long long y = q / x;
                if(p >= y) break;
                ++res;
                x *= 2;
            }
        }

        cout << "Case #" << tcase << ": ";
        if(res == 0) cout << "impossible";
        else cout << res;
        cout << endl;
    }

    return 0;
}
