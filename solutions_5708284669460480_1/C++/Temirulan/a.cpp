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

int s, k, l;
string a, b;
int dp[200][200];
int cnt[200];

vector<int> z_function (string s) {
    int n = (int) s.length();
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}

int get(string a, string b) {
    vi z = z_function(a + "$" + b);
    for(int i = sz(a) + 2; i < sz(z); i++) {
        if(z[i] == sz(z) - i) return z[i];
    }
    return 0;
}

int calc(int ind, int suff) {
    if(ind == s) return 0;
    int &res = dp[ind][suff];
    if(res != -1) return res;
    res = 0;
    for(int i = 0; i < 26; i++) {
        char c = char(i + 'A');
        if(cnt[i]) {
            if(c == b[suff]) {
                int cur = 0;
                int nsuff = suff;
                if(suff + 1 == sz(b)) {
                    cur = 1;
                    nsuff = get(b, b);
                } else {
                    cur = 0;
                    nsuff = suff+1;
                }
                res = max(res, cur + calc(ind+1, nsuff));
            } else {
                int cur = 0;
                string cursuff = "";
                if(suff) cursuff += b.substr(0, suff);
                cursuff += c;
                int nsuff = get(b, cursuff);
                res = max(res, calc(ind+1, nsuff));
            }
        }
    }
    return res;
}

double dp1[200][200];
bool calced[200][200];

double calc1(int ind, int suff) {
    if(ind == s) return 0;
    double &res = dp1[ind][suff];
    if(calced[ind][suff]) return res;
    res = 0;
    calced[ind][suff] = 1;
    for(int i = 0; i < 26; i++) {
        char c = char(i + 'A');
        if(cnt[i]) {
            double p = cnt[i] / (1.0 * k);
            if(c == b[suff]) {
                int cur = 0;
                int nsuff = suff;
                if(suff + 1 == sz(b)) {
                    cur = 1;
                    nsuff = get(b, b);
                } else {
                    cur = 0;
                    nsuff = suff+1;
                }
                res += p * (cur + calc1(ind+1, nsuff));
            } else {
                int cur = 0;
                string cursuff = "";
                if(suff) cursuff += b.substr(0, suff);
                cursuff += c;
                int nsuff = get(b, cursuff);
                res += p * calc1(ind+1, nsuff);
            }
        }
    }
    return res;
}

void solve(int ind) {
    cin >> k >> l >> s;
    cin >> a >> b;
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < sz(a); i++) cnt[a[i]-'A']++;
    memset(dp, -1, sizeof dp);
    int ans = calc(0, 0);
    memset(calced, 0, sizeof calced);
    printf("Case #%d: %.9lf\n", ind, ans-calc1(0, 0));
}

int main(){
    
    int t;
    
    cin >> t;
    
    for(int i = 1; i <= t; i++) solve(i);
        
    return 0;
}
