#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 1005;

int n;
char s[maxn];
std::deque<char> d;

void clear() {
    d.clear();
}

int main() {
    int testcases; scanf("%d", &testcases);
    for (int testnum = 1; testnum <= testcases; testnum++) {
        scanf(" %s", s);
        n = strlen(s);
        for (int i = 0; i < n; i++) {
            if (d.empty() || s[i] >= d.front()) d.push_front(s[i]);
            else d.push_back(s[i]);
        }
        printf("Case #%d: ", testnum);
        for (int i = 0; i < sz(d); i++) printf("%c", d[i]);
        printf("\n");
        clear();
    }
}

