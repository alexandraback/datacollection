#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

void solve(int testNumber) {
    cout << "Case #" << testNumber << ":\n";

    int N, M, K;
    cin >> N >> M >> K;

    vector<string> A(N, string(M, '.'));
    if (K == N * M - 1) {
        for (string& p: A)
            fill(p.begin(), p.end(), '*');
        A[N - 1][M - 1] = 'c';
    } else {
    }
    
    for (const string& p: A)
        cout << p << '\n';
}

int main() {
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int test = 1; test <= T; ++test) {
        solve(test);
        //cerr << "Done #" << test << '\n';
    }
}
