#include <bits/stdc++.h>

using namespace std;
int t;
int main() {
    cin >> t;
    for (int test = 1; test <= t; test++) {
        string s;
        cin >> s;
        int flips = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '-') {
                flips += (i == 0 ? 1 : 2);
                while (i + 1 < s.size() && s[i + 1] == '-') {
                    i++;
                }
            }
        }
        cout << "Case #" << test << ": " << flips << endl;
    }
}