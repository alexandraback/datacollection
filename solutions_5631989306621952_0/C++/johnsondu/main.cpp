#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("outA.txt", "w", stdout);
    int T;
    string str;
    cin >> T;
    for(int i = 1; i <= T; ++ i) {
        cin >> str;
        string ans = "";
        ans += str[0];
        int len = str.size();

        for(int j = 1; j < len; ++ j) {
            if(str[j] >= ans[0]) {
                ans = str[j] + ans;
            }
            else ans = ans + str[j];
        }
        cout << "Case #" << i << ": " << ans << endl;

    }
    return 0;
}
