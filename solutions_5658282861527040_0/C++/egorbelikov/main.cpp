#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

void solve()
{
    int a, b, k, res = 0;
    cin >> a >> b >> k;
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            if ((i&j) < k)
                res++;
    cout << res << endl;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Case #" <<  i + 1 << ": ";
        solve();
    }
}

