#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        string s, t;
        cin >> s;
        for (auto &c: s) t = max(t + c, c + t);
        cout << "Case #" << cas << ": " << t << '\n';
    }
}
