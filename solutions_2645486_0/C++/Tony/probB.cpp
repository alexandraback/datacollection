
#include <algorithm>
#include <iostream>
#define MAXN 11
#define MAXE 6

using namespace std;

int v[10000000];

int gain[MAXN][MAXE];

int solve() {
    int E, R, N;
    cin >> E >> R >> N;
    for (int i = 0; i < N; i++)
        cin >> v[i];

    for (int i = 0; i <= N; i++)
        for (int e = 0; e <= E; e++)
            gain[i][e] = 0;

    int gmax = 0;
    for (int i = 0; i < N; i++) {
        for (int e = 0; e <= E; e++) {
            for (int u = 0; u <= e; u++) {
                int enext = min(E, e - u + R);
                int gnext = gain[i][e] + u * v[i];
                gain[i + 1][enext] = max(gain[i + 1][enext], gnext);
                gmax = max(gmax, gain[i + 1][enext]);
            }
        }
    }
    return gmax;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
        cout << "Case #" << t << ": " << solve() << endl;
}
