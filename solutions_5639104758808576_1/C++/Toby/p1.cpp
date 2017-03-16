#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int s_max, string s) {
    int sum = 0;
    int add = 0;
    for (int i = 0; i <= s_max; i++) {
        if (sum < i) {
            add += i - sum;
            sum = i;
        }
        int s_i = s[i] - '0';
        sum += s_i;
    }
    return add;
}

int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        string s;
        int s_max;
        cin >> s_max >> s;
        int ans = solve(s_max, s);

        cout << "Case #" << testcase << ": ";
        cout << ans;
        cout << endl;
    }
    return 0;
}
