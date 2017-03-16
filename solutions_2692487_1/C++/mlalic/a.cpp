#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map<pair<long long, int>, int> dp;
int solve(vector<int> const& motes, long long a, int pos, int ans) {
    if (dp.find(make_pair(a, pos)) != dp.end()) return dp[make_pair(a, pos)];
    int sz = motes.size();
    int i = pos;
    for (i = pos; i < sz; ++i) {
        if (motes[i] < a)
            a += motes[i];
        else
            break;
    }
    if (i == sz) return ans;
    int next = motes[i];
    int moves = 0;
    int eaten = 0;
    if (a > 1) {
        while (a <= next) {
            a += a - 1;
            ++moves;
        }
        if (moves > ans + sz - i) return dp[make_pair(a, pos)] = ans + sz - i;
        eaten = solve(motes, a, i, ans + moves);
    } else {
        eaten = 99999999;
    }
    if (eaten < ans + sz - i) return dp[make_pair(a, pos)] = eaten;
    else return dp[make_pair(a, pos)] = ans + sz - i;
}

int main() {
    int tn;
    cin >> tn;
    for (int tt = 1; tt <= tn; ++tt) {
        dp.clear();
        int a, n;
        cin >> a >> n;
        vector<int> motes(n);
        for (int i = 0; i < n; ++i) {
            cin >> motes[i];
        }
        sort(motes.begin(), motes.end());
        cout << "Case #" << tt << ": " << solve(motes, a, 0, 0) << endl;
    }
    return 0;
}

