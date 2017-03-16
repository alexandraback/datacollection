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
#include <cstring>
#include <algorithm>

using namespace std;

struct Level {
    int a, b;
    int id;
};
int cmp_a(const Level &x, const Level &y) { return x.a == y.a ? x.b > y.b : x.a < y.a; }
int cmp_b(const Level &x, const Level &y) { return x.b < y.b; }

Level lev1[1010], lev2[1010];
int complete[1010];

int solve(int n)
{
    int res = 0;
    int star = 0;
    memset(complete, 0, sizeof(complete));

    for (int i = 0, j = 0; i < n; ) {
        if (star >= lev2[i].b) {
            star += 2 - complete[lev2[i].id];
            complete[lev2[i].id] = 2;
            i++;
        } else {
            while (j < n && complete[lev1[j].id] != 0) j++;
            if (j >= n || lev1[j].a > star) {
                return -1;
            }
            star++;
            complete[lev1[j].id] = 1;
            j++;
        }
        res++;
    }

    return res;
}

int main()
{
    int tasks;
    scanf("%d", &tasks);
    for (int task = 1; task <= tasks; task++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            lev1[i].id = i;
            scanf("%d %d", &lev1[i].a, &lev1[i].b);
            lev2[i] = lev1[i];
        }
        sort(lev1, lev1 + n, cmp_a);
        sort(lev2, lev2 + n, cmp_b);

        printf("Case #%d: ", task);
        int r = solve(n);
        if (r == -1) {
            puts("Too Bad");
        } else {
            printf("%d\n", r);
        }
    }

    return 0;
}

