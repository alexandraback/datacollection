#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
char s[100];
vector<long long> v;

bool p(long long x) {
    sprintf(s, "%lld", x);
    int len = strlen(s);
    for (int i = 0; i <= len - i - 1; i++)
        if (s[i] != s[len - i - 1]) return 0;
    return 1;
}

void check(long long x) {
    if (p(x) && p(x * x)) v.push_back(x * x);
}

int main() {
    freopen("C-large-1.in", "r", stdin);
    freopen("out.1.txt", "w", stdout);
    v.clear();
    for (int i = 1; i <= 20000000; i++) check(i);
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        long long x, y, xx, yy;
        cin >> x >> y;
        x--;
        for (xx = 0; v[xx] <= x; xx++);
        for (yy = 0; v[yy] <= y; yy++);
        printf("Case #%d: %lld\n", cas, yy - xx);
    }
    return 0;
}