#include <bits/stdc++.h>
using namespace std;

typedef long long li;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

struct hiker {
    li start, period;
    hiker(li s, li p) {
        start = s;
        period = p;
    }

    double goaltime(li times) {
        return ((360. - start) / 360. + times - 1) * period;
    }
};

struct problem {
    // input fields.
    li n;
    vector<li> ds, hs, ms;
    li ans;

    // parse here.
    problem () {
        cin >> n;
        ds = vector<li>(n);
        hs = vector<li>(n);
        ms = vector<li>(n);
        rep(i, n) {
            cin >> ds[i] >> hs[i] >> ms[i];
        }
    }

    // called exactly once. set ans here.
    void solve () {
        vector<hiker> hikers;
        rep(i, n) {
            rep(j, hs[i]) {
                hikers.push_back(hiker(ds[i], ms[i] + j));
            }
        }
        if (hikers.size() < 2) {
            ans = 0;
            return;
        }
        double timelimit = min(hikers[0].goaltime(2), hikers[1].goaltime(2));
        double cangoal = max(hikers[0].goaltime(1), hikers[1].goaltime(1));
        ans = (cangoal < timelimit) ? 0 : 1;
    }
};

// generally you don't have to modify below.
int main () {
    int t;
    cin >> t;
    vector<problem> inputs;
    rep (i, t) {
        inputs.push_back(problem());
    }
    #pragma omp parallel for
    rep (i, t) {
        inputs[i].solve();
    }
    rep (i, t) {
        cout << "Case #" << i + 1 << ": " << inputs[i].ans << endl;
    }
    return 0;
}
