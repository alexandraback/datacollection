#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)

#define equal equalll
#define less lesss
const int N = 1000;
const int INF = 1e9;

int n;
char s[N];

void read() {
    scanf("%d %s", &n, s);
}

void solve() {
    int ans = 0; 
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += s[i - 1] - '0';
        int t = max(0, i - sum);
        sum += t;
        ans += t;
    }
    printf("%d\n", ans);
}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    if (1) {
        int k;
        scanf("%d", &k);
        for (int tt = 0; tt < k; tt++) {
            printf("Case #%d: ", tt + 1);
            read();
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}

