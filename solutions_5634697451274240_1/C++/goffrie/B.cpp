#include <iostream>
#include <string>

using namespace std;

void tc() {
    string s;
    cin >> s;

    static int cas = 1;
    cout << "Case #" << cas++ << ": ";

    char last = 0;
    int n = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != last) {
            last = s[i];
            ++n;
        }
    }
    if (last == '+') --n;
    cout << n << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) tc();
}
