#include <iostream>
#include <string>

using namespace std;

int solve()
{
    int r, c ,w;
    cin >> r;
    cin >> c;
    cin >> w;
    if (w == 1)
        return r * c;
    int p = c / w;
    int a = p;
    a *= r;
    if (c % w == 0)
    {
        a += w - 1;
    }
    else
        a += w;
    return a;
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
