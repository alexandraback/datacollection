#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        string a, ans;
        char fi;
        cin >> a;
        fi = a[0];
        ans = fi;
        for (int i = 1; i < a.size(); i++) {
            if (a[i] >= fi) {
                ans = a[i] + ans;
                fi = a[i];
            }
            else {
                ans += a[i];
            }
        } 
        cout << "Case #" << tt << ": " << ans << endl;
    }
}
