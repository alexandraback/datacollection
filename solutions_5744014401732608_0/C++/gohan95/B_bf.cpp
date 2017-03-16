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

int b, m, mat[7][7], cnt, vis[10];

bool dfs(int x)
{
    //cout << "dfs " << x << endl;
    if (x == b - 1) {
        cnt++;

        return 1;
    }

    if (vis[x]) {
        //cout << x << " hdd\n";
        return 0;
    }

    vis[x] = 1;

    REP (j, 0, b - 1) {
        //cout << x << " " << j << " " << mat[x][j] << " " << b << endl;
        if (mat[x][j])
            if (!dfs(j))
                return 0;
    }

    vis[x] = 0;

    return 1;
}

bool fnc(int mask)
{
    set0(mat);
    int t1, i, j;

    /*REP (i, 0, b - 1) {
        REP (j, 0, b - 1) {
            if (i == j || i == b - 1) {
                mat[i][j] = 0;

                continue ;
            }

            t1 = i * b + j;
            if ((1<<t1) & mask)
                mat[i][j] = 1;

            else
                mat[i][j] = 0;
        }
    }*/

    t1 = i = j = 0;
    while (t1 != (b * b - b - b + 1)) {
        //cout << t1 << " " << i << " " << j << " " << (mask & (1<<t1)) << endl;
        if (i == j) {
            t1--;
            mat[i][j] = 0;
        }

        else if ((1<<t1) & mask)
            mat[i][j] = 1;

        else
            mat[i][j] = 0;

        t1++;
        j++;

        if (j == b) {
            i++;
            j = 0;
        }
    }

    /*cout << "Mask = " << mask << endl;
    REP (i, 0, b - 1) {
        REP (j, 0, b - 1)
            cout << mat[i][j] << " ";
        cout << endl;
    }*/

    set0(vis);

    cnt = 0;
    dfs(0);

    //cout << " " << cnt << endl;
    if (cnt == m) {
        cout << "POSSIBLE\n";

        REP (i, 0, b - 1) {
            REP (j, 0, b - 1)
                cout << mat[i][j];
            cout << endl;
        }

        return 1;
    }

    return 0;
}

int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("op.txt", "w", stdout);

    int t, flag, tt = 0;

    cin >> t;

    while (t--) {
        tt++;
        cin >> b >> m;

        int tmp = 1, hh = b * b - b - b + 1;
        REP (i, 1, hh)
            tmp *= 2;
        tmp--;

        //cout << tmp << endl;

        cout << "Case #" << tt << ": ";
        flag = 0;
        REP (i, 0, tmp)
            if (fnc(i)) {
                flag = 1;
                break ;
            }

        if (!flag)
            cout << "IMPOSSIBLE\n";
    }

    return 0;
}
