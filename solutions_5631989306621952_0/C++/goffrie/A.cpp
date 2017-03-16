#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

void tc() {
    static int cas = 1;
    cout << "Case #" << cas++ << ": ";
    string s;
    cin >> s;
    string S;
    for (int i = 0; i < s.size(); ++i) {
        string l(1, s[i]);
        if (S + l < l + S) S = l + S;
        else S = S + l;
    }
    cout << S << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) tc();
}
