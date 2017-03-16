#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    freopen("C-small-attempt3.in", "rt", stdin);
    freopen("output.out", "wt", stdout);
    int T; cin >> T;
    for(int t = 1; t <= T; t++) {
        int c, d, v;
        cin >> c >> d >> v;
        int s = 0, ans = 0;
        for(int i = 0; i < d; i++) {
            int a; cin >> a;
            while(s + 1 < a && s < v) {
                ans ++;
                s += s + 1;
            }
            s += a;
        }
        while(s < v) {
            ans ++;
            s += s+1;
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
