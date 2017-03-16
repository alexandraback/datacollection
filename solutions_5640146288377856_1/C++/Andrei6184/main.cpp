#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("A-large.in", "rt", stdin);
    freopen("output.out", "wt", stdout);
    int T; cin >> T;
    for(int t = 1; t <= T; t++) {
        int r, c, w;
        cin >> r >> c >> w;
        int ans = r*(c/w)+ w-1 + (c % w != 0);
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
