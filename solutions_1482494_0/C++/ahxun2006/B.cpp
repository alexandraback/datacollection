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
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int a[1005], b[1005];
bool used[2][1005];

int main() {
    freopen("B-small-attempt3.in", "r", stdin);
    freopen("B-small-attempt3.out", "w", stdout);
    int T, N;
    scanf("%d", &T);
    for (int caseId = 1; caseId <= T; ++caseId) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%d %d", &a[i], &b[i]);
        }
        for (int i = 0; i < N; ++i)
            for (int j = i + 1; j < N; ++j)
                if (b[i] < b[j]) {
                    swap(b[i], b[j]);
                    swap(a[i], a[j]);
                }
        int earn = 0, res = -1;
        memset(used, 0, sizeof(used));
        for (int steps = 1; steps <= 2005; ++steps) {
            int id = -1, num = 0, wh = -1;
            for (int i = 0; i < N; ++i) {
                if (!used[0][i] && !used[1][i] && earn >= a[i] && num < 1) {
                    id = i;
                    num = 1;
                    wh = 0;
                }
                if (!used[1][i] && earn >= b[i]) {
                    if (!used[0][i] && num < 2) {
                        num = 2;
                        id = i;
                        wh = 1;
                    } else if (used[0][i] && num <= 1) {
                        num = 1;
                        id = i;
                        wh = 1;
                    }
                }
            }
            if (id == -1) break;
            if (wh == 0) {
                earn += num;
                used[wh][id] = true;
            } else {
                earn += num;
                used[0][id] = used[1][id] = true;
            }
            if (earn ==  N * 2) {
                res = steps;
                break;
            }
            //cout << wh << " " << id << endl;
            //cout << earn << endl;
        }
        //cout << earn << endl;
        if (earn < N * 2) {
            printf("Case #%d: Too Bad\n", caseId);
        } else {
            printf("Case #%d: %d\n", caseId, res);
        }
    }
    return 0;
}
