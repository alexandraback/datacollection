#include <iostream>
#include <string>
#include <map>

using namespace std;

int solve()
{
    int c, d;
    long long v;
    cin >> c;
    cin >> d;
    cin >> v;
    long long a[d + 1];
    for (int i = 0; i < d; i++)
    {
        cin >> a[i];
    }
    a[d] = v + 1;
    int q = 0;
    long long s = 0;
    for (int i = 0; i < d + 1; i++)
    {
        while(s * c < a[i] - 1)
        {
            q++;
            s += c * s + 1;
        }
        s += a[i];
    }
    return q;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        int s = solve();
        cout << "Case #" << i << ": " << s << endl;
    }
    return 0;
}
