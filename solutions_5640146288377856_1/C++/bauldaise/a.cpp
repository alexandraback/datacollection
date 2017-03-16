#include <iostream>
#include <cstdio>
using namespace std;

void cans(int test, int ans)
{
    cout << "Case #" << test << ": " << ans << endl;
}

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {

        int R, C, W;
        cin >> R >> C >> W;
        int ans = ( C / W ) * R + (W - 1);
        if (C % W > 0) ans++;
        cans(tt, ans);
    }
    return 0;

}
