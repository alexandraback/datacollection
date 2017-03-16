#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int fix_cmp(int cmp, int left, int right) {
    if (cmp != 1) return cmp;
    if (left < right) return 0;
    if (left == right) return 1;
    return 2;
}

long long memo[32][3][3][3];
string A, B, K;

long long doit(int digits, int cmpA, int cmpB, int cmpK) {
    if (digits == 31)
        return cmpA <= 1 && cmpB <= 1 && cmpK <= 1;

    long long& ret = memo[digits][cmpA][cmpB][cmpK];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            ret += doit(digits + 1,
                        fix_cmp(cmpA, i, A[digits] - '0'),
                        fix_cmp(cmpB, j, B[digits] - '0'),
                        fix_cmp(cmpK, i & j, K[digits] - '0'));

    return ret;
}

string read_binary(int iA) {
    string A;
    for (int i = 0; i < 31; i++) {
        A = string(1, iA % 2 ? '1' : '0') + A;
        iA /= 2;
    }
    return A;
}

int main() {
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++) {
        int iA, iB, iK;
        cin >> iA >> iB >> iK;

        A = read_binary(iA-1);
        B = read_binary(iB-1);
        K = read_binary(iK-1);

        memset(memo, -1, sizeof memo);
        printf("Case #%d: %lld\n", z, doit(0, 1, 1, 1));
    }
}
