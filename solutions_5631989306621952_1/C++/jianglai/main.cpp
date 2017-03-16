#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

string last_word(string & s) {
    string res;
    for (auto & c : s) {
        if (res + c < c + res) {
            res = c + res;
        } else {
            res = res + c;
        }
    }

    return res;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        string s;
        cin >> s;
        cout << "Case #" << i << ": " << last_word(s) << "\n";
    }


    return 0;
}