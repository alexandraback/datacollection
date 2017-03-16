
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#define MAXN 11
#define MAXE 6

using namespace std;

int R, N, M, K;
int p[8000];

int solve() {
    for (int i = 0; i < K; i++)
        cin >> p[i];

    // N == 3

    double bestProb = -1;
    vector <vector <int> > all;
    for (int i = 2; i <= M; i++)
        for (int j = 2; j <= M; j++)
            for (int k = 2; k <= M; k++) {
                vector <int> q(8);
                q[0] = 1;
                q[1] = i, q[2] = j, q[3] = k;
                q[4] = i * j, q[5] = j * k, q[6] = k * i;
                q[7] = i * j * k;

                double prob = 1;
                for (int l = 0; l < K; l++) {
                    int cnt = 0;
                    for (int mask = 0; mask < 8; mask++)
                        if (q[mask] == p[l])
                            cnt++;
                    prob *= 1.0 * cnt / 8.0;
                }
                if (prob > bestProb)
                    bestProb = prob, all.clear();
                if (prob == bestProb) {
                    vector <int> a(3);
                    a[0] = i, a[1] = j, a[2] = k;
                    all.push_back(a);
                }
            }
    cerr << bestProb << endl;

    vector <int> a = all[rand() % all.size()];
    for (int i = 0; i < 3; i++)
        cout << a[i];
    cout << endl;
}

void solve_all() {
    cin >> R >> N >> M >> K;
    for (int i = 0; i < R; i++) {
        solve();
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ":" << endl;
        solve_all();
    }
}
