#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    int t;
    cin >> t;

    for(int tc = 1; tc <= t; tc++) {

        string ans;
        int x, y;
        cin >> x >> y;

        int cx = 0, cy = 0;

        int ss = 1;

        while(cx != x) {
            if(cx > x) {
                ans += "EW";
                cx--;
            }
            else {
                ans += "WE";
                cx++;
            }
        }

        while(cy != y) {
            if(cy > y) {
                ans += "NS";
                cy--;
            }
            else {
                ans += "SN";
                cy++;
            }
        }

        cout << "Case #" << tc << ": " << ans << '\n';
   }

    return 0;
}
