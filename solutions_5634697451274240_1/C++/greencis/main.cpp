#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int t, n, cnt;
char s[105];

int main()
{
    //freopen("B-large.in", "r", stdin);
    //freopen("B-large.out", "w", stdout);

    cin >> t;
    for (int ttt = 1; ttt <= t; ++ttt) {
        cin >> s;
        n = strlen(s);
        cnt = 0;
        for (int i = 1; i < n; ++i)
            cnt += (s[i] != s[i - 1]);
        if (s[n - 1] == '-') ++cnt;
        cout << "Case #" << ttt << ": " << cnt << "\n";
    }

    return 0;
}
