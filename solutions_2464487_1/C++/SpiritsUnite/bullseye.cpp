#include <iostream>

using namespace std;

int T;
long long r, t, x;

bool check(long long n)
{
    long long need = n * x + (n * (n - 1) / 2) * 4;
    return need <= t;
}

int main()
{
    cin >> T;
    for (int c = 1; c <= T; c++)
    {
        cin >> r >> t;
        x = 2 * r + 1;
        long long lo = 1, hi = 707106790;
        while (lo + 1 < hi)
        {
            long long mid = (lo + hi) / 2;
            if (check(mid)) lo = mid;
            else hi = mid;
        }
        cout << "Case #" << c << ": " << lo << '\n';
    }
}

