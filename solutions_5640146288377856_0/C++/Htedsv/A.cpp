#include <iostream>
using namespace std;
int r, c, w, ans;
int main()
{
    int T;
    cin >> T;
    for (int I = 1; I <= T; ++I)
    {
        cin >> r >> c >> w;
        ans = c / w * r;
        ans += w;
        if (c % w == 0)
            ans --;
        printf("Case #%d: %d\n", I, ans);
    }
}

