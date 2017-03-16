#include <cassert>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iterator>
#include <utility>
#include <algorithm>
#include <list>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

#define pb push_back
#define sz(v) ((long long)v.size())
#define mp make_pair
#define FOR(i,n) for(int i = 0;i < (n);++i)

long long MOD = 1000000007;

int T;
int ar[1010];

int main() {
    cin >> T;
    FOR(itest, T) {
        int n;
        string s;
        cin >> n >> s;
        ar[0] = s[0] - '0';
        FOR(i, n)
            ar[i+1] = ar[i] + s[i+1] - '0';
        int ans = 0;
        FOR(i, n) {
            // cerr << ar[i] << endl;
            ans = max(ans, i + 1 - ar[i]);
        }
        cout << "Case #" << (itest + 1) << ": " << ans << endl;
    }
}