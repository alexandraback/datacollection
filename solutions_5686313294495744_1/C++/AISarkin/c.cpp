#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>

using namespace std;

#define TASKNAME ""

void solve(int test_number);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(9);
    cerr.setf(ios::fixed);
    cerr.precision(3);
#ifdef LOCAL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve(i);
    }
}

const int MAX_N = 2005;
string topic[MAX_N][2], topics[MAX_N * 2];
pair<int, int> nums[MAX_N];
int flow[2 * MAX_N][2 * MAX_N], cap[2 * MAX_N][2 * MAX_N];
const int SRC = 2 * MAX_N - 1;
const int DST = SRC - 1;
bool vis[MAX_N * 2];

int dfs(int u) {
    if (u == DST) {
        return 1;
    }
    if (vis[u]) {
        return 0;
    }
    vis[u] = true;
    for (int j = 0; j < MAX_N * 2; j++) {
        if (!vis[j] && flow[u][j] < cap[u][j] && dfs(j)) {
            flow[u][j]++;
            flow[j][u]--;
            return 1;
        }
    }
    return 0;
}

void solve(int test_number) {
    int n;
    cin >> n;
    int sz = 0;
    for (int i = 0; i < n; i++) {
        cin >> topic[i][0] >> topic[i][1];
        topics[sz++] = topic[i][0];
        topics[sz++] = topic[i][1];
    }
    sort(topics, topics + sz);
    sz = unique(topics, topics + sz) - topics;
    vector<int> topics_l, topics_r;
    for (int i = 0; i < n; i++) {
        nums[i] = make_pair(lower_bound(topics, topics + sz, topic[i][0]) - topics,
                lower_bound(topics, topics + sz, topic[i][1]) - topics);
        topics_l.push_back(nums[i].first);
        topics_r.push_back(nums[i].second);
    }
    sort(topics_l.begin(), topics_l.end());
    topics_l.resize(unique(topics_l.begin(), topics_l.end()) - topics_l.begin());
    sort(topics_r.begin(), topics_r.end());
    topics_r.resize(unique(topics_r.begin(), topics_r.end()) - topics_r.begin());
    memset(flow, 0, sizeof(flow));
    memset(cap, 0, sizeof(cap));
    for (int i = 0; i < n; i++) {
        cap[nums[i].first][nums[i].second + MAX_N]++;
    }
    for (int i = 0; i < MAX_N - 4; i++) {
        cap[SRC][i] = 1;
        cap[i + MAX_N][DST] = 1;
    }
    int flow = 0;
    memset(vis, false, sizeof(vis));
    while (dfs(SRC)) {
        flow++;
        memset(vis, false, sizeof(vis));
    }
    cout << "Case #" << test_number + 1 << ": ";
    cout << n - (int)topics_l.size() - (int)topics_r.size() + flow << endl;
}
