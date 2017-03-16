#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
using namespace std;

void solve()
{
    string s; cin >> s;

    string cur;
    for (auto &c: s) {
        string s1 = cur + c;
        string s2 = c + cur;

        cur = max(s1, s2);
    }

    cout << cur << endl;
}

int main()
{
    int t; cin >> t;
    for (int cn = 1; cn <= t; cn++) {
        cout << "Case #" << cn << ": ";
        solve();
    }
    return 0;
}
