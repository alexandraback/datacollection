#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

bool isPalindrome(long long n) {
    char buffer[20];
    sprintf(buffer, "%lld", n);
    int a = 0;
    int b = strlen(buffer) - 1;
    while (a <= b) {
        if (buffer[a++] != buffer[b--]) return false;
    }
    return true;
}
int main() 
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        long long A, B;
        scanf("%lld%lld", &A, &B);
        long long n = ceil(sqrt(A));
        int count = 0;
        while (n * n <= B) {
            count += (isPalindrome(n) && isPalindrome(n*n));
            n += 1;
        }
        printf("Case #%d: %d\n", t, count);
    }
    return 0;
}
