#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX_S = 1005;

int main() {
    int tests;

    cin >> tests;

    for (int test_id = 1; test_id <= tests; test_id++) {
        int shy;
        char s[MAX_S];

        cin >> shy >> s;

        int now = s[0] - '0', ans = 0;

        for (int i = 1; i <= shy; i++) {
            if (now < i) {
                ans += i - now;
                now = i;
            }

            now += s[i] - '0';
        }

        cout << "Case #" << test_id << ": " << ans << endl;
    }

    return 0;
}
