#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Result {
    int j, p, s;
};

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int J, P, S, K;
        cin >> J >> P >> S >> K;
        map<pair<int, int>, int> jp, ps, js;
        vector<Result> res;
        for(int j = 1; j <= J; j++) {
            vector<pair<int, int> > perm;
            for(int p = 1; p <= P; p++) for(int s = 1; s <= S; s++) {
                perm.push_back(make_pair(p, s));
            }
            map<pair<int, int>, int> best_jp = jp, best_ps = ps, best_js = js;
            vector<Result> best_res = res;
            do {
                map<pair<int, int>, int> tjp = jp, tps = ps, tjs = js;
                vector<Result> tres = res;
                for(const pair<int, int> &e : perm) {
                    int p = e.first, s = e.second;
                    if(tjp[{j, p}] < K && tps[{p, s}] < K && tjs[{j, s}] < K) {
                        tjp[{j, p}]++, tps[{p, s}]++, tjs[{j, s}]++;
                        tres.push_back({j, p, s});
                    }
                }
                if(tres.size() > best_res.size()) {
                    best_res = tres;
                    best_jp = tjp, best_ps = tps, best_js = tjs;
                }
            } while(next_permutation(perm.begin(), perm.end()));
            res = best_res, jp = best_jp, ps = best_ps, js = best_js;
        }
        cout << "Case #" << t << ": " << res.size() << endl;
        for(const Result &r : res) cout << r.j << " " << r.p << " " << r.s << endl;
    }
    return 0;
}
