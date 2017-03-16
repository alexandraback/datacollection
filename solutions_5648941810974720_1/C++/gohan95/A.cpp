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

int has[200], cnt[15];

int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("op.txt", "w", stdout);

    int t, tt;
    string s;

    cin >> t;

    tt = 0;
    while (t--) {
        ++tt;
        cin >> s;

        TR (s, it)
            has[*it]++;

        cnt[0] = has['Z'];
        has['Z'] -= cnt[0];
        has['E'] -= cnt[0];
        has['R'] -= cnt[0];
        has['O'] -= cnt[0];

        cnt[2] = has['W'];
        has['T'] -= cnt[2];
        has['W'] -= cnt[2];
        has['O'] -= cnt[2];

        cnt[4] = has['U'];
        has['F'] -= cnt[4];
        has['O'] -= cnt[4];
        has['U'] -= cnt[4];
        has['R'] -= cnt[4];

        cnt[5] = has['F'];
        has['F'] -= cnt[5];
        has['I'] -= cnt[5];
        has['V'] -= cnt[5];
        has['E'] -= cnt[5];

        cnt[6] = has['X'];
        has['S'] -= cnt[6];
        has['I'] -= cnt[6];
        has['X'] -= cnt[6];

        cnt[7] = has['V'];
        has['S'] -= cnt[7];
        has['E'] -= cnt[7];
        has['V'] -= cnt[7];
        has['E'] -= cnt[7];
        has['N'] -= cnt[7];

        cnt[8] = has['G'];
        has['E'] -= cnt[8];
        has['I'] -= cnt[8];
        has['G'] -= cnt[8];
        has['H'] -= cnt[8];
        has['T'] -= cnt[8];

        cnt[9] = has['I'];
        has['N'] -= cnt[9];
        has['I'] -= cnt[9];
        has['N'] -= cnt[9];
        has['E'] -= cnt[9];

        cnt[3] = has['R'];
        has['T'] -= cnt[3];
        has['H'] -= cnt[3];
        has['R'] -= cnt[3];
        has['E'] -= cnt[3];
        has['E'] -= cnt[3];

        cnt[1] = has['O'];
        has['O'] -= cnt[1];
        has['N'] -= cnt[1];
        has['E'] -= cnt[1];

        REP (i, 'A', 'Z')
            assert(has[i] == 0);

        printf("Case #%d: ", tt);
        REP (i, 0, 9) {
            while (cnt[i]) {
                cout << i;
                cnt[i]--;
            }
        }
        cout << endl;
    }

    return 0;
}
