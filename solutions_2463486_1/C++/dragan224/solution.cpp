#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <cmath>
#include <algorithm>
#define msg(var) cout << #var << " = " << var << endl
using namespace std;

const long long maxPal = 10000224;

long long cnt[maxPal];

bool isPal(long long n)
{
    string str = "";
    while (n > 0)
    {
        str.push_back(n % 10 + '0');
        n /= 10;
    }
    for (long long i = 0; i < str.size(); i++)
        if (str[i] != str[str.size() - i - 1])
            return false;

    return true;
}

void precalc()
{
    for (long long i = 1; i < maxPal; i++)
    {
        cnt[i] += cnt[i - 1];
        if (!isPal(i)) continue;
        if (isPal(i * i)) cnt[i]++;
    }
}

long long f(long long n)
{
    if (n == 0) return 0;
    int root = floor(sqrt(1.0 * n));
    return cnt[root];
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    freopen("ss.in", "r", stdin);
    freopen("ss.out", "w", stdout);
    precalc();

    long long t;
    cin >> t;
    for (long long T = 1; T <= t; T++)
    {
        long long ans = 0;
        long long a, b;
        cin >> a >> b;
        ans = f(b) - f(a - 1);

        cout << "Case #" << T << ": " << ans << "\n";
    }

    return 0;
}
