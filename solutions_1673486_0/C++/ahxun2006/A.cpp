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

double p[100000], e[100005];

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A.txt", "w", stdout);
    int T, A, B;
    scanf("%d", &T);/*
    for (int caseId = 1; caseId <= T; ++caseId) {
        scanf("%d %d", &A, &B);
        for (int i = 0; i < A; ++i) scanf("%lf", &p[i]);
        double prob = 1.0;
        for (int i = A; i >= 1; --i) {
            e[i] = prob * (1.0 - p[i - 1]);
            prob *= p[i - 1];
        }
        e[0] = prob;
        for (int i = 0; i <= A; ++i) cout << e[i] << " "; cout << endl;
        int len = B - A;
        double res = (len + 1) * e[0] + (len + 2 + B) * (1.0 - e[0]);
        res = min(res, (double)B + 2.0);
        cout << res << endl;
        double rem = 1.0 - e[0];
        for (int i = A; i >= 1; --i) {
            double cost = A - (i - 1) + B - (i - 1) + 1;
            rem -= e[i];
            res = min(res, rem * (cost + B + 1) + (1.0 - rem) * cost);
            cout << rem << " " << rem * (cost + B + 1) + (1.0 - rem) * cost << endl;
        }
        printf("Case #%d: %.9lf\n", caseId, res);
    }    */
    for (int caseId = 1; caseId <= T; ++caseId) {
        scanf("%d %d", &A, &B);
        for (int i = 0; i < A; ++i) scanf("%lf", &p[i]);
        double prob = 1.0;
        for (int i = 1; i <= A; ++i) {
            prob *= p[i - 1];
            e[i] = 1.0 - prob;
        }
        int len = B - A;
        double res = (len + 1) * prob + (len + 2 + B) * (1.0 - prob);
        res = min(res, (double)B + 2.0);
      //  cout << res << endl;
        for (int i = A; i >= 2; --i) {
            double cost = A - (i - 1) + B - (i - 1) + 1;
            res = min(res, e[i - 1] * (cost + B + 1) + (1.0 - e[i - 1]) * cost);
        }
        printf("Case #%d: %.9lf\n", caseId, res);
    }
    return 0;
}
