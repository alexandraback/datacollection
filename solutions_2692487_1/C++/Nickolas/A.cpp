#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve(int ind) {
    // input
    int A, N;
    cin >> A >> N;
    vector<int> m(N);
    for (int i = 0; i < N; ++i) {
        cin >> m[i];
    }
    // process
    // special case = A = 1 can't eat
    if (A == 1) {
        cout << "Case #" << ind << ": " << N << endl;
        return;
    }
    int curop = 0, minop = N;
    sort(m.begin(), m.end());
    int eaten = 0;
    // or eat all you can
    while (m[eaten] < A && eaten < N) {
        A += m[eaten];
        ++eaten;
    }
    while (eaten < N) {
        // you can discard all motes that are left
        minop = min<int>(minop, curop + N - eaten);
        // or add the largest mote you can eat (1 is enough)
        ++curop;
        A += A - 1;
        // and eat all you can again
        while (m[eaten] < A && eaten < N) {
            A += m[eaten];
            ++eaten;
        }
    }
    minop = min<int>(minop, curop);
    // output
    cout << "Case #" << ind << ": " << minop << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        solve(i);
    }
}