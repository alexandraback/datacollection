#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <utility>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define INF 2e9
#define pb push_back
#define mp make_pair
#define forn(i,n) for (int i = 0; i < n; i++)

using namespace std;

typedef long long ll;

int t, n;
ll x;
ll a;
vector <ll> d;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    forn (test, t) {
        cin >> a >> n;
        d.clear();
        forn (i, n) {
            cin >> x;
            d.pb(x);
        }
        sort(d.begin(), d.end());
        int ans = INF, k = 0;
        for (int i = 0; i < n; i++) {
            if (a > d[i]) {
                a += d[i];
            } else {
                ans = min(ans, k + n - i);
                if (a == 1) {
                    k = INF;
                    break;

                }
                a += a - 1;
                k++;
                i--;
            }
        }
        ans = min(ans, k);
        printf("Case #%d: %d\n", test + 1, ans);
    }
    return 0;
}
