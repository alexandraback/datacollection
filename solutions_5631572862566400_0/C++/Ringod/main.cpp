#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector <int> to(n);
    map < pair <int, int> , vector < pair<int, int> > > sa;
    map <pair <int, int>, int> en;
    for (int i = 0; i < n; ++i) {
        cin >> to[i]; to[i] --;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int c = i, cnt = 1, ppp = i, pp = i, p = i;
        vector < int > u(n, 0);
        while (u[c] == 0) {
            u[c] = cnt;
            ppp = pp;
            pp = p;
            p = c;
            c = to[c];
            ++cnt;
        }
        if (pp == c) {
            if (p > pp) {
                swap(p, pp);
            }
            if (ppp != pp) {
                sa[make_pair(p, pp)].push_back(make_pair(cnt - 1, ppp));
            }
            en[make_pair(p, pp)] = max(en[make_pair(p, pp)], cnt - 1);
        }
        res = max(res, cnt - u[c]);
    }
    for (pair < pair<int, int>, vector < pair <int, int> > > x : sa) {
        int tc = x.second.size();
        for (int i = 0; i < tc; ++i) {
            for (int j = 0; j < tc; ++j) {
                if (i == j) {
                    continue;
                }
                if (x.second[i].second != x.second[j].second && to[x.second[j].first] != to[x.second[i].first]) {
                    res = max(res, x.second[i].first + x.second[j].first - 2);
                }
            }
        }
    }
    vector <int> keys(n, 0);
    for (pair <pair <int, int>, int> x : en) {
        keys.push_back(x.second);
    }
    sort(keys.begin(), keys.end());
    if (keys.size() > 0) {
        res = max(res, keys[keys.size() - 1]);
    }
    if (keys.size() > 1) {
        vector < pair <int, pair <int, int> > > t;
        for (pair <pair <int, int>, int> x : en) {
            t.push_back(make_pair(x.second, x.first));
        }
        sort(t.begin(), t.end());
        for (int i = 0; i < t.size(); ++i) {
            for (int j = 0; j < t.size(); ++j) {
                if (i == j) {
                    continue;
                }
                res = max(res, t[j].first + t[i].first - 1);

            }
        }
    }
    cout << res << endl;
}


int main() {
#ifdef ALEXEY
    freopen("/home/alexey/Projects/ClionAcm/input", "r", stdin);
    freopen("/home/alexey/Projects/ClionAcm/output", "w", stdout);
#else
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(std::ios_base::fixed);
    cout.precision(28);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
#ifdef ALEXEY
    fprintf(stderr, "Time: %.18lf\n", (double)clock() / CLOCKS_PER_SEC);
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}