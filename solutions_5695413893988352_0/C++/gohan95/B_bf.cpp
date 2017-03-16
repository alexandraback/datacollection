//Done by: K Ashwin

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TR(c, it) \
for (auto it = (c).begin(); it != (c).end(); it++)

#define s(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define set0(a) memset(a, 0, sizeof(a))
#define setdp(a) memset(a, -1, sizeof(a))
#define INF 2000000000
#define MOD 1000000007

string s1, s2;

bool check(int x, int y)
{
    for (int i = s1.size() - 1; i >= 0; --i) {
        if (s1[i] == '?' || s1[i] - '0' == (x % 10))
            x /= 10;

        else
            return 0;
    }

    if (x)
        return 0;

    for (int i = s2.size() - 1; i >= 0; --i) {
        if (s2[i] == '?' || s2[i] - '0' == (y % 10))
            y /= 10;

        else
            return 0;
    }

    if (y)
        return 0;

    return 1;
}

int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("op.txt", "w", stdout);

    int t, tt, t1, C, J;
    string out;


    cin >> t;

    tt = 0;
    while (t--) {
        ++tt;

        cin >> s1 >> s2;

        t1 = INF, C = -1, J = -1;
        for (int i = 0; i <= 999; ++i) {
            for (int j = 0; j <= 999; ++j) {
                if (check(i, j)) {
                    if (abs(i - j) < t1) {
                        t1 = abs(i - j);
                        C = i;
                        J = j;
                    }
                }
            }
        }

        assert(C != -1 && J != -1);

        printf("Case #%d: ", tt);

        out.clear();
        int tmp = 0;
        while (tmp < s1.size()) {
            ++tmp;
            out.pb((C % 10) + '0');
            C /= 10;
        }

        reverse(out.begin(), out.end());

        cout << out << " ";

        C = J;
        out.clear();
        tmp = 0;
        while (tmp < s1.size()) {
            ++tmp;
            out.pb((C % 10) + '0');
            C /= 10;
        }

        reverse(out.begin(), out.end());

        cout << out << endl;
    }

    return 0;
}
