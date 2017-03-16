
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#define INF 1e20

using namespace std;

typedef pair <int, int> fraction;

int N;
char C[50];
int S[50];
int P[50];

struct collision {
    bool start;
    double t;
    int i;
    int j;
    double pos;
};

vector <collision> all;

bool cmp(const collision &c1, const collision &c2) {
    if (fabs(c1.t - c2.t) < 1e-9)
        return c1.pos < c2.pos;
    return c1.t < c2.t;
}

char side[50];
double pos[50];
bool canMove[50][50];
int numBlocking[50];

void init() {
    for (int i = 0; i < N; i++) {
        side[i] = C[i];
        pos[i] = P[i];
        numBlocking[i] = 0;
    }
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            canMove[i][j] = canMove[j][i] = (abs(P[j] - P[i]) >= 5);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (j != i && !canMove[i][j])
                numBlocking[i]++;
}

double solve() {
    all.clear();
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++) {
            if (S[i] == S[j])
                continue;

            double t0 = 1.0 * (P[j] - P[i] - 5) / (S[i] - S[j]);
            double t1 = 1.0 * (P[j] - P[i] + 5) / (S[i] - S[j]);
            if (t0 > t1)
                swap(t0, t1);

            if (t0 > 0) {
                collision col;
                col.start = true;
                col.t = t0;
                col.i = i;
                col.j = j;
                col.pos = min(P[i] + t0 * S[i], P[j] + t0 * S[j]);
                all.push_back(col);
            }

            if (t1 > 0) {
                collision col;
                col.start = false;
                col.t = t1;
                col.i = i;
                col.j = j;
                col.pos = min(P[i] + t1 * S[i], P[j] + t1 * S[j]);
                all.push_back(col);
            }
        }
    sort(all.begin(), all.end(), cmp);

    //printf("all size: %d\n", all.size());

    int M = 0;
    for (int i = 0; i < all.size(); i++)
        if (all[i].start)
            M++;

    //printf("red size: %d\n", M);

    double best = 0;
    for (int mm = 0; mm < (1 << M); mm++) {
        init();

        int mask = 0;
        int at = 0;
        for (int k = 0; k < all.size(); k++)
            if (all[k].start) {
                if (mm & (1 << at))
                    mask |= (1 << k);
                at++;
            }

        double t = INF;
        for (int k = 0; k < all.size(); k++) {
            int i = all[k].i;
            int j = all[k].j;
            if (all[k].start) {
                char side0 = 'L';
                char side1 = 'R';
                if (mask & (1 << k))
                    swap(side0, side1);
                if (side[i] != side0) {
                    if (numBlocking[i] > 0) {
                        t = all[k].t;
                        break;
                    }
                    side[i] = side0;
                }
                if (side[j] != side1) {
                    if (numBlocking[j] > 0) {
                        t = all[k].t;
                        break;
                    }
                    side[j] = side1;
                }
                canMove[i][j] = canMove[j][i] = false;
                numBlocking[i]++, numBlocking[j]++;
            }
            else {
                canMove[i][j] = canMove[j][i] = true;
                numBlocking[i]--, numBlocking[j]--;
            }

        }
        best = max(best, t);
    }
    return best;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        for (int j = 0; j < N; j++) {
            string side;
            cin >> side >> S[j] >> P[j];
            C[j] = side[0];
        }
        printf("Case #%d: ", i + 1);
        double ans = solve();
        if (ans > INF / 2)
            printf("Possible\n");
        else
            printf("%.10lf\n", solve());
    }
}
