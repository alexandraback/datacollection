#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <complex>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;

const int maxn = 2000000 + 10;

int p10[10];
vector<int> cycle[maxn];
int a[10], len;

void Init() {
    p10[0] = 1;
    for (int i = 1; i < 10; ++i) p10[i] = p10[i - 1] * 10;
        
    for (int i = 1; i <= 2000000; ++i) {
        len = 0;
        for (int x = i; x > 0; x /= 10) a[len++] = x % 10;
        reverse(a, a + len);
        int value = i;
        for (int j = 0; j < len; ++j) {
            if (value < i && a[0] != 0) {
                cycle[i].push_back(value);
            }
            value -= a[0] * p10[len - 1];
            rotate(a, a + 1, a + len);
            value *= 10;
            value += a[len - 1];
        }
        if (cycle[i].empty()) continue;
        sort(cycle[i].begin(), cycle[i].end());
        cycle[i].erase(unique(cycle[i].begin(), cycle[i].end()), cycle[i].end());
    }
}

//set<pair<int, int> > st;

void main2() {
    int L, R;
    scanf("%d%d", &L, &R);
    int ans = 0;
    for (int i = L; i <= R; ++i) {
        int x = lower_bound(cycle[i].begin(), cycle[i].end(), L) - cycle[i].begin();
        /*
        for (int j = x; j < cycle[i].size(); ++j) {
            if (st.count(make_pair(cycle[i][j], i))) {
                cout << i << endl;
            }
            st.insert(make_pair(cycle[i][j], i));
        }
        */
        ans += cycle[i].size() - x;
    }
    printf("%d\n", ans);
    //cout << st.size() << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-large (1).in", "r", stdin);
    freopen("C.out", "w", stdout);
    Init();

    int testCnt;
    scanf("%d", &testCnt);
    for (int caseId = 1; caseId <= testCnt; ++caseId) {
        printf("Case #%d: ", caseId);
        main2();
    }
}

