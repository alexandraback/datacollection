#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <map>

using namespace std;

const int MAXN = 100;
const int INF = 12345678;
int S[MAXN];
int N;

typedef pair<long long, int> p_t;
map<p_t, int> dp;
int go(long long cur, int at) {
    const p_t state(cur, at);
    if (dp.count(state)) {
        return dp[state];
    }
    int &ret = dp[state];
    while (at<N && cur>S[at]) {
        cur += S[at++];
    }
    if (at == N) {
        ret = 0;
    } else {
        ret = 1 + go(cur, at+1);
        if (cur > 1) {
            ret = min(ret, 1 + go(2*cur-1, at));
        }
    }
    return ret;
}
int solve(int A) {
    dp.clear();
    return go(A, 0);
}
int main() {
    cin.sync_with_stdio(false);
    int ntestcases;
    scanf("%d", &ntestcases);
    for (int testcase=1; testcase<=ntestcases; ++testcase) {
        int A;
        scanf("%d %d", &A, &N);
        for (int i=0; i<N; ++i) {
            scanf("%d", S + i);
        }
        sort(S, S+N);
        printf("Case #%d: %d\n", testcase, solve(A));
    }
	return 0;
}
