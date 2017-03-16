#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define sz(a) (int)a.size()
#define fs first
#define sc second

typedef long long ll;
typedef pair<int,int> ii;

int n;
string s[20], t[20];

void solve() {
    int res = 0, p = 1<<n;
    for (int i = 0; i < p; ++i) {
        set <string> a, b;
        for (int j = 0; j < n; ++j)
            if (!(i&(1<<j))) a.insert(s[j]), b.insert(t[j]);
        bool check = true;
        for (int j = 0; j < n; ++j) {
            if ((i&(1<<j))) {
                if (a.find(s[j])==a.end() || b.find(t[j])==b.end()) {
                    check = false;
                    break;
                }
            }
        }
        if (check) res = max(res, __builtin_popcount(i));
    }
    printf("%d\n",res);
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int test; scanf("%d",&test); int tmp = test;
    while (test--) {
        scanf("%d",&n);
        for (int j = 0; j < n; ++j)
            cin >> s[j] >> t[j];
        printf("Case #%d: ",tmp-test);
        solve();
    }
    return 0;
}

