#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iterator>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define for_size(var, size) \
    for(int var = 0; var < (size); ++var)
#define for_range(var, from, to) \
    for(int var = (from); var < (to); ++var)
#define for_ranges(var, from, to, step) \
    for(int var = (from); var < (to); var += (step))
#define for_each(var, container) \
    for(typeof((container).begin()) var = (container).begin(); var != (container).end(); ++var)

using namespace std;

const int MAX_N = 1000;
int n;
int state[MAX_N];
int a[MAX_N];
int b[MAX_N];
int order[MAX_N];
bool cmp(const int i, const int j) {
    return b[i] > b[j];
}
int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B.out", "w", stdout);

    int testNum;
    cin >> testNum;
    for_size(testIdx, testNum) {
        cin >> n;
        for_size(i, n) {
            cin >> a[i] >> b[i];
            order[i] = i;
        }
        sort(order, order + n, cmp);
        fill(state, state + n, 0);
        int cnt = 0, cur = 0, ans = 0;
        while (cnt < n) {
            bool changed = false;
            for_size(i, n) 
                if (state[i] < 2 && cur >= b[order[i]]) {
                    cnt++;
                    ans++;
                    cur += 2 - state[i];
                    state[i] = 2;
                    changed = true;
                }
            if (changed) 
                continue;
            for_size(i, n)
                if (state[i] == 0 && cur >= a[order[i]]) {
                    state[i] = 1;
                    cur++;
                    ans++;
                    changed = true;
                    break;
                }
            if (!changed)
                break;
        }
        if (cnt == n) {
            printf("Case #%d: %d\n", testIdx + 1, ans);
        } else {
            printf("Case #%d: Too Bad\n", testIdx + 1);
        }
    }

    return 0;
}
