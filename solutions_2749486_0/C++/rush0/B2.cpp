#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define OUT(x) cerr << #x << ": " << (x) << endl
#define SZ(x) ((int)x.size())
#define FOR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long LL;

int T, x, y;

void go(int x, char front, char back) {
    while (x--) {
        printf("%c%c", back, front);
    }
}

int main() {
    scanf("%d", &T);
    for (int id = 1; id <= T; ++id) {
        scanf("%d%d", &x, &y);
        printf("Case #%d: ", id);
        if (0 <= x) {
            go(x, 'E', 'W');
        } else {
            go(-x, 'W', 'E');
        }
        if (0 <= y) {
            go(y, 'N', 'S');
        } else {
            go(-y, 'S', 'N');
        }
        printf("\n");
    }
    return 0;
}
