#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("small.in", "r", stdin);
    freopen("small.out", "w", stdout);
    int nbT;
    int R,C, W;
    cin >> nbT;
    for (int t = 1; t <= nbT; t++)
    {
        cin >> R >> C >> W;
        cout << "Case #" << t << ": ";
        int ans = (R-1)*(C/W);
        //if (W != C)
            ans += ((C-W)/W)+W;
        if (C%W)
            ans++;

        cout << ans << '\n';


    }
    return 0;
}
