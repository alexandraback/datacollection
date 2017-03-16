#include <iostream>
#include <algorithm>
using namespace std;

string solve(string s) {
    string one;
    string two;
    
    for (char c : s) {
        if (one.empty() || c >= one.back()) {
            one.push_back(c);
        } else {
            two.push_back(c);
        }
    }
    
    reverse(one.begin(), one.end());
    one += two;
    return one;
}

int main() {
    int T; cin >> T; cin.ignore();
    for (int t = 1; t <= T; t++) {
        string s; getline(cin, s);
        string out = solve(s);
        cout << "Case #" << t << ": " << out << endl;
    }
}