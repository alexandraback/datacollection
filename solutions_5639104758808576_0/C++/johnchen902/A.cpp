#include <cstdio>
using namespace std;

char a[1002];

int solve(int s) {
    int ans = 0, sum = a[0] - '0';
    for(int i = 1; i <= s; i++) {
        if(sum < i) {
            ans += i - sum;
            sum = i;
        }
        sum += a[i] - '0';
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        int s;
        scanf("%d %s", &s, a);
        printf("Case #%d: %d\n", i, solve(s));
    }
}
