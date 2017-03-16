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

bool ok(int n, int m) {
    if (n == m) return false;
    char s[10];
    sprintf(s, "%d", n);
    char c[10];
    sprintf(c, "%d", m);
    int len1 = strlen(s), len2 = strlen(c);
    if (len1 != len2) return false;

    for (int start = 1; start < len1; ++start) {
        bool flag = true;
        for (int i = 0; i < len1; ++i) {
            if (s[(start + i)%len1] != c[i]) flag = false;
        }
        if(flag){
           // cout << n <<" " << m << endl;
            return true;
        }
    }
    return false;

}

int solve() {
    int a, b;
    cin >> a >> b;
    int res = 0;
    for (int i = a; i <= b; ++i) {
        for (int j = i + 1; j <= b; ++j) {
            if (ok(i, j)) ++res;
        }
    }
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