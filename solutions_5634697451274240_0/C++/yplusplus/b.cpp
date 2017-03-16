#include <iostream>
using namespace std;

int main() {
    int T, Case = 1;
    cin >> T;
    string str;
    while (T--) {
        cin >> str;
        cout << "Case #" << Case++ << ": ";
        auto pos = str.rfind('-');
        if (pos == string::npos) {
            cout << 0 << endl;
        } else {
            str = str.substr(0, pos + 1);
            int ans = unique(str.begin(), str.end()) - str.begin();
            cout << ans << endl;
        }
    }
    return 0;
}
