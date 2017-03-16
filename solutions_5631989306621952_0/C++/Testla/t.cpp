#include <bits/stdc++.h>

int t;

using std::cin;
using std::cout;
using std::endl;

int main() {
    std::string s, last;
    cin >> t;
    for (int ti = 1; ti <= t; ++ti) {
        cout << "Case #" << ti << ": ";
        cin >> s;
        last = std::string();
        for (int i = 0, l = s.size(); i < l; ++i)
            if (s[i] + last > last + s[i])
                last = s[i] + last;
            else
                last = last + s[i];
        cout << last << endl;
    }
}
