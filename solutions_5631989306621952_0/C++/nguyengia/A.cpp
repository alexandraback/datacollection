#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string process (string s) {
    string t;
    t += s[0];
    for (int i=1; i<s.length(); i++) {
        if (s[i] < t[0]) {
            t += s.substr(i, 1);
        } else {
            t = s.substr(i, 1) + t;
        }
    }
    return t;
}

int main () {
    int n;
    string s;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s;
        cout << "Case #" << i+1 << ": " << process(s) << endl;
     }
  return 0;
}
