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
        return ((360. - start) / 360. + times) * period;
    }

    li encounter(double gt) {
        if (gt < goaltime(0)) return 1;
        gt -= goaltime(0);
        return (li)(gt / period);
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
        vector<double> goaltimes;
        rep(i, hikers.size()) {
            goaltimes.push_back(hikers[i].goaltime(0));
        }
        goaltimes.push_back(0);
        vector<li> ans_cand;
        rep(i, goaltimes.size()) {
            double gt = goaltimes[i] + 1e-5;
            li tans = 0;
            rep(j, hikers.size()) {
                tans += hikers[j].encounter(gt);
            }
            ans_cand.push_back(tans);
        }
        ans = *min_element(ans_cand.begin(), ans_cand.end());
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
