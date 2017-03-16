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

map <int, int> MP;
int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int caseId = 1; caseId <= T; ++caseId) {
        int A, B;
        scanf("%d %d", &A, &B);
        MP.clear();
        for (int i = A; i <= B; ++i) {
            int p = 1, mmin = i;
            while (mmin > 0) {
                p *= 10;
                mmin /= 10;
            }
            int pl = p, pr = 1;
            mmin = i;
            while (pl > 0) {
                int tmp = i / pr + i % pr * pl;
                if (tmp >= A && tmp <= B)
                    mmin = min(mmin, tmp);
                pl /= 10;
                pr *= 10;
            }
            MP[mmin]++;
        }
        int res = 0;
        for (map <int, int>::iterator it = MP.begin(); it != MP.end(); ++it) {
            if (it->second >= 2) {
                res += it->second * (it->second - 1) / 2;
            }
        }
        printf("Case #%d: %d\n", caseId, res);
    }
    return 0;
}
