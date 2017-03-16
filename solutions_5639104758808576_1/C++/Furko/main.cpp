#include <iostream>
#include <string>
#include <memory.h>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <queue>
#include <list>

using namespace std;
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) for(int i=0;i<n;++i)
int n; string s;
void solve() {
    cin >> n >> s; n++;
    for (int i = 0; i <= 10000; ++i) {
        bool is = true;
        int all = i;
        for (int j = 0; j < n; ++j) {
            int dig = s[j] - '0';
            if (dig) {
                if (all >= j) all += dig; else {
                    is = false;
                    break;
                }
            }
        }
        if (is) {
            cout << i << endl;
            return;
        }
    }
}
int main() {
    freopen("A-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    int num = 0;
    while (T--) {
        num++;
        cout << "Case #" << num << ": ";
        solve();
    }
    return 0;
}
