#include <cstdio>
using namespace std;
int solve() {
    char c = getchar();
    int ans = 0;
    for(char d; (d = getchar()) == '+' || d == '-'; )
        if(c != d)
            ans++, c = d;
    if(c == '-')
        ans++;
    return ans;
}
int main() {
    int t;
    scanf("%d\n", &t);
    for(int i = 1; i <= t; i++) {
        printf("Case #%d: %d\n", i, solve());
    }
}

