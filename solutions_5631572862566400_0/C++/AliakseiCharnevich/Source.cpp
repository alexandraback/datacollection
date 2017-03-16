#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

bool is_doubles(vector<int> const& f, int cur)
{
    return f[f[cur]] == cur;
}

int find_max_cycle(vector<int> const& f)
{
    deque<int> is_sused(f.size(), 0);
    int start = 0;
    int max_cycle = 0;
    for (int i = 0; i < f.size(); ++i)
    {
        if (is_sused[i])
        {
            continue;
        }
        start += 10;
        int cur_start = start;
        int cur = i;
        while(!is_sused[cur])
        {
            is_sused[cur] = start++;
            cur = f[cur];
        }
        if (is_sused[cur] < cur_start)
        {
            continue;
        }
        max_cycle=max(max_cycle, start - is_sused[cur]);
    }
    return max_cycle;
}

pair<int, int> find_cnt(vector<pair<int, int> >& last_count, vector<int> const& f, int cur, vector<char> &is_used)
{
    if (is_doubles(f,cur))
    {
        return pair<int, int>(cur, 0);
    }

    if (is_used[cur])
    {
        return last_count[cur];
    }
    is_used[cur] = true;
    pair<int, int> p = find_cnt(last_count, f, f[cur], is_used);
    if (p != last_count[cur])
    {
        last_count[cur].second = p.second + 1;
        last_count[cur].first = p.first;
    }
    return last_count[cur];
}

void calc_row()
{
    int n;
    cin >> n;
    vector<int> f;
    for (int i = 0; i < n; ++i)
    {
        int bff;
        cin >> bff;
        f.push_back(bff-1);
    }

    int max_cycle = find_max_cycle(f);

    vector<pair<int, int> > doubles;
    vector<pair<int, int> > last_count(f.size(), pair<int, int>(-1, -1));
    vector<char> is_used(f.size(), 0);
    for (int i = 0; i < f.size(); ++i)
    {
        if (is_doubles(f, i))
        {
            doubles.push_back(make_pair(i, f[i]));
        }
        else
        {
            find_cnt(last_count, f, i, is_used);
        }
    }
    map<int, int> mp;
    for (int i = 0; i < last_count.size(); ++i)
    {
        if (last_count[i].first != -1)
        {
            mp[last_count[i].first] = max(last_count[i].second, mp[last_count[i].first]);
        }
    }

    int doubles_cycle = doubles.size();
    for (int i = 0; i < doubles.size(); ++i)
    {
        doubles_cycle += mp[doubles[i].first];
    }
    cout << max(doubles_cycle, max_cycle);
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cout << "Case #" << + i + 1 << ": ";
        calc_row();
        cout << "\n";
    }
    return 0;
}