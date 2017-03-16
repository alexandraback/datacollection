#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int n;
char s[105];
std::vector<int> v;

void clear() {
    v.clear();
}

int main() {
    int testcases; scanf("%d", &testcases);
    for (int testnum = 1; testnum <= testcases; testnum++) {
        printf("Case #%d: ", testnum);
        clear();
        scanf(" %s", s);
        n = strlen(s);
        for (int i = 0; i < n; i++) {
            if (!i || s[i] != s[i-1]) v.pb(s[i]);
        }
        if (v.back() == '+') v.pop_back();
        printf("%d", sz(v));
        printf("\n");
    }
}

