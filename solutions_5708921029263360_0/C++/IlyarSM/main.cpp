#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstdio>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <memory>
#include <bitset>
#include <functional>
#include <cassert>
#include <fstream>
using namespace std;

#define fori(i, n) for (int i = 0; i < (int)(n); i++)
#define mp(x, y) make_pair((x), (y))

using llg = long long;
using ldb = long double;

vector<vector<int> > v;

map<pair<int, int>, int> j_p, j_s, p_s;

void solve(int jck, int p, int s, int k)
{
    v.clear();
    j_p.clear();
    j_s.clear();
    p_s.clear();

    for (int i = 1; i <= jck; i++)
        for (int u = 1; u <= p; u++)
            for (int c = 1; c <= s; c++)
                v.push_back({i, u, c});

    int pn = jck * p * s;
    int tn = 1 << (jck * p * s);

    assert(v.size() == (jck * p * s));
    int tmax = -1, mask_max = 0;

    pair<int, int> tpair;
    bool is_ok = true;
    int cnt;
    for (int mask = 0; mask < tn; mask++)
    {
        cnt = 0;
        is_ok = true;
        j_p.clear();
        j_s.clear();
        p_s.clear();
        for (int j = 0; j < pn; j++)
        {
            if (mask & (1 << j))
            {
                cnt++;
                tpair = mp(v[j][0], v[j][1]);
                j_p[tpair]++;
                if (j_p[tpair] > k)
                {
                    is_ok = false;
                    break;
                }
                tpair = mp(v[j][0], v[j][2]);
                j_s[tpair]++;
                if (j_s[tpair] > k)
                {
                    is_ok = false;
                    break;
                }
                tpair = mp(v[j][1], v[j][2]);
                p_s[tpair]++;
                if (p_s[tpair] > k)
                {
                    is_ok = false;
                    break;
                }
            }
        }
        if (is_ok)
        {
            if (tmax < cnt)
            {
                tmax = cnt;
                mask_max = mask;
            }
        }
    }
    cout << jck << ' ' << p << ' ' << s << ' ' << k << endl;
    cout << tmax << endl;
    for (int i = 0; i < pn; i++)
    {
        if (mask_max & (1 << i))
        {
            cout << v[i][0] << ' ' << v[i][1] << ' ' << v[i][2] << endl;
        }
    }
    cout << endl;
}

void gen()
{
    freopen("input.txt", "r", stdin);
    freopen("tests.txt", "w", stdout);

    for (int j = 1; j <= 3; j++)
        for (int p = 1; p <= 3; p++)
            for (int s = 1; s <= 3; s++)
                for (int k = 1; k <= 2; k++)
                {
                    if (j <= p && p <= s)
                        solve(j, p, s, k);
                }
}

void main_solve()
{

    int jck, p, k, s;
    cin >> jck >> p >> s >> k;

    if (k >= 3)
    {
        cout << jck * p * s << endl;
        for (int i = 1; i <= jck; i++)
            for (int j = 1; j <= p; j++)
                for (int c = 1; c <= s; c++)
                {
                    cout << i << ' ' << j << ' ' << c << endl;
                }
    }
    else
    {
        ifstream fin("tests.txt");
        int tj, tp, tk, ts, cnt;

        int p1, p2, p3;

        vector<vector<int> > ans;

        do
        {
            ans.clear();
            fin >> tj >> tp >> ts >> tk >> cnt;
            
            for (int i = 0; i < cnt; i++)
            {
                fin >> p1 >> p2 >> p3;
                ans.push_back({ p1, p2, p3 });
            }

            if (tj == jck && tp == p && ts == s && tk == k)
                break;
        } while (true);

        cout << cnt << endl;

        for (int i = 0; i < cnt; i++)
            cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << endl;

        fin.close();
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tests;
    cin >> tests;

    for (int i = 0; i < tests; i++)
    {
        cout << "Case #" << to_string(i + 1) << ": ";
        main_solve();
    }


    return 0;
}