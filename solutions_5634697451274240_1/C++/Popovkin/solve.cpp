#include <iostream>
#include <fstream>
#define ll long long
#include <string>

using namespace std;

ll a, b, c, d, e;

string s;

int main() {
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    cin >> a;
    for (int i = 0; i < a; ++i) {
        cin >> s;
        while (s.size() > 0 && *s.rbegin() == '+') s.pop_back();
        cout << "Case #" << i + 1 << ": ";
        if (s.size() == 0) cout << 0 << "\n";
        else {
            int n = 1;
            for (int q = 1; q < s.size(); ++q)
                if (s[q] != s[q - 1]) ++n;
            cout << n << "\n";
        }
    }
}