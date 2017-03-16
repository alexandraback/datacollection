#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair < int, int >
#define pll pair < long long, long long>
#define ull unsigned long long
#define y1 stupid_cmath
#define left stupid_left
#define right stupid_right
#define vi vector <int>
#define sz(a) (int)a.size()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x))

const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);

int r, c, w;

int calc(int n) {
    if(n == w) return w;
    int ans = 0;
    int l = w, r = w;
    int ln = w-1, rn = n-w;
    while(r-l+1 < w) {
        int cur = r-l+1;
        if(ln > rn && ln) {
            if(cur + rn >= w) {
                ans = max(ans, r - l + 1 + 1 + w - cur);
            }
            ln--;
            l--;
        } else if(rn >= ln && rn) {
            if(cur + ln >= w) {
                ans = max(ans, r - l + 1 + 1 + w - cur);
            }
            rn--;
            r++;
        }
    }
    if(n - w >= w) ans = max(ans, calc(n-w) + 1);
    return ans;
}

int solve() {
    if(r == 1) return calc(c);
    else return -1;
}

int main(){
    
    int t;
    
    cin >> t;
    
    for(int i = 1; i <= t; i++) {
        cin >> r >> c >> w;
        printf("Case #%d: %d\n", i, solve());
    }
        
    return 0;
}
