#include <bits/stdc++.h>
using namespace std;

int TC, N;
bool digits[10];

string conv(long long x) {
    if (x == 0) return "0";
    else {
        string ans = "";
        while (x != 0) {
            ans += '0' + (x % 10);
            x /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
}

int main() {
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        scanf("%d", &N);
        long long cur = N;
        int cnt = 0;
        if (N == 0) {
            printf("Case #%d: INSOMNIA\n", tc);
            continue;
        }
        memset(digits, 0, sizeof(digits));
        while (true) {
            string s = conv(cur);
            for (int i = 0; i < s.length(); i++) {
                if (!digits[s[i] - '0']) cnt++;
                digits[s[i] - '0'] = 1;
            }
            if (cnt == 10) {
                printf("Case #%d: %lld\n", tc, cur);
                break;
            }
            cur += N;
        }
    }
}
