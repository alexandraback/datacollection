#include <bits/stdc++.h>
 
using namespace std;
 
int J, P, S, K;
 
struct state {
    int ret;
    bitset<10> used[10][10];
 
    char combJP[10][10];
    char combJS[10][10];
    char combPS[10][10];
 
    bool check(int j, int p, int s) {
        if (max(max(combJP[j][p], combJS[j][s]), combPS[p][s]) < K) {
            return !used[j][p][s];
        }
        return false;
    }
 
    void use(int j, int p, int s) {
        ret++;
        used[j][p].set(s, true);
        combJP[j][p]++;
        combJS[j][s]++;
        combPS[p][s]++;
    }
};
 
state solve(int j, int p, int s, state st) {
    if (j >= J) {
        j = 0;
        p++;
    }
 
    if (p >= P) {
        p = 0;
        s++;
    }
 
    if (s >= S) return st;
 
    if (st.check(j, p, s)) {
        state s1 = solve(j + 1, p, s, st);
        st.use(j, p, s);
        state s2 = solve(j + 1, p, s, st);
        return s1.ret > s2.ret ? s1 : s2;
    }
 
    return solve(j + 1, p, s, st);
}
 
int main() {
    int t;
    cin >> t;
 
    int cur = 0;
    while (t--) {
        cur++;
 
        state st;
        st.ret = 0;
 
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                st.combJP[i][j] = 0;
                st.combJS[i][j] = 0;
                st.combPS[i][j] = 0;
            }
        }
 
        cin >> J >> P >> S >> K;
 
        state ret = solve(0, 0, 0, st);
 
        printf("Case #%d: %d\n", cur, ret.ret);
 
        for (int j = 0; j < J; j++) {
            for (int p = 0; p < P; p++) {
                for (int s = 0; s < S; s++) {
                    if (ret.used[j][p][s]) {
                        printf("%d %d %d\n", j + 1, p + 1, s + 1);
                    }
                }
            }
        }
    }
 
    return 0;
}
