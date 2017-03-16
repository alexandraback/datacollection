#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string s;
    int t, count, len;
    char prev, curr;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> s;
        len = s.length();
        if (0 == len) {
            if ('+' == s[0]) cout << "Case #" << i << ": 0" << endl;
            else cout << "Case #" << i << ": 1" << endl;
            continue;
        }
        count = 0;
        prev = s[0];
        for (int j = 1; j < len; ++j) {
            curr = s[j];
            if (curr != prev) {
                ++count;
                prev = s[j];
            }
        }
        if ('-' == prev) ++count;
        cout << "Case #" << i << ": " << count << endl;
    }
    return 0;
}
