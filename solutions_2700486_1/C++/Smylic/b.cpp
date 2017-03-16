#include <iostream>

using namespace std;

double f(int n, int x, int y)
{
    int k = 1;
    for (; k * (k + 1) <= 2*n; k += 2);
    if (x+y > k || -x+y > k || y > k-2)
        return 0.0;
    k -= 2;
    if (x+y < k && -x+y < k)
        return 1.0;
    double res = 0;
    double c = 1.0;
    n -= k*(k+1)/2;
    if (y < n-k-1)
        return 1.0;

    for (int i=n; i > y; i--)
    {
        res += c;
        c *= i;
        c /= n-i+1;
        res *= 0.5;
        c *= 0.5;
    }
    for (int i = y; i > 0; i--)
        res *= 0.5;
    return res;
}

int main()
{
    int t;
    cin >> t;
    for (int tt=1; tt<=t; tt++)
    {
        int n, x, y;
        cin >> n >> x >> y;
        cout.setf(ios::fixed);
        cout.precision(15);
        cout << "Case #" << tt << ": " << f(n, x, y) << endl;
    }
    return 0;
}
