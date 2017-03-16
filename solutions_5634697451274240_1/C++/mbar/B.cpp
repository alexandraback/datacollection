#include <iostream>
#include <string>

using namespace std;

const char cc[] = "+-";

int flips(const string& s, int n, int k) {
    const char c = cc[k];
    int i=n;
    // skip the padded targets
    while (i>=0 && s[i] == c) --i;
    if (i == -1) return 0;
    return 1 + flips(s, i, 1-k);
}

int main() {
    int T;
    cin >> T;
    for (int cs=1; cs<=T; ++cs) {
        string s;
        cin >> s;
        int r = flips(s, s.size()-1, 0);
        cout << "Case #" << cs << ": " << r << "\n";
    }
}
