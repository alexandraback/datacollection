#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>

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
        int n, x;
        set<int> s;
        cin >> n;
        for (int j = 0; j < 2 * n * n - n; ++j) {
            cin >> x;
            if (s.count(x)) {
                s.erase(x);
            } else {
                s.insert(x);
            }
        }
        cout << "Case #" << i << ":";
        for (auto & x : s) {
            cout << " " << x;
        }
        cout << "\n";
    }


    return 0;
}