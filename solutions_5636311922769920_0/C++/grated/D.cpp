#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair

typedef long long           LL;
typedef unsigned long long  ULL;
typedef unsigned int        uint;
typedef pair<int, int>      pii;
typedef pair<LL, LL>        pll;

const int INF = 0x3f3f3f3f;

int main() {
    freopen("d_in.txt", "r", stdin);
    freopen("d_out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int K, C, S;
        scanf("%d%d%d", &K, &C, &S);
        printf("Case #%d:", t);
        for (int i = 1; i <= K; i++) {
            printf(" %d", i);
        }
        puts("");
    }
    return 0;
}
