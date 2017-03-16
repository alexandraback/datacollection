#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define sz(a) (int)a.size()
#define fs first
#define sc second

typedef long long ll;
typedef pair<int,int> ii;

char a[30], b[30], c[30], d[30], res1[30], res2[30], res3[30], res4[30];
ll res;
int n;

ll get(char * a) {
    ll res = 0;
    for (int i = 1; i <= n; ++i)
        res = res*10 + a[i] - '0';
    return res;
}

void bang(char * a, char * b, int idx) {
    for (int i = idx; i <= n; ++i)
        a[i] = b[i];
}

void gq(int i) {
    bool f1 = c[i] > d[i], f2 = d[i] > c[i];
    for (int j = i+1; j <= n; ++j) {
        if (c[j]=='?') c[j] = f1 ? '0' : '9';
        if (d[j]=='?') d[j] = f2 ? '0' : '9';
    }
}

void update(ll ans) {
    if (ans < res) {
        res = ans;
        bang(res1,c,1); bang(res2,d,1);
        return;
    }
    bang(res3,c,1); bang(res4,d,1);
    ll k1 = get(res1), k2 = get(res2), k3 = get(res3), k4 = get(res4);
    if (k3 < k1 || (k3==k1 && k4 < k2)) {
        res = ans;
        bang(res1,c,1); bang(res2,d,1);
    }
}

void solve() {
    n = strlen(a+1);
    bang(c,a,1); bang(d,b,1);
    res = 2000000000000000000LL;
    for (int i = 1; i <= n; ++i) {
        if (c[i]=='?'&&d[i]=='?') {
            c[i] = '0'; d[i] = '1';
            gq(i);
            ll k1 = get(c), k2 = get(d), ans = abs(k1-k2);
            if (res >= ans) update(ans);
            bang(c,a,i+1); bang(d,b,i+1);
            /////////
            c[i] = '1'; d[i] = '0';
            gq(i);
            k1 = get(c), k2 = get(d), ans = abs(k1-k2);
            if (res >= ans) update(ans);
            bang(c,a,i+1); bang(d,b,i+1);
            /////////
            c[i] = d[i] = '0';
            continue;
        }
        if (c[i]!='?'&&d[i]!='?') {
            if (c[i]==d[i]) continue;
            gq(i);
            ll k1 = get(c), k2 = get(d), ans = abs(k1-k2);
            if (res >= ans) update(ans);
            return;
        }
        if (c[i]=='?') {
            if (d[i]+1 <= '9') {
                c[i] = d[i]+1;
                gq(i);
                ll k1 = get(c), k2 = get(d), ans = abs(k1-k2);
                if (res >= ans) update(ans);
                bang(c,a,i+1); bang(d,b,i+1);
            }
            if (d[i]-1 >= '0') {
                c[i] = d[i]-1;
                gq(i);
                ll k1 = get(c), k2 = get(d), ans = abs(k1-k2);
                if (res >= ans) update(ans);
                bang(c,a,i+1); bang(d,b,i+1);
            }
            c[i] = d[i];
        }
        if (d[i]=='?') {
            if (c[i]+1 <= '9') {
                d[i] = c[i]+1;
                gq(i);
                ll k1 = get(c), k2 = get(d), ans = abs(k1-k2);
                if (res >= ans) update(ans);
                bang(c,a,i+1); bang(d,b,i+1);
            }
            if (c[i]-1 >= '0') {
                d[i] = c[i]-1;
                gq(i);
                ll k1 = get(c), k2 = get(d), ans = abs(k1-k2);
                if (res >= ans) update(ans);
                bang(c,a,i+1); bang(d,b,i+1);
            }
            d[i] = c[i];
        }
    }
    ll k1 = get(c), k2 = get(d), ans = abs(k1-k2);
    if (res >= ans) update(ans);
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int t; scanf("%d\n",&t); int tmp = t;
    while (t--) {
        scanf("%s %s\n",a+1,b+1);
        printf("Case #%d: ",tmp-t);
        solve();
        for (int i = 1; i <= n; ++i) printf("%c",res1[i]);
        printf(" ");
        for (int i = 1; i <= n; ++i) printf("%c",res2[i]);
        printf("\n");
    }
	return 0;
}
