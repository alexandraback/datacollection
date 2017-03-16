#include <iostream>
#include <string>
#include <vector>

using namespace std;

int t;
string s;

int main() {
    cin >> t;
    for (int _ = 1; _ <= t; _++) {
        cin >> s;
        //
        string res;
        res += s[0];
        for (int i = 1; i < s.size(); i++) {
            if (s[i] < res[0]) {
                res += s[i];
            } else {
                res = s[i] + res;
            }
        }
        // print
        cout << "Case #" << _ << ": ";
        cout << res << endl;
    }
    return 0;
}