#define DBG 1

#include <cstring>
#include <map>
#include <unordered_map>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> pii;

int gi() {
    int a;
    scanf("%d", &a);
    return a;
}

#define SINGLELINE 1
int p[1000];
bool myfunction (int i,int j) { return (i>j); }

void solve() {
    int d = gi();
    int max = 0;
    for (int i = 0; i < d; i++) {
        p[i] = gi();
        max = MAX(max, p[i]);
    }
    sort(p, p+d, myfunction);
    int res = 10000;
    for (int t = 1; t <= max; t++) {
        int r = t;
        for (int i = 0; i < d && p[i] > t; i++)
            r += ((p[i]/t) + (p[i]%t ? 1 : 0)) - 1;
        res = MIN(r, res);
    }
    printf("%d\n", res);
}

int main() {
    int t = gi();

    for (int i = 1; i <= t; i++) {
        printf("Case #%d:%c", i, (SINGLELINE ? ' ' : '\n'));
        solve();
    }

    return 0;
}
