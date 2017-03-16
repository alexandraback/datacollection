#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

const int maxn = 100 + 10;
const ll INF = 5e18;

char s[maxn];
int sc[maxn], sd[maxn];
int c[maxn], d[maxn];
int n;
ll ansCha, ansC, ansD;

void calcu() {
    ll a, b;
    a = 0;
    b = 0;
    for(int i = 0; i < n; i++) {
        a = a * 10 + (ll)c[i];
        b = b * 10 + (ll)d[i];
    }
    //cout << a << " " << b << endl;
    ll t = a - b;
    if(t < 0) {
        t = -t;
    }
    if(t < ansCha) {
        ansCha = t;
        ansC = a;
        ansD = b;
    }
    else if(t == ansCha) {
        if(a < ansC) {
            ansC = a;
            ansD = b;
        }
        else if(a == ansC) {
            if(b < ansD) {
                ansD = b;
            }
        }
    }
}

void dfs(int pos, int flag) {
    if(pos == n) {
        calcu();
        return;
    }
    if(flag == 0) {
        if(sc[pos] == -1 && sd[pos] == -1) {
            c[pos] = 1;
            d[pos] = 0;
            dfs(pos + 1, 1);
            c[pos] = 0;
            d[pos] = 0;
            dfs(pos + 1, 0);
            c[pos] = 0;
            d[pos] = 1;
            dfs(pos + 1, -1);
        }
        else if(sd[pos] == -1) {
            int t = sc[pos];
            c[pos] = t;
            if(t != 0) {
                c[pos] = t;
                d[pos] = t - 1;
                dfs(pos + 1, 1);
            }
            d[pos] = t;
            dfs(pos + 1, 0);
            if(t != 9) {
                d[pos] = t + 1;
                dfs(pos + 1, -1);
            }
        }
        else if(sc[pos] == -1) {
            int t = sd[pos];
            d[pos] = t;
            if(t != 9) {
                c[pos] = t + 1;
                dfs(pos + 1, 1);
            }
            c[pos] = t;
            dfs(pos + 1, 0);
            if(t != 0) {
                c[pos] = t - 1;
                dfs(pos + 1, -1);
            }
        }
        else {
            //printf("11  %d\n", pos);
            c[pos] = sc[pos];
            d[pos] = sd[pos];
            if(c[pos] == d[pos]) {
                dfs(pos + 1, 0);
            }
            else if(c[pos] > d[pos]) {
                dfs(pos + 1, 1);
            }
            else {
                //printf("dsafas  %d %d\n", c[pos], d[pos]);
                dfs(pos + 1, -1);
            }
        }
    }
    else if(flag == 1) {
        if(sc[pos] == -1 && sd[pos] == -1) {
            c[pos] = 0;
            d[pos] = 9;
        }
        else if(sd[pos] == -1) {
            c[pos] = sc[pos];
            d[pos] = 9;
        }
        else if(sc[pos] == -1) {
            c[pos] = 0;
            d[pos] = sd[pos];
        }
        else {
            c[pos] = sc[pos];
            d[pos] = sd[pos];
        }
        dfs(pos + 1, 1);
    }
    else {
        //printf("333 %d\n", pos);
        if(sc[pos] == -1 && sd[pos] == -1) {
            c[pos] = 9;
            d[pos] = 0;
            //printf("adsfadsfadsf  %d %d  %d\n", pos, c[pos], d[pos]);
        }
        else if(sd[pos] == -1) {
            c[pos] = sc[pos];
            d[pos] = 0;
        }
        else if(sc[pos] == -1) {
            c[pos] = 9;
            d[pos] = sd[pos];
        }
        else {
            c[pos] = sc[pos];
            d[pos] = sd[pos];
        }
        dfs(pos + 1, -1);
    }
}
vector<ll> t;

void solve() {
    ansCha = INF;
    //printf("%d\n", n);
    dfs(0, 0);
    t.clear();
    for(int i = 0; i < n; i++) {
        //printf("%I64d", ansC % 10);
        t.push_back(ansC % 10);
        ansC /= 10;
    }
    for(int i = n - 1; i >= 0; i--) {
        printf("%I64d", t[i]);
    }
    printf(" ");
    t.clear();
    for(int i = 0; i < n; i++) {
        //printf("%I64d", ansD % 10);
        t.push_back(ansD % 10);
        ansD /= 10;
    }
    for(int i = n - 1; i >= 0; i--) {
        printf("%I64d", t[i]);
    }
    printf("\n");
    //printf("%0I64d %I64d\n", ansC, ansD);
}

int main() {
    //freopen("B.txt", "r", stdin);
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("Bout.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int _ = 1; _ <= t; _++) {
        printf("Case #%d: ", _);
        scanf("%s", s);
        n = strlen(s);
        for(int i = 0; i < n; i++) {
            if(s[i] == '?') {
                sc[i] = -1;
            }
            else {
                sc[i] = s[i] - '0';
            }
        }
        scanf("%s", s);
        for(int i = 0; i < n; i++) {
            if(s[i] == '?') {
                sd[i] = -1;
            }
            else {
                sd[i] = s[i] - '0';
            }
        }
        solve();
    }
    return 0;
}
