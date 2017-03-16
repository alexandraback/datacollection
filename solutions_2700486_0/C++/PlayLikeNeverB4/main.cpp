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

#define OFFSET 15000
int T, N, X, Y;
int H[30000];

double go(int p) {
    if(p == N) {
        if(H[X + OFFSET] > Y && (H[X + OFFSET] - Y) % 2 == 0)
            return 1.0;
        return 0.0;
    }

    int h = H[OFFSET];
    double ret = 0.0;
    if(H[OFFSET + 1] < h && H[OFFSET - 1] < h) {
        // right
        int x = 0;
        while(H[OFFSET + x + 1] < H[OFFSET + x])
            x++;

        int aux1 = H[OFFSET + x - 1];
        int aux2 = H[OFFSET + x + 1];

        H[OFFSET + x] += 2;

        H[OFFSET + x - 1] = max(H[OFFSET + x - 1], H[OFFSET + x] - 1);
        H[OFFSET + x + 1] = max(H[OFFSET + x + 1], H[OFFSET + x] - 1);

        ret += go(p + 1);

        H[OFFSET + x] -= 2;

        H[OFFSET + x - 1] = aux1;
        H[OFFSET + x + 1] = aux2;

        // left
        x = 0;
        while(H[OFFSET + x - 1] < H[OFFSET + x])
            x--;

        aux1 = H[OFFSET + x - 1];
        aux2 = H[OFFSET + x + 1];

        H[OFFSET + x] += 2;

        H[OFFSET + x - 1] = max(H[OFFSET + x - 1], H[OFFSET + x] - 1);
        H[OFFSET + x + 1] = max(H[OFFSET + x + 1], H[OFFSET + x] - 1);

        ret += go(p + 1);

        H[OFFSET + x] -= 2;

        H[OFFSET + x - 1] = aux1;
        H[OFFSET + x + 1] = aux2;

        ret *= 0.5;
    }
    else {
        if(H[OFFSET + 1] > h && H[OFFSET - 1] > h) {
            int aux1 = H[OFFSET - 1];
            int aux2 = H[OFFSET + 1];

            H[OFFSET] += 2;

            H[OFFSET - 1] = max(H[OFFSET - 1], H[OFFSET] - 1);
            H[OFFSET + 1] = max(H[OFFSET + 1], H[OFFSET] - 1);

            ret = go(p + 1);

            H[OFFSET] -= 2;

            H[OFFSET - 1] = aux1;
            H[OFFSET + 1] = aux2;
        }
        else if(H[OFFSET + 1] < h) {
            int x = 0;
            while(H[OFFSET + x + 1] < H[OFFSET + x])
                x++;

            int aux1 = H[OFFSET + x - 1];
            int aux2 = H[OFFSET + x + 1];

            H[OFFSET + x] += 2;

            H[OFFSET + x - 1] = max(H[OFFSET + x - 1], H[OFFSET + x] - 1);
            H[OFFSET + x + 1] = max(H[OFFSET + x + 1], H[OFFSET + x] - 1);

            ret = go(p + 1);

            H[OFFSET + x] -= 2;

            H[OFFSET + x - 1] = aux1;
            H[OFFSET + x + 1] = aux2;
        }
        else {
            int x = 0;
            while(H[OFFSET + x - 1] < H[OFFSET + x])
                x--;

            int aux1 = H[OFFSET + x - 1];
            int aux2 = H[OFFSET + x + 1];

            H[OFFSET + x] += 2;

            H[OFFSET + x - 1] = max(H[OFFSET + x - 1], H[OFFSET + x] - 1);
            H[OFFSET + x + 1] = max(H[OFFSET + x + 1], H[OFFSET + x] - 1);

            ret = go(p + 1);

            H[OFFSET + x] -= 2;

            H[OFFSET + x - 1] = aux1;
            H[OFFSET + x + 1] = aux2;
        }
    }

    return ret;
}

int main() {
	freopen("date.in", "r", stdin);
	freopen("date.out","w", stdout);

	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
        scanf("%d %d %d", &N, &X, &Y);

        memset(H, 0, sizeof(H));
        double ans = go(0);
        printf("Case #%d: %.6lf\n", t, ans);
	}

	return 0;
}
