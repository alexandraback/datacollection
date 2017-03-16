#include <cstdio>
#include <bitset>
#include <limits>
#include <cstdlib>
using namespace std;
int solve(int n) {
    if(n == 0)
        return 0;
    bitset<10> digits;
    for(int i = 1; ; i++) {
        if(i > numeric_limits<int>::max() / n) {
            exit(1);
        }
        for(int x = i * n; x; x /= 10)
            digits[x % 10] = true;
        if(digits.all())
            return i * n;
    }
}
int main() {
    /*for(int i = 0; i <= 1000000; i++)
        printf("%d %d\n", i, solve(i));*/

    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        int n;
        scanf("%d", &n);
        int ans = solve(n);
        if(ans <= 0)
            printf("Case #%d: INSOMNIA\n", i);
        else
            printf("Case #%d: %d\n", i, ans);
    }
}

