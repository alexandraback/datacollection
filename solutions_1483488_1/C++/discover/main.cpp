#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <ctime>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define rep(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define sz size()
typedef long long ll;
const int N = 1000 + 11;


int a, b;

bool ok(int x, int y) {
    char s[10];
    sprintf(s, "%d", x);
    char c[10];
    sprintf(c, "%d", y);
    int len = strlen(s);
    if (len != strlen(c)) return false;
    for (int i = 1; i < len; ++i) {
        bool flag = true;
        for (int j = 0; j < len; ++j) {
            if (c[j] != s[(i + j)%len]) flag = false;
        }
        if (flag) return true;
    }
    return false;
}

int calc(int v) {
    set<int> S;
    int ar[10], arn = 0;
    int tv = v;
    while (v) {
        ar[arn++] = v % 10;
        v /= 10;
    }
    reverse(ar, ar + arn);
    for (int i = 1; i < arn; ++i) {
        int tmp = 0;
        for (int j = 0; j < arn; ++j) {
            tmp = tmp * 10 + ar[(i + j) % arn];
        }

        if (tmp > tv && tmp <= b) {
            S.insert(tmp);
        }
    }
    return  S.size();
}

int solve() {
    int res = 0;
    cin >> a >> b;
    for (int i = a; i <= b; ++i) {
        res += calc(i);
    }
//    int t = 0;
//    for (int i = a; i <= b; ++i){
//        for (int j = i + 1; j <= b; ++j)
//            if (ok(i,j)) ++ t;
//    }
//    cout << t << endl;
    return res;
}

int main() {
    int cas, tcas = 0;
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    for (cin >> cas, getchar(); cas; --cas) {
        printf("Case #%d: ", ++tcas);
        printf("%d\n", solve());
    }
}
