#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
    
    cin.tie(0);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    
    int TC;
    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        int len;
        string s;
        cin >> len >> s;
        int total = 0;
        int ans = 0;
        for (int i = 0; i <= len; i++) {
            int count = s[i] - '0';
            while (total < i) {
                total++;
                ans++;
            }
            total += count;
        }
        cout << "Case #" << tc << ": " << ans << endl;
    }

    return 0;
}
