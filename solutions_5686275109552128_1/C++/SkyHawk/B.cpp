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
        int d;
        cin >> d;
        FOR(i, d)
            cin >> ar[i];
        int ans = 1000000000;
        for(int eat_days = 1; eat_days <= 1005; ++eat_days) {
            int sum = 0;
            FOR(i, d) {
                sum += (ar[i] - 1) / eat_days; 
            }
            ans = min(ans, sum + eat_days);
        }
        cout << "Case #" << (itest + 1) << ": " << ans << endl;
    }
}