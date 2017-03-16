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

int c, d, v, a[20];
vi used, temp;

bool check(vi &a, int t) {
    vi used(t+1, 0);
    for(int mask = 1; mask < (1<<sz(a)); mask++) {
        int sum = 0;
        for(int i = 0; i < sz(a) && sum <= t; i++) {
            if((1<<i)&mask) sum += a[i];
        }
        if(sum <= t) used[sum] = 1;
    }
    for(int i = 1; i <= t; i++) {
        if(!used[i]) return false;
    }
    return true;
}

void go(int k, int last, int &ans) {
    if(k > 5) return;
    if(check(temp, v)) ans = min(ans, sz(temp) - d);
    for(int i = last + 1; i <= v; i++) {
        if(!used[i]) {
            temp.pb(i);
            go(k+1, i, ans);
            temp.pop_back();
        }
    }
}

void solve(int ind) {
    cin >> c >> d >> v;
    for(int i = 0; i < d; i++) cin >> a[i];
    if(c > 1) {
        printf("Case #%d: %d\n", ind, -1);
        return;
    }
    temp.clear();
    for(int i = 0; i < d; i++) temp.pb(a[i]);
    int ans = inf;
    used.assign(v+1, 0);
    for(int i = 0; i < d; i++) used[a[i]] = 1;
    go(0, 0, ans);
    printf("Case #%d: %d\n", ind, ans);
}

int main(){
    
    int t;
    
    cin >> t;
    
    for(int i = 1; i <= t; i++) solve(i);
        
    return 0;
}
