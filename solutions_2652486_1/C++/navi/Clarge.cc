#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int T, R, N, M, K;
ll a[12];
vector<int> res;

bool f(int n) {
    for (int i = 0; i < K; ++i) {
        if (a[i] % n == 0) {
            return true;
        }
    }
    return false;
}

void gao(int n) {
    int count = 0;
    for (int i = 0; i < K; ++i) {
        int cur = 0;
        for (ll j = a[i]; j % n == 0; j /= n, ++cur);
        count = max(count, cur);
    }
    for (int i = 0; i < count; ++i) {
        res.push_back(n);
    }
}

void gao() {
    gao(3);
    gao(5);
    gao(7);
    bool f2 = false, f4 = false, f8 = false;
    for (int i = 0; i < K; ++i) {
        int count = 0;
        for (ll j = a[i]; j % 2 == 0; j /= 2, ++count);
        if (count == 1) {
            f2 = true;
        } else if (count == 2) {
            f4 = true;
        } else if (count == 3) {
            f8 = true;
        }
    }
    if (f8) {
        if (f4 && f2) {
            res.push_back(4);
            res.push_back(2);
        } else {
            res.push_back(8);
            if (f4) {
                res.push_back(4);
            } else if (f2) {
                res.push_back(2);
            }
        }
    } else if (f4) {
        res.push_back(4);
    }
    while ((int)res.size() < N) {
        res.push_back(2);
    }
}

int main() {
    scanf("%d", &T);
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        printf("Case #%d:\n", caseNum);
        scanf("%d%d%d%d", &R, &N, &M, &K);
        for (int i = 0; i < R; ++i) {
            res.clear();
            for (int j = 0; j < K; ++j) {
                scanf("%lld", &a[j]);
            }
            gao();
            for (int j = 0; j < N; ++j) {
                printf("%d", res[j]);
            }
            puts("");
        }
    }
    return 0;
}
