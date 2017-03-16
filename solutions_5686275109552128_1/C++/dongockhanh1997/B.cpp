#include <bits/stdc++.h>
using namespace std;

const int INF = (int) 1e9;
const int N = 1000;
int a[N];

int runTest() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int result = INF;
    for (int eat = 1; eat <= N; ++eat) {
        int foo = eat;
        for (int i = 0; i < n; ++i) foo += (a[i] - 1) / eat;
        result = min(result, foo);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    int numTests; cin >> numTests;
    for (int test = 0; test < numTests; ++test) {
        cout << "Case #" << test + 1 << ": " << runTest() << '\n';
    }
    return 0;
}
