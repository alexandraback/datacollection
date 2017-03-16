#include "bits/stdc++.h"

using namespace std;

class Answer {
public:
    int j, p, s;
    Answer() {}
    Answer(int _j, int _p, int _s) : j(_j), p(_p), s(_s) {}
};

vector<Answer> ans;
int j, p, s, k;
vector<bool> cur;
int res;
vector<bool> result;

int JP[5][5];
int PS[5][5];
int JS[5][5];

void check(int cnt, int idx) {
    if (idx == (int)ans.size()) {
        if (cnt > res) {
            res = cnt;
            result = cur;
        }
        return;
    }
    auto t = ans[idx];
    if (JP[t.j][t.p] < k && PS[t.p][t.s] < k && JS[t.j][t.s] < k) {
        cur[idx] = 1;
        JP[t.j][t.p]++;
        PS[t.p][t.s]++;
        JS[t.j][t.s]++;
        check(cnt + 1, idx + 1);
        JP[t.j][t.p]--;
        PS[t.p][t.s]--;
        JS[t.j][t.s]--;
    }
    cur[idx] = 0;
    check(cnt, idx + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int c = 0; c < t; ++c) {
        cin >> j >> p >> s >> k;
        ans.clear();
        res = 0;
        for (int x = 0; x < j; ++x) {
            for (int y = 0; y < p; ++y) {
                for (int z = 0; z < s; ++z) {
                    ans.push_back(Answer(x, y, z));
                    JP[x][y] = 0;
                    PS[y][z] = 0;
                    JS[x][z] = 0;
                }
            }
        }
        cur.resize(ans.size());
        check(0, 0);
        cout << "Case #" << c + 1 << ": " << res << "\n";
        for (int i = 0; i < (int)result.size(); ++i) {
            if (result[i]) {
                cout << ans[i].j + 1 << " " << a    ns[i].p + 1 << " " << ans[i].s + 1 << "\n";
            }
        }
    }
    return 0;
}