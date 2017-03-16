#include <iostream>

using namespace std;

void solve()
{
    int r, c, w;
    cin >> r >> c >> w;

    int perRow = c / w;
    if(c % w)
        perRow++;

    int soFar = r * perRow;
    soFar++;
    soFar += w - 2;

    cout << soFar;
}

int main()
{
    int t;
    cin >> t;

    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
}
