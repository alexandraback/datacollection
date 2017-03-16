#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

bool lst[105];
int n;

void flip(int left, int right) {
    int l = left;
    int r = right;
    while (l < r) {
        swap(lst[l], lst[r]);
        ++ l; -- r;
    }
    for (int i = left; i <= right; ++ i)
        lst[i] = !lst[i];
}

// + -> true, - -> false
int solve() {
    int count = 0;
    int R = n - 1;
    while (1) {
        while (R >= 0 && lst[R]) -- R;
        if (R < 0) break;
        ++ count;
        if (!lst[0]) {
            flip(0, R);
        }
        else {
            int L = 0;
            while (L <= R && lst[L]) ++ L;
            -- L;
            flip(0, L);
        }
    }
    return count;
}

char S[105];

int main() {
    int T;
    scanf("%d", &T);
    for (int test = 1; test <= T; ++ test) {
        printf("Case #%d: ", test);
        scanf("%s", S);
        n = strlen(S);
        for (int i = 0; i < n; ++ i)
            lst[i] = S[i] == '+';
        printf("%d\n", solve());
    }
    return 0;
}
