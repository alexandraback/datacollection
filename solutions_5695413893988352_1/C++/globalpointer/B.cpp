#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 20;
const ll inf = 2e18;

int n;
char s[maxn], t[maxn], ss[maxn], tt[maxn];
std::pair<ll, std::pair<ll,ll>> best = {inf,{0ll,0ll}};

void clear() {
    best = {inf,{0ll,0ll}};
}
ll getll(char *p) {
    ll x = 0;
    for (int i = 0; i < n; i++) x = x*10 + p[i] - '0';
    return x;
}
void fixSBigger() {
    strcpy(ss, s); strcpy(tt, t);
    for (int i = 0; i < n; i++) if (ss[i] == '?') ss[i] = '0';
    for (int i = 0; i < n; i++) if (tt[i] == '?') tt[i] = '9';
    ll sll = getll(ss), tll = getll(tt);
    domin(best, {std::abs(sll-tll), {sll, tll}});
}
void fixTBigger() {
    strcpy(ss, s); strcpy(tt, t);
    for (int i = 0; i < n; i++) if (ss[i] == '?') ss[i] = '9';
    for (int i = 0; i < n; i++) if (tt[i] == '?') tt[i] = '0';
    ll sll = getll(ss), tll = getll(tt);
    domin(best, {std::abs(sll-tll), {sll, tll}});
}

int main() {
    int testcases; scanf("%d", &testcases);
    for (int testnum = 1; testnum <= testcases; testnum++) {
        scanf(" %s %s", s, t);
        n = strlen(s);
        bool rip = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == '?' && t[i] == '?') {
                s[i] = '0'; t[i] = '1';
                fixTBigger();
                s[i] = '1'; t[i] = '0';
                fixSBigger();
                s[i] = '0'; t[i] = '0';
            } else if (s[i] == '?') {
                if (t[i] < '9') {
                    s[i] = t[i] + 1;
                    fixSBigger();
                }
                if (t[i] > '0') {
                    s[i] = t[i] - 1;
                    fixTBigger();
                }
                s[i] = t[i];
            } else if (t[i] == '?') {
                if (s[i] < '9') {
                    t[i] = s[i] + 1;
                    fixTBigger();
                }
                if (s[i] > '0') {
                    t[i] = s[i] - 1;
                    fixSBigger();
                }
                t[i] = s[i];
            } else {
                if (s[i] != t[i]) {
                    if (s[i] > t[i]) fixSBigger();
                    else fixTBigger();
                    rip = true;
                    break;
                }
            }
        }
        fixSBigger();
        printf("Case #%d: %0*lld %0*lld\n", testnum, n, best.second.first, n, best.second.second);
        clear();
    }
}

