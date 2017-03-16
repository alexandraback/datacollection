#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

int m[1000010];

pair<int,int> need(int now, int next) {
    int cnt = 0;
    while (now <= next) {
        ++ cnt;
        now += now - 1;
    }
    return make_pair(cnt,now);
}

int main () {
    int T;
    scanf("%d", &T);
    for (int ti = 1; ti <= T; ++ ti) {
        int A, N;
        scanf("%d%d", &A, &N);
        for (int i = 0; i < N; ++ i) {
            scanf("%d", &m[i]);
        }
        sort(m, m + N);
        if (A == 1) {
            printf("Case #%d: %d\n", ti, N);
            continue;
        }
        int res = N;
        int cur = A;
        int cnt = 0;
        for (int i = 0; i < N; ++ i) {
            pair<int,int> ret = need(cur, m[i]);
            cnt += ret.first;
            cur = ret.second + m[i];
            res = min(res, cnt + N - i - 1);
        }
        printf("Case #%d: %d\n", ti, res);
    }
}
