#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;



int main() {
    int T;
    cin >> T;
    for (int z = 1; z <= T; ++z) {
        cout << "Case #" << z << ":" << " ";
        string s;
        cin >> s;
        int i1 = 0, i2 = s.size() - 1;
        int cnt = 0;
        while (true) {
            while (i2 >= i1 && s[i2] == '+') {
                --i2;
            }
            if (i1 > i2) {
                break;
            }

            if (s[i1] == '-') {
                ++cnt;
                while (i1 <= i2 && s[i1] == '-') {
                    ++i1;
                }
                reverse(s.begin() + i1, s.begin() + i2 + 1);
                for (int i = i1; i <= i2; ++i) {
                    s[i] = (s[i] == '+' ? '-' : '+');
                }
            } else {
                int i = i1;
                ++cnt;
                while (i <= i2 && s[i] == '+') {
                    s[i] = '-';
                    ++i;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
