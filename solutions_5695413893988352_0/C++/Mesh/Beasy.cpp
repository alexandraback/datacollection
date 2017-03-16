#include <iostream>
#include <sstream>
#include <cassert>
#include <cmath>

using namespace std;


bool comp(int n, string s) {
    string ns = to_string(n);
    if (ns.length() > s.length()) return false;
    ns = string(s.length()-ns.length(), '0') + ns;
    for (int i = 0; i < ns.length(); i++) {
        if (s[i] != '?' && s[i] != ns[i]) return false;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        
        string a, b;
        cin >> a >> b;
        int n = a.length();
        
        int m = 999, n1, n2;
        for (int i = 0; i <= 999; i++) {
            for (int j = 0; j <= 999; j++) {
                if (comp(i, a) && comp(j, b)) {
                    if (m > abs(i-j)) {
                        m = abs(i-j);
                        n1 = i; n2 = j;
                    }
                }
            }
        }
        
        cout << string(abs(int(to_string(n1).length()-n)), '0') << n1 << " " << string(abs(int(to_string(n2).length()-n)), '0') << n2 << endl;
    }
}
