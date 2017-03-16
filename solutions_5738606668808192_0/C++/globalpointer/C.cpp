#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int n, j, k;

void clear() {
}
void print(int i) {
    if (j) {
        printf("11");
        for (int x = 0; x < k; x++) {
            if (i & (1<<x)) printf("11");
            else printf("00");
        }
        printf("11 ");
        for (int x = 3; x <= 11; x++) printf("%d%c", x, " \n"[x==11]);
        j--;
    }
}

int main() {
    int testcases; scanf("%d", &testcases);
    for (int testnum = 1; testnum <= testcases; testnum++) {
        printf("Case #%d:\n", testnum);
        clear();
        scanf("%d%d", &n, &j);
        k = n/2-2;
        for (int i = 0; i < 1<<k; i++) {
            print(i);
        }
    }
}

