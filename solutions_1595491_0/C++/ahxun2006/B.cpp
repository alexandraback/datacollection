#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;

const int INF = 100000000;
int score[105], best[105][105];


int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("2.out", "w", stdout);
    int T, N, S, P;
    scanf("%d", &T);
    for (int caseId = 1; caseId <= T; ++caseId) {
        scanf("%d %d %d", &N, &S, &P);
        for (int i = 0; i < N; ++i)
            scanf("%d", &score[i]);
        for (int i = 0; i <= N; ++i)
            for (int j = 0; j <= S; ++j)
                best[i][j] = -INF;
        best[0][0] = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j <= S; ++j)
                if (best[i][j] >= 0) {
                    for (int a = 0; a <= 10; ++a)
                        for (int b = a; b <= a + 2 && b <= 10; ++b) {
                            for (int c = b; c <= a + 2 && b <= 10; ++c) {
                                if (a + b + c != score[i]) continue;
                                if (c - a < 2) {
                                    best[i + 1][j] = max(best[i][j] + (c >= P), best[i + 1][j]);
                                } else if (j + 1 <= S) {
                                    best[i + 1][j + 1] = max(best[i + 1][j + 1], best[i][j] + (c >= P));
                                }
                            }
                        }
                }
        printf("Case #%d: %d\n", caseId, best[N][S]);
    }
    return 0;
}
