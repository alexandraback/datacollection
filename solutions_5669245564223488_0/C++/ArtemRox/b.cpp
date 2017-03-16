#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 10;
const int K = 26;

string s[N];
int n, now[N], last[K];

bool check() {
    for (int i = 0; i < K; i++)
        last[i] = -1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[now[i]].size(); j++) {
            int c = s[now[i]][j] - 'a';
            if (last[c] != -1 && last[c] != cnt - 1)
                return 0;
            last[c] = cnt++;
        }
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int l = 0; l < t; l++) {
        cout << "Case #" << l + 1 << ": ";
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> s[i];
        for (int i = 0; i < n; i++)
            now[i] = i;
        int ans = 0;
        do { ans += check(); }
        while (next_permutation(now, now + n));
        cout << ans << endl;
    }
    return 0;
}
