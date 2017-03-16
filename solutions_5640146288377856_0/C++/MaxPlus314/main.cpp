#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int q, r, c, w;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        cin >> r >> c >> w;
        cout << "Case #" << i + 1 << ": " << c / w * r + w - !(c % w) << '\n';
    }
    return 0;
}
