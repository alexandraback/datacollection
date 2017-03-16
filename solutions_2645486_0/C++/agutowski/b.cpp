#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int T, maks, next[10000009];
long long E, R, N, v[10000009];
struct comp {
    bool operator() (const int &a, const int &b) const { return v[a]<v[b]; }
};
set<int, comp> s;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int k=1; k<=T; k++) {
        cin >> E >> R >> N;
        s.clear();
        for (int i=0; i<N; i++) {
            cin >> v[i];
            for (set<int>::iterator it=s.begin(); it!=s.end(); it++) {
                if (v[*it] > v[i]) break;
                next[*it] = i-*it;
                s.erase(it);
            }
            s.insert(i);
        }
        for (set<int>::iterator it=s.begin(); it!=s.end(); it++)
            next[*it] = E;
        int ACT = E;
        long long res = 0;
        for (int i=0; i<N; i++) {
            long long use = ACT - (E - next[i]*R);
            if (use < 0) use = 0;
            if (use >= ACT) {
                res += ACT*v[i];
                ACT = R;
            } else {
                res += use*v[i];
                ACT += R - use;
            }
        }
        cout << "Case #" << k << ": " << res << "\n";
    }
    return 0;
}
