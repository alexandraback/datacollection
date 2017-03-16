#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define F first
#define S second
#define MP make_pair

const int N = 20;
const int SZ = (1 << N);
int cnt[SZ][20];
vector<int> pref[SZ];
int val[444];

struct chest
{
    int type;
    vector<int> keys;

    void read()
    {
        cin >> type;

        int k;
        cin >> k;

        keys.resize(k);
        for (int i = 0; i < k; ++i)
            cin >> keys[i];
    }
};

chest c[N];

void solve(int test)
{
    fill(val, val + 444, -1);
    for (int i = 0; i < SZ; ++i)
    {
        pref[i].clear();
        for (int j = 0; j < N; ++j)
            cnt[i][j] = 0;
    }

    int n, k;
    cin >> k >> n;

    vector<int> have(k);
    for (int i = 0; i < k; ++i)
        cin >> have[i];

    for (int i = 0; i < n; ++i)
        c[i].read();

    int f = 0;
    for (int i = 0; i < n; ++i)
        if (val[c[i].type] == -1)
            val[c[i].type] = f++;

    for (int i = 0; i < k; ++i)
        if (val[have[i]] >= 0)
            ++cnt[0][val[have[i]]];

    for (int mask = 0; mask < (1 << n); ++mask)
        for (int j = 0; j < n; ++j)
        {
            if (mask & (1 << j))
                continue;
            int tval = val[c[j].type];
            if (cnt[mask][tval] == 0)
                continue;
            int go = (mask | (1 << j));
            vector<int> cur = pref[mask];
            cur.push_back(j + 1);
            if (pref[go].size() > 0 && cur >= pref[go])
                continue;
            pref[go] = cur;
            for (int k = 0; k < n; ++k)
                cnt[go][k] = cnt[mask][k];
            --cnt[go][tval];
            for (int k = 0; k < c[j].keys.size(); ++k)
            {
                int curk = c[j].keys[k];
                if (val[curk] == -1)
                    continue;
                ++cnt[go][val[curk]];
            }
        }

    cout << "Case #" << test << ": ";
    if (pref[(1 << n) - 1].size() == 0)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for (int i = 0; i < n; ++i)
            cout << pref[(1 << n) - 1][i] << " ";
        cout << endl;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int test;
    cin >> test;
    for (int i = 1; i <= test; ++i)
        solve(i);


    return 0;
}
