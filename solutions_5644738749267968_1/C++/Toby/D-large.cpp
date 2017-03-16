#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int N;
double A[1000], B[1000];

int f(double *X, double *Y) {
    int pos = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        while (pos < N && Y[pos] < X[i])
            pos++;
        if (pos >= N)
            break;
        ans++;
        pos++;
    }
    return ans;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];

    sort(A, A+N);
    sort(B, B+N);

    cout << f(B, A);
   
    for (int i = 0; i < N; i++) {
        A[i] = -A[i];
        B[i] = -B[i];
    }
    sort(A, A+N);
    sort(B, B+N);

    cout << ' ' << N - f(B, A) << endl;
}

int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        cout << "Case #" << testcase << ": ";
        solve();
    }

    return 0;
}
