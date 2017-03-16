#include <cstdio>
#include <assert.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstring>
#include <hashtable.h>

using namespace std;
typedef long long ll;
int i, j, k, m, n, cnt[200], inside_count[200], inside_cnt[200][200], opener[200], closed[200], g[200][200], leads[200][200];
vector<int> opens[200];
char ss[10002];

int old_cnt[200], old_closed[200];
bool can_be_solved()
{
    int i, j, k;

    for (i = 0; i < 200; i++)
    {
        old_cnt[i] = cnt[i];
        old_closed[i] = closed[i];
    }

    int sg = 1;
    while (sg)
    {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                g[i][j] = ((i == j) || (inside_cnt[i][opener[j]])) && closed[i] && closed[j];
        for (k = 0; k < n; k++) if (closed[k])
            for (i = 0; i < n; i++) if (g[i][k])
                for (j = 0; j < n; j++)
                    if (g[k][j]) g[i][j] = 1;

        for (i = 0; i < n; i++) if (closed[i])
            for (j = 0; j < 200; j++)
            {
                leads[i][j] = 0;
            }
        for (i = 0; i < n; i++) if (closed[i])
            for (k = 0; k < n; k++) if (g[i][k])
                for (j = 0; j < 200; j++)
                    if (inside_cnt[k][j]) leads[i][j] = 1;

        sg = 0;
        for (i = 0; i < 200 && !sg; i++) if (cnt[i])
        {
            for (j = 0; j < opens[i].size(); j++)
                if (closed[opens[i][j]] && leads[opens[i][j]][i])
                {
                    cnt[i]--;
                    closed[opens[i][j]] = 0;
                    for (k = 0; k < 200; k++)
                    {
                        cnt[k] += inside_cnt[opens[i][j]][k];
                    }
                    sg = 1;
                    break;
                }
        }
    }

    sg = 1;
    while (sg)
    {
        sg = 0;
        for (i = 0; i < 200 && !sg; i++) if (cnt[i])
        {
            for (j = 0; j < opens[i].size(); j++)
                if (closed[opens[i][j]])
                {
                    cnt[i]--;
                    closed[opens[i][j]] = 0;
                    for (k = 0; k < 200; k++)
                    {
                        cnt[k] += inside_cnt[opens[i][j]][k];
                    }
                    sg = 1;
                    break;
                }
        }
    }

    bool verdict = true;
    for (i = 0; i < 200; i++)
    {
        if (closed[i])
            verdict = false;
        cnt[i] = old_cnt[i];
        closed[i] = old_closed[i];
    }
    return verdict;
}

int old_cnt2[200], old_closed2[200];
void solve()
{
    int i, j, k;


    for (int u = 0; u < n; u++)
    {
        for (i = 0; i < 200; i++)
        {
            old_cnt2[i] = cnt[i];
            old_closed2[i] = closed[i];
        }
        for (i = 0; i < n; i++)
            if (closed[i] && cnt[opener[i]])
            {
                cnt[opener[i]]--;
                closed[i] = 0;
                for (k = 0; k < 200; k++)
                {
                    cnt[k] += inside_cnt[i][k];
                }
                if (can_be_solved())
                {
                    cout << " " << i+1;
                    break;
                }
                else
                {
                    for (k = 0; k < 200; k++)
                    {
                        cnt[k] = old_cnt2[k];
                        closed[k] = old_closed2[k];
                    }
                }
            }
        if (i == n) throw 9;
    }
}

int main()
{
    freopen("x.in", "r", stdin);
    freopen("x.txt", "w", stdout);

    int ti, tn;
    cin >> tn;
    gets(ss);

    for (ti = 1; ti <= tn; ti++)
    {
        cin >> k >> n;
        for (i = 0; i < 200; i++)
        {
            cnt[i] = 0;
            closed[i] = 0;
            for (j = 0; j < 200; j++)
                inside_cnt[i][j] = 0;
            opens[i].clear();
        }
        for (i = 0; i < k; i++)
        {
            cin >> j;
            cnt[j-1]++;
        }
        for (i = 0; i < n; i++)
        {
            closed[i] = 1;
            cin >> opener[i] >> inside_count[i];
            opener[i]--;
            opens[opener[i]].push_back(i);
            for (j = 0; j < inside_count[i]; j++)
            {
                cin >> k;
                inside_cnt[i][k-1]++;
            }
        }

        string ans = "IMPOSSIBLE";
        if (!can_be_solved())
        {
            cout << "Case #" << ti << ": " << ans << endl;
        }
        else
        {
            cout << "Case #" << ti << ":";
            solve();
            cout << endl;
        }
    }

    return 0;
}
