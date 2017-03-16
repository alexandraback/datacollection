#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main() {
    char map[] = 
        "yhesocvxduiglbkrztnwjpfmaq";
      // abcdefghijklmnopqrstuvwxyz
    string s;
    getline(cin, s);
    int n = atoi(s.c_str());
    for (int c = 1; c <= n; c++) {
        getline(cin, s);
        for (unsigned i = 0; i < s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] = map[s[i]-'a'];
            }
        }
        cout << "Case #" << c << ": " << s << endl;
    }
    return 0;
}