#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        string s;
        cin >> s;
        char last = s[0];
        int c = 0;
        for (char sc : s) {
            if (last != sc) {
                c++;
                last = sc;
            }
        }
        if (last != '+') c++;
        cout << "Case #" << t << ": " << c << endl;
    }
}
