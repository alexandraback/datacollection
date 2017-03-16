#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;

//by Skyly

typedef long long int64;

#define SIZE(X) ((int)((X).size())) 
#define FOR(IT, X) for (__typeof((X).begin()) IT = (X).begin(); IT != (X).end(); ++IT)

template<typename T> string toStr(const T &x) { ostringstream os; os << x; return os.str(); }
template<typename T> void toMin(T &x, const T &y) { x = min(x, y); }
template<typename T> void toMax(T &x, const T &y) { x = max(x, y); }

const int MAXN = 10;
const double INF = 1e+100;

int N;
int s[MAXN], p[MAXN];
int lane[MAXN];

map<pair< vector<int>, vector<int> >, double> dp;

double currPos(int id, int t) {
    return p[id] + s[id] * t;
}
double speed(int id) {
    return s[id];
}
vector<int> insertCar(const vector<int> &org, int id, int pos) {
    vector<int> res;
    for (int i = 0; i < pos; ++i) {
        res.push_back(org[i]);
    }
    res.push_back(id);
    for (int i = pos; i < SIZE(org); ++i) {
        res.push_back(org[i]);
    }
    return res;
}
vector<int> eraseCar(const vector<int> &org, int pos) {
    vector<int> res;
    for (int i = 0; i < pos; ++i) {
        res.push_back(org[i]);
    }
    for (int i = pos + 1; i < SIZE(org); ++i) {
        res.push_back(org[i]);
    }
    return res;
}

double colliTime(const vector<int> &L, const vector<int> &R, const int t) {
    vector<int> lst[2];
            lst[0] = L;
            lst[1] = R;
            double minT = INF;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < SIZE(lst[i]) - 1; j++) {
                    if (s[lst[i][j]] > s[lst[i][j + 1]]) {
                        toMin(minT, (currPos(lst[i][j + 1], t) - (currPos(lst[i][j], t) + 5)) / (speed(lst[i][j]) - speed(lst[i][j + 1])));
                    }
                }
            }
        return minT;
}

