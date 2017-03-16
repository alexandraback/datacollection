/*
 *  SRC: 
 * PROB: 
 * ALGO: 
 * DATE: Apr 28, 2012
 * COMP: g++
 *
 * Created by Leewings Ac
 */
#include <iostream>

using std::cerr;
using std::endl;

#ifndef DEBUG
#define DEBUG 0
#endif

#define debug(x) if (DEBUG) cerr << #x << " = " << (x) << endl

#define debug_line(a, n) do {                           \
    if (DEBUG) {                                        \
        for (int i = 0; i < (n); i++)                   \
        cerr << (a)[i] << " ";                          \
        cerr << endl;                                   \
    }                                                   \
} while (0)

#define debug_mat(a, n, m) do {                         \
    if (DEBUG) {                                        \
        for (int i = 0; i < (n); i++) {                 \
            for (int j = 0; j < (m); j++)               \
            cerr << (a)[i][j] << " ";                   \
            cerr << endl;                               \
        }                                               \
    }                                                   \
} while (0)

#include <cstdio>
#include <algorithm>

using namespace std;

double p[100010];
double pre[100010];

int main()
{
    int tasks;
    scanf("%d", &tasks);
    pre[0] = 1;
    for (int task = 1; task <= tasks; task++) {
        int A, B;
        scanf("%d%d", &A, &B);
        for (int i = 1; i <= A; i++) {
            scanf("%lf", p + i);
            pre[i] = pre[i - 1] * p[i];
        }

        double ans = min(pre[A] * (B - A + 1) + (1 - pre[A]) * (B - A + 1 + B + 1), B + 2.0);
        for (int i = 1; i <= A; i++) {
            ans = min(ans, i + pre[A - i] * (B - A + i + 1) + (1 - pre[A - i]) * (B - A + i + 1 + B + 1));
        }

        printf("Case #%d: %.8lf\n", task, ans);
    }


    return 0;
}

