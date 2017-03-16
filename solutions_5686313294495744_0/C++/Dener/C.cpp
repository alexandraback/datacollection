#include <bits/stdc++.h>

using namespace std;

void solve(int testnum)
{
    vector<pair<string, string>> s;
    int n;
    cin >> n;
    s.resize(n);
    for (int i = 0 ;i  < n; i++) {
        cin >> s[i].first >> s[i].second;
    }

    int best_answer = n;
    for (int mask = 0; mask < (1<<n); mask++) {
        set<string> have_first;
        set<string> have_second;
        int good_count = 0;
        for (int i = 0 ; i < n; i++) {
            if ((mask >> i) & 1) {
                have_first.insert(s[i].first);
                have_second.insert(s[i].second);
                good_count++;
            }
        }

        if (good_count >= best_answer) {
            continue;
        }

        bool ok = true;
        for (int i = 0; i < n and ok; i++) {
            if (not ((mask >> i) & 1)) {
                if (not have_first.count(s[i].first)) {
                    ok = false;
                }
                if (not have_second.count(s[i].second)) {
                    ok = false;
                }
            }
        }
        if (ok) {
            best_answer = good_count;
        }
    }
    cout << "Case #" << testnum + 1 << ": " << n - best_answer << endl;
}

int main()
{
    int T;
    ios_base::sync_with_stdio(false);
    cin >> T;
    for (int testnum = 0; testnum < T; testnum++) {
        solve(testnum);
    }
}
