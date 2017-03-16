#include <iostream>
#include <string>
#include <map>

using namespace std;

int solve()
{
    int c, d, v;
    cin >> c;
    cin >> d;
    cin >> v;
    int a[d + 1];
    for (int i = 0; i < d; i++)
    {
        cin >> a[i];
    }
    a[d] = v + 1;
    int q = 0;
    int s = 0;
    for (int i = 0; i < d + 1; i++)
    {
        while(s < a[i] - 1)
        {
            q++;
            s = 2 * s + 1;
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
