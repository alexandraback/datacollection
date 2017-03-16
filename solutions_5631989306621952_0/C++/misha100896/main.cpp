#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        string s, s1;
        cin >> s;
        s1 = s[0];
        for (int i = 1; i < s.size(); ++i)
            if (s[i] < s1[0])
                s1 += s[i];
            else
                s1 = s[i] + s1;
        cout << s1 << '\n';
    }
    return 0;
}
