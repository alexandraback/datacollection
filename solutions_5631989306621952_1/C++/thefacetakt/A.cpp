#include "bits/stdc++.h"

using namespace std;


int main() {
    int T;
    cin >> T;
    for (int z = 0; z < T; ++z) {
        cout << "Case #" << z + 1 << ": ";
        string s;
        cin >> s;
        deque<char> winning(1, s[0]);
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] < winning[0]) {
                winning.push_back(s[i]);
            } else {
                winning.push_front(s[i]);
            }
        }
        for (int i = 0; i < s.size(); ++i) {
            cout << winning[i];
        }
        cout << "\n";

    }
}
