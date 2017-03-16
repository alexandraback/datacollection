#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctype.h>
#include <cstring>
#include <ctime>
#include <cassert>
#include <utility>

using namespace std;

#define MAXN 105
#define MAXP 1000005
int A, N, T;
int B[MAXN];
int mem[MAXN][MAXP];

int go(int p, int s) {
    if(mem[p][s] > -1)
        return mem[p][s];
    if(p == N)
        return 0;

    int ret = MAXN;

    if(s > B[p]) {
        ret = go(p + 1, min(MAXP - 1, s + B[p]));
    }
    else {
        // remove it
        ret = min(ret, 1 + go(p + 1, s));

        // add more
        if(s > 1) {
            int ns = min(MAXP - 1, s + s - 1);
            ret = min(ret, 1 + go(p, ns));
        }
    }

    return mem[p][s] = ret;
}

int main() {
	freopen("date.in", "r", stdin);
	freopen("date.out","w", stdout);

	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
        scanf("%d %d", &A, &N);
        for(int i = 0; i < N; i++)
            scanf("%d", &B[i]);

        sort(B, B + N);

        memset(mem, -1, sizeof(mem));
        int ans = go(0, A);

        printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}
