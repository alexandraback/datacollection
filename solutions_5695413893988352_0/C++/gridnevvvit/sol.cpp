#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int toInt(string s1) {
    int ans = 0;
    int power = 1;
    for(int i = s1.size() - 1; i >= 0; i--) {
        ans += power * (s1[i] - '0');
        power *= 10;
    }
    return ans;
}

string ans[2];
int AnsDiff = -1;

void go(int pos, int x, string s1, string s2) {
    if (pos == s1.size()) {
        int diff = toInt(s1) - toInt(s2);
        if (diff < 0) diff *= -1;
        if (AnsDiff == -1 || diff < AnsDiff || (diff == AnsDiff && s1 < ans[0])) {
            ans[0] = s1;
            ans[1] = s2;
            AnsDiff = diff;
        }
        return;
    }
    if (x == 0) {
        if (s1[pos] == '?') {
            for(int i = 0; i < 10; i++) {
                s1[pos] = char(i + '0');
                go(pos, 1, s1, s2);
            }
            s1[pos] = '?';
        } else {
            go(pos, 1, s1, s2);
        }
    } else {
        if (s2[pos] == '?') {
            for(int i = 0; i < 10; i++) {
                s2[pos] = char(i + '0');
                go(pos + 1, 0, s1, s2);
            }
            s2[pos] = '?';
        } else {
            go(pos + 1, 0, s1, s2);
        }
    }
}

void solve(int test) {
    printf("Case #%d: ", test);
    string s1, s2;
    cin >> s1 >> s2;
    go(0, 0, s1, s2);
    printf("%s %s\n", ans[0].c_str(), ans[1].c_str());
    AnsDiff = -1;
}

int main() {
    int T;
    scanf("%d\n", &T);
    for(int i = 0; i < T; i++) {
        solve(i + 1);
    }
}
