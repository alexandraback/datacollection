#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int toInt(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans |= (1 << (s.size() - i - 1)) * (s[i] - '0');
    }
    return ans;
}

int sum(int i) {
    int ans = 0;
    while(i) {
        ans += i % 2;
        i /= 2;
    }
    return ans;
}

int main() {
    freopen("A-small-attempt1.in", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    size_t t;
    cin >> t;
    for (size_t q = 0; q < t; q++) {
        int n, l;
        cin >> n >> l;
        vector < int > f(n), s(n), sd(n);
        for (int i = 0; i < n; i++) {
            string st;
            cin >> st;
            f[i] = (toInt(st));
        }
        for (int i = 0; i < n; i++) {
            string st;
            cin >> st;
            s[i] = (toInt(st));
        }
        sort(s.begin(), s.end());
        int mn = l + 1;
        for (int i = 0; i < (1 << l); i++) {
            for (int j = 0; j < n; j++)
                sd[j] = f[j] ^ i;
            sort(sd.begin(), sd.end());
            if (s == sd)
                mn = min(mn, sum(i));
        }
        cout << "Case #" << q + 1 << ": ";
        if (mn <= l) {
            cout<< mn << endl;
        } else {
            cout<< "NOT POSSIBLE" << endl;
        }
    }
    return 0;
}
