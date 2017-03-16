#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

typedef long long i64;

const int nextOp[][8] = {{0, 1, 2, 3, 4, 5, 6, 7},
                         {1, 4, 3, 6, 5, 0, 7, 2},
                         {2, 7, 4, 1, 6, 3, 0, 5},
                         {3, 2, 5, 4, 7, 6, 1, 0},
                         {4, 5, 6, 7, 0, 1, 2, 3},
                         {5, 0, 7, 2, 1, 4, 3, 6},
                         {6, 3, 0, 5, 2, 7, 4, 1},
                         {7, 6, 1, 0, 3, 2, 5, 4}};

void solve(int testNumber) {
    cout << "Case #" << testNumber << ": ";

    int N;
    i64 M;
    string S;
    cin >> N >> M >> S;

    int val = 0;
    for (int p: S)
        val = nextOp[val][p - 'h'];

    vector<int> reachTime(8, 0);
    int pos, time = 1;
    for (pos = val; reachTime[pos] == 0; pos = nextOp[pos][val]) {
        reachTime[pos] = time;
        ++time;
    }


    int cycleSize = time - reachTime[pos], extra = time - cycleSize;
    int period;
    if (M <= extra) period = M;
    else period = extra + cycleSize * min(3LL, (M - extra - 1) / cycleSize) + (M - extra - 1) % cycleSize + 1;

    string A;
    for (int i = 0; i < period; ++i)
        A += S;

    val = 0;
    for (int p: A)
        val = nextOp[val][p - 'h'];

    if (val != 4) {
        cout << "NO\n";
        return;
    }

    N = A.length();

    int firstAp = -1;
    val = 0;
    for (int i = 1; i <= N; ++i) {
        int c = A[i - 1] - 'h';
        val = nextOp[val][c];
        if (val == 1) {
            firstAp = i;
            break;
        }
    }

    if (firstAp == -1) {
        cout << "NO\n";
        return;
    }

    val = 0;
    for (int i = N; i > firstAp + 1; --i) {
        int c = A[i - 1] - 'h';
        val = nextOp[c][val];
        if (val == 3) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    //freopen("task.in", "r", stdin);
    //freopen("task.out", "w", stdout);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        solve(test);
        //cerr << "Done #" << test << '\n';
    }
}
