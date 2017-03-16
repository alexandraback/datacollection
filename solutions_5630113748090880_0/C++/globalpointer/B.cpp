#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxh = 2505;

int n, a, count[maxh];

void clear() {
    std::fill(count, count+maxh, 0);
}

int main() {
    int testcases; scanf("%d", &testcases);
    for (int testnum = 1; testnum <= testcases; testnum++) {
        printf("Case #%d: ", testnum);
        clear();
        scanf("%d", &n);
        for (int i = 0; i < n+n-1; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &a);
                count[a]++;
            }
        }
        for (int i = 0; i < maxh; i++) if (count[i] & 1) printf("%d ", i);
        printf("\n");
    }
}

