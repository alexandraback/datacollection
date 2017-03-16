#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <bitset>
#include <fstream>
#include <stack>
#include <deque>
#include <utility>
#include <numeric>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tests;
    scanf("%d", &tests);
    for (int t = 1; t <= tests; t++) {
        int r;
        int c;
        int w;
        scanf("%d %d %d", &r, &c, &w);
        int ans = 0;
        for (int i = 1; i <= r; i++) {
            ans += c / w;
        }
        ans += w - 1;
        if (c % w != 0) {
            ans++;
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}