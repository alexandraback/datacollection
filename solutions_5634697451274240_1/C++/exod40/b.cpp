#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

char buf[128];
int n;
void read() {
    scanf("%s", buf);
    n = strlen(buf);
}

void solve() {
    char sign = buf[0];
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (buf[i] != sign) {
            ans ++;
        }
        sign = buf[i];
    }
    if (buf[n-1] == '-') ans++;
    //if(n) ans += sign == '-';
    printf ("%d\n", ans);
}

int main() {
    int cases;

    scanf("%d", &cases);
    for (int i=1; i<=cases; i++) {
        read();
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}

