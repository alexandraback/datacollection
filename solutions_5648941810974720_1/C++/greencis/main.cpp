#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int T, n, u[299];
char s[9999];
char t[9999];
int ti;

string d[10] = { "ZERO", "SIX", "EIGHT", "FOUR", "TWO", "FIVE", "SEVEN", "THREE", "ONE", "NINE" };
char uni[11] = "ZXGUWFVTON", dig[11] = "0684257319";

int main()
{
    //freopen("A-large.in", "r", stdin);
    //freopen("A-large.out", "w", stdout);

    cin >> T;
    for (int ttt = 1; ttt <= T; ++ttt) {
        cin >> s;
        for (int i = 0; i < 299; ++i)
            u[i] = 0;
        n = strlen(s);
        for (int i = 0; s[i]; ++i)
            ++u[s[i]];
        ti = 0;
        for (int i = 0; i < 10; ++i) {
            while (u[uni[i]]) {
                t[ti++] = dig[i];
                for (int j = 0; j < d[i].size(); ++j)
                    --u[d[i][j]];
            }
        }
        t[ti] = 0;
        sort(t, t + ti);
        cout << "Case #" << ttt << ": " << t << "\n";
    }

    return 0;
}
