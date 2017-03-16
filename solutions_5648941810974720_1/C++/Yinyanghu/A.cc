#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>

using namespace std;

string S;

int A[10];

int counting(char c) {
    int ret = 0;
    for (int i = 0; i < S.size(); ++ i)
        if (S[i] == c) ++ ret;
    return ret;
}

void solve() {
    memset(A, 0, sizeof(A));
    A[0] = counting('Z');
    A[2] = counting('W');
    A[4] = counting('U');
    A[6] = counting('X');
    A[8] = counting('G');
    A[5] = counting('F') - A[4];
    A[7] = counting('S') - A[6];
    A[9] = counting('I') - A[5] - A[6] - A[8];
    A[1] = counting('N') - A[7] - 2 * A[9];
    A[3] = counting('T') - A[2] - A[8];
    for (int i = 0; i < 10; ++ i)
        for (int j = 0; j < A[i]; ++ j)
            cout << i;
    cout << endl;
}

int main() {
    int T;
    int test = 1;
    for (cin >> T; T --;) {
        cin >> S;
        cout << "Case #" << test ++ << ": ";
        solve();
    }
    return 0;
}
