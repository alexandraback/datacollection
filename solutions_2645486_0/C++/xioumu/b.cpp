/*
 * Author:  xioumu
 * Created Time:  2013/4/27 10:13:58
 * File Name: b.cpp
 * solve: b.cpp
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define sz(v) ((int)(v).size())
#define rep(i, n) for (lint i = 0; i < (n); ++i)
#define repf(i, a, b) for (lint i = (a); i <= (b); ++i)
#define repd(i, a, b) for (lint i = (a); i >= (b); --i)
#define clr(x) memset(x,0,sizeof(x))
#define clrs( x , y ) memset(x,y,sizeof(x))
#define out(x) printf(#x" %lld\n", x)
#define sqr(x) ((x) * (x))
typedef long long lint;

const lint maxlint = -1u>>1;
const double eps = 1e-8;
const lint maxn = 10000 + 10;

lint sgn(const double &x) {  return (x > eps) - (x < -eps); }

vector<lint > use;
lint e, r, v[maxn], n;

int main() {
    freopen("b.out", "w", stdout);
    lint T, ca = 1;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld%lld%lld", &e, &r, &n);
        rep (i, n) {
            scanf("%lld", &v[i]);
        }
        use.clear();
        r = min(e, r);
        lint have = n, now = e;
        while (have > 0) {
            if (now == e || have == 1) {
                use.push_back(now);
                now = r;
                have--;
            }
            else {
                if (now - 1 + r < e) {
                    use.push_back(1);
                    have--;
                    now += r - 1;
                }
                else {
                    lint h = now + r - e;
                    use.push_back(h);
                    now = e;
                    have--;
                }
            }
        }
        sort(v, v + n);
        sort(use.begin(), use.end());
        lint ans = 0;
        rep (i, n) {
            //printf("%lld %lld\n", v[i], use[i]);
            ans += v[i] * use[i];
        }
        printf("Case #%lld: ", ca++);
        printf("%lld\n", ans);
    }
    return 0;
}
