#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

string get(int a) {
    if (a < 2) {
        return string(1, (char)('0' + a));
    }
    return get(a / 2) + (char)('0' + a % 2);

}

string get2(int a) {
    string res = get(a);
    res = string(100 - (int)res.size(), '0') + res;
    return res;
}

long long ways[200][2][2][2];

int update(int cmp, int a, int b) {
    if (cmp == 0) {
        if (a > b) return 2;
        if (a == b) return 0;
        return 1;
    }
    if (cmp == 1) {
        return 1;
    }
    return -1;
}

void solve() {
    memset(ways, 0, sizeof ways);
    int A, B, K;
    cin >> A >> B >> K;
    string sa = get2(A), sb = get2(B), sk = get2(K);
    ways[0][0][0][0] = 1LL;
    for (int i = 0; i < 100; ++i) {
        for (int cmpa = 0; cmpa < 2; ++cmpa) {
            for (int cmpb = 0; cmpb < 2; ++cmpb) {
                for (int cmpk = 0; cmpk < 2; ++cmpk) {
                    for (int a = 0; a < 2; ++a) {
                        for (int b = 0; b < 2; ++b) {
                            int ncmpa = update(cmpa, a, sa[i] - '0');
                            int ncmpb = update(cmpb, b, sb[i] - '0');
                            int ncmpk = update(cmpk, (a & b), sk[i] - '0');
                            if (ncmpa == 2 || ncmpb == 2 || ncmpk == 2) {
                                continue;
                            }
                            ways[i + 1][ncmpa][ncmpb][ncmpk] += ways[i][cmpa][cmpb][cmpk];
                        }
                    }
                }
            }
        }
    }
    cout << ways[100][1][1][1] << endl;
}

int main() {
    int testCount;
    cin >> testCount;
    for (int testId = 1; testId <= testCount; ++testId) {
        printf("Case #%d: ", testId);
        solve();
    }
}
