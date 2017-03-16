#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std;

int t;
int cache[2000010];
vector<pair<int, int> > vec;

void solve() {
    int a, b;
    scanf("%d%d", &a, &b);
    int ans = 0;
    for (vector<pair<int, int> >::iterator i = vec.begin(); i != vec.end(); ++i)
        if (i->first >= a && i->second <= b) {
            ++ans;
            //printf("%d %d\n", i->first, i->second);
        }
    printf("Case #%d: %d\n", ++t, ans);
}

int main() {
    freopen("C.out", "w", stdout);
    for (int i = 2; i < 2000010; ++i) {
        char buf[16];
        sprintf(buf, "%d", i);
        int a = 1, b = 10;
        for (int j = 1; buf[j] != '\0'; ++j)
            a *= 10;
        for (int j = 1; buf[j] != '\0'; ++j, a /= 10, b *= 10) {
            if (buf[j] == '0')
                continue;
            int tmp = i % a * b + i / a;
            if (tmp == i)
                break;
            if (tmp < i) {
                vec.push_back(make_pair(i % a * b + i / a, i));
            }
        }
    }
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}
