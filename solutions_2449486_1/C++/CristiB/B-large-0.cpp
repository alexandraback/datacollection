#include <iostream>
#include <set>
#include <utility>
#include <algorithm>
#include <utility>

#define log cerr

using namespace std;

const int MAX_N = 200;

int N, M, A[MAX_N][MAX_N];


void read_test() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> A[i][j];
}

bool solve() {
    int line[MAX_N], col[MAX_N];

    for (int i = 0; i < N; ++i) {
        int maxim = -1;
        for (int j = 0; j < M; ++j)
            if (A[i][j] > maxim) 
                maxim = A[i][j];
        line[i] = maxim;
    }

    for (int j = 0; j < M; ++j) {
        int maxim = -1;
        for (int i = 0; i < N; ++i)
            if (A[i][j] > maxim) 
                maxim = A[i][j];
        col[j] = maxim;
    }

    // check
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
           int minim = min(line[i], col[j]);
           if (minim != A[i][j])
              return false; 
        }

    return true;
}

std::string getMsg(bool res) {
    if (res) return "YES";
    else return "NO";
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        read_test();
        bool res = solve();
        cout << "Case #" << t << ": " << getMsg(res)  << endl;
    }
    
    return 0;
}

