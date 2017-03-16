#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

void solve() {
    int max = 0;
    string s;

    cin >> max >> s;

    int current = 0;
    int add = 0;

    for (int i=0; i<=max; i++) {
        int shy = i;
        int num = s[i]-'0';
        if (num>0 && current<shy) {
            add += shy - current;
            current += add;
        }
        current += num;
    }

    cout << add << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
