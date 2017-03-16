/*
 * Author:  xioumu
 * Created Time:  2013/5/12 17:18:06
 * File Name: a.cpp
 * solve: a.cpp
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
#define out(x) printf(#x" %I64d\n", x)
#define sqr(x) ((x) * (x))
typedef long long lint;

const lint maxlint = -1u>>1;
const double eps = 1e-8;
const lint maxn = 1000000 + 10;


lint sgn(const double &x) {  return (x > eps) - (x < -eps); }

lint last[maxn], n, m;
char s[maxn];

bool isC(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return false;
    return true;
}

int main() {
    freopen("a.out", "w", stdout);
    lint T, ca = 1;
    scanf("%I64d", &T);
    while (T--) {
        scanf("%s", s);
        n = strlen(s);
        scanf("%I64d", &m);
        lint now = 0, end = n;
        repd (i, n - 1, 0) {
            if (isC(s[i])) now++;
            else now = 0;
            if (now >= m) end = i + m - 1;
            last[i] = end;
            //out(now);
        }
        //rep (i, n)
            //printf("%I64d ", last[i]);
        //puts("");
        
        lint ans = 0;
        rep (i, n) {
            if (last[i] != n) {
                ans += (n - last[i]);
            }
        }
        printf("Case #%I64d: ", ca++);
        printf("%I64d\n", ans);
    }
    return 0;
}
