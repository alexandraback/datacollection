#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

string s;

int main() {
    int T;
    cin >> T;
    for (int TC = 1; TC <= T; TC++) {
        cin >> s;
        string t = "";
        for (char c : s) {
            if (t == "" || c >= t[0]) t = c + t;
            else t += c;
        }
        cout << "Case #" << TC << ": ";
        cout << t << '\n';
    }
}
