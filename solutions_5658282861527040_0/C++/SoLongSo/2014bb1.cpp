#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdint>

#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <set>

#include <string>

#include <stdint.h>
#include <limits>

using namespace std;

#define INF 1000000000
//FORE only want to repeat, so iterator will not be visible outside
#define FORE(a, b, c) for(int a = b; a < c; a++)

typedef pair<int, int> pii;
typedef long long ll;

struct A {
    char p[50];
    bool operator < (const A &q) const {
        return strcmp(p, q.p) < 0;
    }
} q[200], tar[200];

int main() {
    freopen("2014bb1.in", "r", stdin);
    freopen("2014bb1.ot", "w", stdout);
    int T, t = 0;
    cin >> T;

    while (t++ < T) {
        printf("Case #%d: ", t);
        int a, b, k;
        int ans = 0;
        cin >> a >> b >> k;
        for (int i = 0; i < a; i++)
            for (int j = 0; j < b; j++)
                if ((i&j) < k)
                    ans++;
        printf ("%d\n", ans);
    }
}
