#include <iostream>
#include <vector>
using namespace std;

#define MAXN 1024

struct clothes {
    int j, p, s;
};

int count(clothes c1, clothes c2) {
    int ret = 0;
    if (c1.j == c2.j) ret++;
    if (c1.p == c2.p) ret++;
    if (c1.s == c2.s) ret++;
    return ret;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";

        int j, p, s, k;
        cin >> j >> p >> s >> k;

        int n = j * p * s;
        vector<clothes> v;
        for (int i1 = 0; i1 < j; i1++) {
            for (int i2 = 0; i2 < p; ++i2) {
                for (int i3 = 0; i3 < s; ++i3) {
                    clothes c;
                    c.j = i1;
                    c.p = i2;
                    c.s = i3;
                    v.push_back(c);
                }
            }
        }

        vector<vector<int> > neighbor(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    if (count(v[i], v[j]) > 1) {
                         neighbor[i].push_back(j);
                    }
                }
            }
        }

        vector<int> degree(n);
        for (int i = 0; i < n; ++i) {
            degree[i] = neighbor[i].size();
        }
        /*
        for (int i = 0; i < n; ++i) {
            cout << "degree" << i << " " << degree[i] << endl;
        }
        */

        vector<bool> flag(n, true);

        while (true) {
            int index = -1;
            for (int i = 0; i < n; ++i) {
                if (flag[i] == true) {
                     if (index < 0) index = i;
                     else if (degree[i] > degree[index]) index = i;
                }
            }

            if (degree[index] < k) break;

            for (int i = 0; i < neighbor[index].size(); ++i) {
                 degree[neighbor[index][i]]--;
            }

            flag[index] = false;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
             if (flag[i]) ans++;
        }

        cout << ans << endl;
        for (int i = 0; i < n; ++i) {
            if (flag[i]) {
                cout << v[i].j + 1<< " " << v[i].p  + 1<< " " << v[i].s  + 1<< endl;
            }
        }
    }

    return 0;
}
