#include <bits/stdc++.h>
using namespace std;

struct node {
    int j, p, s;
    node(){};
    node(int _j, int _p, int _s) {
        j = _j;
        p = _p;
        s = _s;
    }
};

map <pair<int, pair <int, int> >, bool> used;
map <pair<int, int>, int> JS, JP, PS;

pair <int, pair <int, int> > get (node x) {
    return make_pair(x.j, make_pair(x.p, x.s));
}

int main() {

    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    int t; cin >> t;

    for (int i = 1; i <= t; i++) {
        used.clear();
        JS.clear();
        JP.clear();
        PS.clear();
        cout << "Case #" << i << ": ";
        int j, p, s, k; cin >> j >> p >> s >> k;

        vector <node> allOut;
        for (int i1 = 1; i1 <= j; i1++) {
            for (int i2 = 1; i2 <= p; i2++) {
                for (int i3 = 1; i3 <= s; i3++) {
                    allOut.push_back(node(i1, i2, i3));
                    used[get(node(i1, i2, i3))] = false;
                    JP[make_pair(i1, i2)] = 0;
                    JS[make_pair(i1, i3)] = 0;
                    PS[make_pair(i2, i3)] = 0;
                }
            }
        }

        vector <node> result;
        for (int i = 0; i < allOut.size(); i++) {
            int J = allOut[i].j, P = allOut[i].p, S = allOut[i].s;
            if (used[get(allOut[i])] == true) continue;
            if (JP[make_pair(J, P)] < k && JS[make_pair(J, S)] < k && PS[make_pair(P, S)] < k) {
                used[get(allOut[i])] = true;
                JP[make_pair(J, P)]++;
                JS[make_pair(J, S)]++;
                PS[make_pair(P, S)]++;
                result.push_back(allOut[i]);
            }
        }

        cout << result.size() << "\n";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i].j << " " << result[i].p << " " << result[i].s << "\n";
        }
    }

    return 0;
}
