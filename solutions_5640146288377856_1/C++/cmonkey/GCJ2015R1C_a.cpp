#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t, T;
    int r, c, w;
    int ans;

    freopen("A-large.in", "r", stdin);
    freopen("a.out", "w", stdout);

    cin >> T;
    for (t = 1; t <= T; t++){
        cin >> r >> c >> w;
        ans = r * (c / w);
        ans += (w - 1);
        if (c % w > 0) ans += 1;
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
