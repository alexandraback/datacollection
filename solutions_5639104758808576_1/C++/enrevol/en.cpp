#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int tn;
    cin >> tn;
    for (int ti = 1; ti <= tn; ++ti) {
        int n;
        string s;
        cin >> n >> s;
        int cnt = 0;
        int answer = 0;
        for (int i = 0; i < int(s.size()); ++i) {
            if (cnt < i) {
                answer += i - cnt;
                cnt = i;
            }
            cnt += s[i] - '0';
        }
        cout << "Case #" << ti << ": " << answer << '\n';
    }
}
