#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 2005, maxk = 26;

int n, c[maxk], d[maxk];
char s[maxn];

void clear() {
    std::fill(c, c+maxk, 0);
    std::fill(d, d+maxk, 0);
}

int main() {
    int testcases; scanf("%d", &testcases);
    for (int testnum = 1; testnum <= testcases; testnum++) {
        scanf(" %s", s);
        n = strlen(s);
        for (int i = 0; i < n; i++) {
            c[s[i] - 'A']++;
        }
        d[0] = c['Z' - 'A'];
        d[2] = c['W' - 'A'];
        d[4] = c['U' - 'A'];
        d[6] = c['X' - 'A'];
        d[8] = c['G' - 'A'];
        d[3] = c['H' - 'A'] - d[8];
        d[5] = c['F' - 'A'] - d[4];
        d[7] = c['V' - 'A'] - d[5];
        d[9] = c['I' - 'A'] - d[8] - d[6] - d[5];
        d[1] = c['N' - 'A'] - 2*d[9] - d[7];
        std::string t;
        for (int i = 0; i < 10; i++) for (int j = 0; j < d[i]; j++)
            t += '0' + i;
        printf("Case #%d: %s\n", testnum, t.c_str());
        clear();
    }
}

