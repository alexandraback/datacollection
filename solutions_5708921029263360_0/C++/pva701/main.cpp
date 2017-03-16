#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <sstream>
#include <fstream>
using namespace std;
typedef long long ll;
struct Info {
    int x, y, z;
};

vector<Info> answers[4][4][4][11];

void solve() {
    int x = 3, y = 3 , z = 3, k;
    //cin >> x >> y >> z >> k;
    vector<int> a, b, c;
    for (int i = 0; i < x; ++i)
        for (int j = 0; j < y; ++j)
            for (int k = 0; k < z; ++k) {
                a.push_back(i);
                b.push_back(j);
                c.push_back(k);
            }

    int tot = 1<<a.size();
    int curAns = 0, curMask = 0;
    for (int ms = 0; ms < tot; ++ms) {
        if (ms % 1000000 == 0)
            cerr << ms << " from " << tot << endl;

        int cnt1[3][3], cnt2[3][3], cnt3[3][3];
        memset(cnt1, 0, sizeof cnt1);
        memset(cnt2, 0, sizeof cnt2);
        memset(cnt3, 0, sizeof cnt3);

        int bits = 0;
        int mxk = 0;
        int mxx = 0, mxy = 0, mxz = 0;

        vector<Info> cur;
        for (int i = 0; i < a.size(); ++i) {
            int bit = (ms>>i)&1;
            if (bit) {
                cnt1[a[i]][b[i]]++;
                cnt2[a[i]][c[i]]++;
                cnt3[b[i]][c[i]]++;
                mxx = max(mxx, a[i] + 1);
                mxy = max(mxy, b[i] + 1);
                mxz = max(mxz, c[i] + 1);

                mxk = max(mxk, cnt1[a[i]][b[i]]);
                mxk = max(mxk, cnt2[a[i]][c[i]]);
                mxk = max(mxk, cnt3[b[i]][c[i]]);

                cur.push_back({a[i], b[i], c[i]});
                //fail |= cnt1[a[i]][b[i]] > k || cnt2[a[i]][c[i]] > k || cnt3[b[i]][c[i]] > k;
            }
        }
        if (answers[mxx][mxy][mxz][mxk].size() < cur.size())
            answers[mxx][mxy][mxz][mxk] = cur;

        /*if (!fail && bits > curAns) {
            curAns = bits;
            curMask = ms;
        }*/
    }
    freopen("ans.txt", "w", stdout);
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j)
            for (int t = 1; t <= 3; ++t)
                for (int e = 1; e <= 10; ++e) {
                    printf("%d %d %d %d: ", i, j, t, e);
                    for (int o = 0; o < answers[i][j][t][e].size(); ++o)
                        printf("%d %d %d ", answers[i][j][t][e][o].x, answers[i][j][t][e][o].y, answers[i][j][t][e][o].z);
                    printf("\n");
                }
}

void solveTest() {
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<Info> ans;
    for (int i = 1; i <= k; ++i)
        if (answers[x][y][z][i].size() > ans.size())
            ans = answers[x][y][z][i];
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        printf("%d %d %d\n", ans[i].x + 1, ans[i].y + 1, ans[i].z + 1);
}

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    //solve();
    ifstream iin("ans.txt");
    string s;
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j)
            for (int p = 1; p <= 3; ++p)
                for (int t = 1; t <= 10; ++t) {
                    getline(iin, s);
                    stringstream in(s);
                    int a0, b0, c0, d0;
                    char c;
                    in >> a0 >> b0 >> c0 >> d0 >> c;
                    int x;
                    vector<int> arr;
                    while (in >> x)
                        arr.push_back(x);
                    for (int u = 0; u < arr.size(); u += 3)
                        answers[i][j][p][t].push_back({arr[u], arr[u + 1], arr[u + 2]});
                }

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        solveTest();
    }
    return 0;
}

