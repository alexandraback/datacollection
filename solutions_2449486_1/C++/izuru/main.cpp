#include <iostream>
#include <set>

using namespace std;

#define MN 100
#define MM 100

int A[MN][MM];

int N, M;

#define INF (1<<8)
bool check() {
    //cout << endl;
    //for (int i = 0; i < N; i++) {
    //    for (int j = 0; j < M; j++) {
    //        cout << A[i][j] << ' ';
    //    }
    //    cout << endl;
    //}
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (A[i][j] != INF) return false;
    return true;
}

bool solve() {
    set<int> hs;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            hs.insert(A[i][j]);
        }
    }
    for (set<int>::iterator it = hs.begin(); it != hs.end(); it++) {
        int h = *it;
        for (int i = 0; i < N; i++) {
            bool all_eq = true;
            for (int j = 0; j < M; j++) {
                if (A[i][j] != h && A[i][j] != INF) {
                    all_eq = false;
                    break;
                }
            }
            if (all_eq) {
                for (int j = 0; j < M; j++) {
                    A[i][j] = INF;
                }
            }
        }
        for (int j = 0; j < M; j++) {
            bool all_eq = true;
            for (int i = 0; i < N; i++) {
                if (A[i][j] != h && A[i][j] != INF) {
                    all_eq = false;
                    break;
                }
            }
            if (all_eq) {
                for (int i = 0; i < N; i++) {
                    A[i][j] = INF;
                }
            }
        }
    }
    return check();
}

int T;
int main() {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        set<int> h;
        cin >> N >> M;
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        cout << "Case #" << tc << ": " << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}
