#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
int p[2000];
int curc = 0;
int curs = 0;
bool u[2000];
bool inc[2000];
bool ex[2000];
vector<int> co[2000];
int solve(int x, int d, int start) {
    if (ex[x]) return 0;
    u[x] = true;
    if (inc[x]) return 0 ;
    if (u[p[x]]) {
        if (p[x] == start) { 
            curc = max(curc, d);
            inc[x] = true;
        }
        return 0;
    }
    if (ex[p[x]] && (p[p[x]] != x)) {
        co[p[x]].push_back(d);
    } else 
        solve(p[x], d + 1, start);
}

int solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
        ex[i] = false;
        co[i].clear();
    }
    curc = 0;
    curs = 0;
    for (int i = 0; i < n; ++i) {
        if (i == p[p[i]])
            ex[i] = true;
    }
    for (int i = 0; i < n; ++i)
        inc[i] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            u[j] = false;
        solve(i, 1, i);
    }
    for (int i = 0; i < n; ++i) {
        sort(co[i].begin(), co[i].end());
        reverse(co[i].begin(), co[i].end());
    }
    int gs = 0;
    for (int i = 0; i < n; ++i) {
        if (ex[i]) {
            curs = 0;
            if (p[i] < i) continue;
            curs = max(curs, 2);

            if (co[i].size() > 0) {
                curs = max(curs, 2 + co[i][0]);
            } 
            if (co[p[i]].size() > 0) {
                curs = max(curs, 2 + co[p[i]][0]);
            }
            if ((co[i].size() > 0) && (co[p[i]].size() > 0)) {
                
                curs =  max(curs, 2 + co[i][0] + co[p[i]][0]);
            }
            gs += curs;
        }
    }
    cout << max(curc, gs) << endl;
}

int main(void) {
    int T;
    cin >> T;
   
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: ", t);
        solve();
    }
}
