#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool tb[256];

const int maxn = 1000000 + 5;

char s[maxn];
int l[maxn];

long long solve() {
    memset(l, 0, sizeof(l));
    
    int L;
    scanf("%s %d",s,&L);
    long long ans = strlen(s);
    ans = ans * (ans - 1) / 2 + ans;
    int last = 0;
    int n = 0;
    for (const char* p = s; *p; ++p) {
        if (tb[*p]) {
            last = 0;
        } else {
            last ++;
        }
        l[n++] = last;
        // cout << "l[" << n-1 <<"]=" << last << endl;
    }

    int last_begin = -1;
    for (int i = 0; i < n; ++i) {
        if (l[i] >= L) {
            last_begin = i - L + 1;
        }
        if (i > last_begin) {
            ans -= (long long)(i - last_begin);
        }
    }
    return ans;
}

int main() {
    freopen("A-large.in", "r", stdin);
    for (int i = 0; i < 256; ++i) tb[i] = false;
    tb['a'] = true;
    tb['e'] = true;
    tb['i'] = true;
    tb['o'] = true;
    tb['u'] = true;
    
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }
    return 0;
}
