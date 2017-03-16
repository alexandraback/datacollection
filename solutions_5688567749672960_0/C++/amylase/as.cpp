#include <bits/stdc++.h>
using namespace std;

typedef long long li;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int max_n = 1e6 + 1;
int revmap[max_n];
int cost[max_n];

void init () {
    rep(i, max_n) {
        stringstream ss, ss2;
        ss << i;
        string is;
        ss >> is;
        reverse(is.begin(), is.end());
        ss2 << is;
        ss2 >> revmap[i];
        cost[i] = i + 1;
    }
    queue<pair<int, int> > q;
    q.push(make_pair(1, 1));
    cost[1] = 1;
    while (not q.empty()) {
        int tcost = q.front().first;
        int tpos = q.front().second;
        q.pop();

        int nexts[2] = {tpos + 1, revmap[tpos]};
        rep(i, 2) {
            int npos = nexts[i];
            int ncost = tcost + 1;
            if (ncost < cost[npos]) {
                cost[npos] = ncost;
                q.push(make_pair(ncost, npos));
            }
        }
    }
}

struct problem {
    // input fields.
    int n, ans;

    // parse here.
    problem () {
        cin >> n;
    }

    // called exactly once. set ans here.
    void solve () {
        ans = cost[n];
    }
};

// generally you don't have to modify below.
int main () {
    init();
    int t;
    cin >> t;
    vector<problem> inputs;
    rep (i, t) {
        inputs.push_back(problem());
    }
    //#pragma omp parallel for
    rep (i, t) {
        inputs[i].solve();
    }
    rep (i, t) {
        cout << "Case #" << i + 1 << ": " << inputs[i].ans << endl;
    }
    return 0;
}
