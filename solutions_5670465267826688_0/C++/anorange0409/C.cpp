#include <iostream>
#include <cstdio>
using namespace std;

int hehe[4][4] = {
    1,2,3,4,
    2,-1,4,-3,
    3,-4,-1,2,
    4,3,-2,-1
};

int n,m;
string s,p;

int calc(int a, int b) {
    int k = 1;
    if (a < 0) { a = -a; k = -k;}
    if (b < 0) { b = -b; k = -k;}
    return k * hehe[a-1][b-1];
}

int count(string s, int x, int y) {
    int re = 1;
    for (int i = x; i <= y; i++) {
        int k = 0;
        if (s[i] == 'i') k = 2;
        if (s[i] == 'j') k = 3;
        if (s[i] == 'k') k = 4;
        re = calc(re, k);
    }
    return re;
}

int main() {
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small.out","w",stdout);
    int T;
    cin >> T;
    for (int o = 1; o <= T; o++) {
        cin >> n >> m;
        cin >> s;
        p = "";
        n *= m;
        while(m--) p+=s;
        if (count(p, 0, n - 1) != -1) {
            printf("Case #%d: NO\n", o);
            continue;
        }
        int i , j;
        for (i = 0; i < n; i++)
            if (count(p, 0, i) == 2) break;
        if (i == n) {
            printf("Case #%d: NO\n", o);
            continue;
        }
        for (j = i + 1; j < n; j++)
            if (count(p, j, n - 1) == 4) break;
        if (j == n) {
            printf("Case #%d: NO\n", o);
            continue;
        }
        printf("Case #%d: YES\n", o);
    }
}
