
#include <iostream>
#include <string>

using namespace std;

int solve(string s) {
    int moves = s.back() == '-' ? 1 : 0;
    for (int i = 0; i + 1 < s.size(); i++)
        if (s[i] != s[i + 1])
            moves++;
    return moves;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        string s;
        cin >> s;
        cout << "Case #" << t << ": " << solve(s) << endl;
    }
}
