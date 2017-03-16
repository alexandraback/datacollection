#define DBG 1

#include <cstring>
#include <map>
#include <unordered_map>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> pii;

int gi() {
    int a;
    scanf("%d", &a);
    return a;
}

#define SINGLELINE 1
char s[1024];
void solve() {
    int sm = gi();
    scanf("%s", s);
    int res = 0, tot = 0;
    for (int i = 0; i <= sm; i++) {
        int v = s[i]-'0';
        if (v) {
            if (tot < i) {
                res += i-tot;
                tot = i;
            }
            tot += v;
        }
    }
    printf("%d\n", res);
}

int main() {
    int t = gi();

    for (int i = 1; i <= t; i++) {
        printf("Case #%d:%c", i, (SINGLELINE ? ' ' : '\n'));
        solve();
    }

    return 0;
}
