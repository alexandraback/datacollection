#include <iostream>
#include <string>
using namespace std;

int main() {
    int tests; cin >> tests;
    for(int test=1; test<=tests; test++) {
        string s; cin >> s;
        string s2 = string(1, s[0]);
        for(int i=1; i<s.size(); i++) {
            if (s[i] >= s2[0])
                s2 = string(1, s[i]) + s2;
            else
                s2 = s2 + string(1, s[i]);
        }
        cout << "Case #" << test << ": " << s2 << endl;
    }
}
