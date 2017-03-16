#include <iostream>
#include <cstring>

using namespace std;

#define N_MAX 100

int N, M;
int a[N_MAX][N_MAX];

int max_h[N_MAX], max_v[N_MAX];

const char* solve() {
    memset(max_h, 0, sizeof(max_h));
    memset(max_v, 0, sizeof(max_v));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] > max_h[i])
                max_h[i] = a[i][j];
            if (a[i][j] > max_v[j])
                max_v[j] = a[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] < max_h[i] && a[i][j] < max_v[j])
                return "NO";
        }
    }
    return "YES";
}

int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        cin >> N >> M;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> a[i][j];

        cout << "Case #" << testcase << ": " << solve() << endl;
    }

    return 0;
}
