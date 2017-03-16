#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A.out", "w", stdout);

    int test;
    cin >> test;
    for(int tc = 1; tc <= test; tc++) {
        int n; string s;
        cin >> n >> s;
        int c = 0, result = 0;
        for(int i = 0; i <= n; i++) {
            int j = s[i] - '0';
            if (c < i) result += i - c;
            c = max(c, i);
            c += j;
        }
        cout << "Case #" << tc << ": " << result << endl;
    }
}
