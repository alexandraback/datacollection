#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int n;
bool seen[10];

void clear() {
    std::fill(seen, seen+10, false);
}
void add(int i) {
    while (i) {
        seen[i%10] = true;
        i /= 10;
    }
}
bool done() {
    for (int i = 0; i < 10; i++) if (!seen[i]) return false;
    return true;
}

int main() {
    int testcases; scanf("%d", &testcases);
    for (int testnum = 1; testnum <= testcases; testnum++) {
        printf("Case #%d: ", testnum);
        clear();
        scanf("%d", &n);
        if (n) {
            int i;
            for (i = 1; !done(); i++) {
                add(i*n);
            }
            printf("%d", (i-1)*n);
        } else printf("INSOMNIA");
        printf("\n");
    }
}

