#include<iostream>
#include<fstream>
#include<algorithm>
#define ll long long
using namespace std;
int solve() {
    string s;
    string s1, s2;
    string cur = "";
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        s1 = cur;
        s2 = " " + cur;
        s1.push_back(s[i]);
        s2[0] = s[i];
        cur = max(s1, s2);
    }
    cout << cur << endl;
}

int main(void) {
    int T;
    cin >> T;
    int k, c, s;
   
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: ", t);
        solve();
    }
}
