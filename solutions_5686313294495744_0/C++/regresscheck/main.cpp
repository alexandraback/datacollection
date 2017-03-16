#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <vector>

using namespace std;



int n;
unordered_map<string, int> m1, m2;
vector<pair<string, string>> topics;
string s1, s2;

void solve() {
    m1.clear();
    m2.clear();
    topics.clear();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s1 >> s2;
        m1[s1] += 1;
        m2[s2] += 1;
        topics.push_back(make_pair(s1, s2));
    }
    while (true) {
        int mx = -1, mxp;
        for (int i = 0; i < topics.size(); ++i) {
            if (min(m1[topics[i].first], m2[topics[i].second]) > mx) {
                mx = min(m1[topics[i].first], m2[topics[i].second]);
                mxp = i;
            }
        }
        if (mx != -1) {
            m1[topics[mxp].first] -= 1;
            m2[topics[mxp].second] -= 1;
            topics.erase(topics.begin() + mxp);
        } else {
            break;
        }
    }
    cout << n - topics.size();
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "CASE #" << i << ": ";
        solve();
        cout << endl;
    }
}
