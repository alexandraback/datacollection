#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <ctime>
#include <assert.h>
using namespace std;

#define PI 3.141592653589793
#define INF 2123456789
#define NUL 0.0000001

#define for_each(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define SZ size()
#define CS c_str()
#define PB push_back
#define MP make_pair
#define INS insert
#define EMP empty()
#define CLR clear()
#define LEN length()
#define MS(x) memset(x, 0, sizeof(x))
#define MS1(x) memset(x, -1, sizeof(x))

typedef long long LL;
typedef unsigned long long ULL;

const int MaxN = 205;

int a[MaxN];

int main(){
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    int t; scanf("%d", &t);
    for (int test = 1; test <= t; test++){
        int armin, n; scanf("%d%d", &armin, &n);
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        if (armin == 1){
            printf("Case #%d: %d\n", test, n);
            continue;
        }

        sort(a + 1, a + n + 1);

        int sol = n, t = 0;
        for (int i = 1; i <= n; i++)
            if (armin > a[i]) armin += a[i];
            else {
                sol = min(sol, n - i + 1 + t);
                armin += armin - 1;
                t++; i--;
            }
        sol = min(sol, t);
        printf("Case #%d: %d\n", test, sol);
    }
    return 0;
}
