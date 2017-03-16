#define DBG 1

#include <cstring>
#include <map>
#include <unordered_map>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> pii;

int gi() {
    int a;
    scanf("%d", &a);
    return a;
}

ll gli() {
    ll a;
    scanf("%lld", &a);
    return a;
}

#define SINGLELINE 1
char buf[150100];
char m[8][8];
void solve() {
    int l = gi();
    ll X = gli();
    int x;
    if (X > 14) {
        x = (X%4 + 12);
        if (x == 15)
            x = 11;
    } else {
        x = X;
    }
    scanf("%s", buf);
    for (int i = 1; i < x; i++)
        memcpy(&buf[i*l], buf, l);
    int curr = 'h', lvl = 0;
    for (int i = 0; i < l*x; i++) {
        curr = m[curr-'h'][buf[i]-'h'];
        if (lvl == 0 && curr == 'i') {
            lvl++;
        } else if (lvl == 1 && curr == 'k')
            lvl++;
    }
    if (lvl == 2 && curr == 'l')
        printf("YES\n");
    else
        printf("NO\n");
}

int main() {
    int t = gi();

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            int s = 0, r, ii = i, jj = j;
            if (ii > 3) {
                ii -= 4;
                s = 1-s;
            }
            if (jj > 3) {
                jj -= 4;
                s = 1-s;
            }
            if (ii == 0)
                r = jj;
            else if (jj == 0)
                r = ii;
            else if (ii == jj) {
                r = 0;
                s = 1-s;
            } else {
                if (jj == ii-1 || (ii == 1 && jj == 3))
                    s = 1-s;
                r = (6-ii-jj);
            }
            m[i][j] = 'h' + r + s*4;
            //printf("%c%c %c%c => %c%c\n", i>3?'-':' ',i>3?'d'+i:'h'+i, j>3?'-':' ',j>3?'d'+j:'h'+j, m[i][j]>'k'?'-':' ', m[i][j]>'k'?m[i][j]-4:m[i][j]);
        }

    for (int i = 1; i <= t; i++) {
        printf("Case #%d:%c", i, (SINGLELINE ? ' ' : '\n'));
        solve();
    }

    return 0;
}