void solve(vector<int> L, vector<int> R, double t) {
    if (R < L) swap(L, R);
    if (dp.find(make_pair(L, R)) != dp.end()) {
        if (dp.find(make_pair(L, R))->second < t + 1e-7) return;
        else dp[make_pair(L, R)] = t;
    } else {
        dp.insert(make_pair(make_pair(L, R), t));
    }
    //try L
    for (int i = 0; i < SIZE(L); ++i) {
        for (int j = 0; j <= SIZE(R); ++j) {
            double tL = 0.0;
            double tR = colliTime(L, R, t);
            if (i + 1 < SIZE(L)) {
                if (s[L[i + 1]] < s[L[i]]) toMin(tR, (currPos(L[i + 1], t) - (currPos(L[i], t) + 5)) / (speed(L[i]) - speed(L[i + 1])));
            }
            if (i > 0) {
                if (s[L[i - 1]] > s[L[i]]) toMin(tR, (currPos(L[i], t) - (currPos(L[i - 1], t) + 5)) / (speed(L[i - 1]) - speed(L[i])));
            }
            if (j > 0) {
                if (s[L[i]] == s[R[j - 1]]) {
                    if (currPos(L[i], t) < currPos(R[j - 1], t) + 5) tL = INF + 1.0;
                } else if (s[L[i]] > s[R[j - 1]]) {
                    if (currPos(L[i], t) < currPos(R[j - 1], t) + 5) {
                        toMax(tL, (currPos(R[j - 1], t) + 5 - currPos(L[i], t)) / (speed(L[i]) - speed(R[j - 1])));
                    }
                } else {
                    if (currPos(L[i], t) < currPos(R[j - 1], t) + 5) tL = INF + 1.0;
                    else {
                        toMin(tR, (currPos(L[i], t) - (currPos(R[j - 1], t) + 5)) / (speed(R[j - 1]) - speed(L[i])));
                    }
                }
            }
            if (j < SIZE(R)) {
                if (s[L[i]] == s[R[j]]) {
                    if (currPos(R[j], t) < currPos(L[i], t) + 5) tL = INF + 1.0;
                } else if (s[L[i]] < s[R[j]]) {
                    if (currPos(R[j], t) < currPos(L[i], t) + 5) {
                        toMax(tL, (currPos(L[i], t) + 5 - currPos(R[j], t)) / (speed(R[j]) - speed(L[i])));
                    }
                } else {
                    if (currPos(R[j], t) < currPos(L[i], t) + 5) tL = INF + 1.0;
                    else {
                        toMin(tR, (currPos(R[j], t) - (currPos(L[i], t) + 5)) / (speed(L[i]) - speed(R[j])));
                    }
                }
            }
            if (tL < tR + 1e-7) {
                solve(eraseCar(L, i), insertCar(R, L[i], j), t + tL);
            }
        }
    }

    //try R
    for (int i = 0; i < SIZE(R); ++i) {
        for (int j = 0; j <= SIZE(L); ++j) {
            double tR = 0.0;
            double tL = colliTime(L, R, t);
            if (i + 1 < SIZE(R)) {
                if (s[R[i + 1]] < s[R[i]]) toMin(tL, (currPos(R[i + 1], t) - (currPos(R[i], t) + 5)) / (speed(R[i]) - speed(R[i + 1])));
            }
            if (i > 0) {
                if (s[R[i - 1]] > s[R[i]]) toMin(tL, (currPos(R[i], t) - (currPos(R[i - 1], t) + 5)) / (speed(R[i - 1]) - speed(R[i])));
            }
            if (j > 0) {
                if (s[R[i]] == s[L[j - 1]]) {
                    if (currPos(R[i], t) < currPos(L[j - 1], t) + 5) tR = INF + 1.0;
                } else if (s[R[i]] > s[L[j - 1]]) {
                    if (currPos(R[i], t) < currPos(L[j - 1], t) + 5) {
                        toMax(tR, (currPos(L[j - 1], t) + 5 - currPos(R[i], t)) / (speed(R[i]) - speed(L[j - 1])));
                    }
                } else {
                    if (currPos(R[i], t) < currPos(L[j - 1], t) + 5) tR = INF + 1.0;
                    else {
                        toMin(tL, (currPos(R[i], t) - (currPos(L[j - 1], t) + 5)) / (speed(L[j - 1]) - speed(R[i])));
                    }
                }
            }
            if (j < SIZE(L)) {
                if (s[R[i]] == s[L[j]]) {
                    if (currPos(L[j], t) < currPos(R[i], t) + 5) tR = INF + 1.0;
                } else if (s[R[i]] < s[L[j]]) {
                    if (currPos(L[j], t) < currPos(R[i], t) + 5) {
                        toMax(tR, (currPos(R[i], t) + 5 - currPos(L[j], t)) / (speed(L[j]) - speed(R[i])));
                    }
                } else {
                    if (currPos(L[j], t) < currPos(R[i], t) + 5) tR = INF + 1.0;
                    else {
                        toMin(tL, (currPos(L[j], t) - (currPos(R[i], t) + 5)) / (speed(R[i]) - speed(L[j])));
                    }
                }
            }
            if (tR < tL + 1e-7) {
                solve(eraseCar(R, i), insertCar(L, R[i], j), t + tR);
            }
        }
    }

}

int main() {
    int t;
    char buf[10];

    scanf("%d", &t);
    for (int casN = 1; casN <= t; ++casN) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%s%d%d", buf, &s[i], &p[i]);
            lane[i] = (buf[0] == 'L') ? 0 : 1;
        }
        set< pair<int, int> > ord[2];
        for (int i = 0; i < N; ++i) {
            ord[lane[i]].insert(make_pair(p[i], i));
        }
        vector<int> lst[2];
        for (int i = 0; i < 2; ++i) {
            FOR (it, ord[i]) {
                lst[i].push_back(it->second);
            }
        }
        dp.clear();
        solve(lst[0], lst[1], 0.0);

        double ans = 0.0;
        FOR (it, dp) {
            lst[0] = (it->first).first;
            lst[1] = (it->first).second;
            double minT = INF;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < SIZE(lst[i]) - 1; j++) {
                    if (s[lst[i][j]] > s[lst[i][j + 1]]) {
                        toMin(minT, (currPos(lst[i][j + 1], it->second) - (currPos(lst[i][j], it->second) + 5)) / (speed(lst[i][j]) - speed(lst[i][j + 1])));
                    }
                }
            }
            toMax(ans, (it->second) + minT);
        }
        printf("Case #%d: ", casN);
        if (ans > 1e+90) puts("Possible");
        else printf("%.9f\n", ans);
    }

    return 0;
}

