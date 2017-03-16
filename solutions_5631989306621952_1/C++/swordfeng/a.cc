#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        string s;
        cin >> s;
        string o = s.substr(0, 1);
        for (int j = 1; j < s.size(); j++) {
            if (s[j] >= o[0]) o = s.substr(j, 1) + o;
            else o += s.substr(j, 1);
        }
        cout << "Case #" << i << ": " << o << endl;
    }
    return 0;
}

