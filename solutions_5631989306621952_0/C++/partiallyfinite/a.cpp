#include <iostream>
#include <string>

using namespace std;

int t;
string s;

int main() {
    cin >> t;
    for (int x = 0; x ++< t;) {
        cin >> s;
        string a;
        a += s[0];
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] >= a[0]) a = s[i] + a;
            else a += s[i];
        }
        cout << "Case #" << x << ": " << a << '\n';
    } 
}

