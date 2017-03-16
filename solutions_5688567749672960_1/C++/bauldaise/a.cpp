#include <iostream>
#include <cstdio>
using namespace std;

long long ft[20];

long long f (long long n)
{
    long long ans = 0;
    long long dig[20];
    int cnt = 0;
    for (; n > 0; cnt++)
    {
        dig[cnt] = n % 10;
        n /= 10;
    }

    int l = cnt - cnt / 2;
    long long pow = 1;
    for (int i = cnt-1; i >= l; i--)
    {
        ans += dig[i] * pow;
        pow *= 10;
    }
    if (ans > 1) ans++; //for reverse

    pow = 1;
    for (int i = 0; i < l; i++)
    {
        ans += pow * dig[i];
        pow *= 10;
    }

    ans += ft[cnt - 1];// for 10000
    ans--; // for 1



    return ans;
}

int main()
{
    freopen("al.in", "r", stdin);
    freopen("a.out", "w", stdout);
    ft[0] = 1;
    long long pow = 10;
    for (int i = 1; i < 16; i++)
    {
        ft[i] = f(pow - 1) + 1;
        pow *= 10;
    }

    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        long long x;
        cin >> x;
        if (x % 10 == 0) x = f(x - 1) + 1;
        else x = f(x);
        cout << "Case #" << tt << ": " << x << endl;
    }
}
