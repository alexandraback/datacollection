#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;

int main() {
    int testcases;
    cin>>testcases;
    for (int t = 1; t <= testcases; ++t) {
        printf("Case #%d:", t);
        int n;
        cin>>n;
        map<int, int> cnt;
        for (int i = 1; i <= 2*n-1; ++i) {
            for (int j = 1; j <= n; ++j) {
                int x;
                cin>>x;
                ++cnt[x];
            }
        }
        for (const pair<int, int> p : cnt) {
            if (p.second % 2 == 1) {
                printf(" %d", p.first);
            }
        }
        putchar('\n');
    }
}
