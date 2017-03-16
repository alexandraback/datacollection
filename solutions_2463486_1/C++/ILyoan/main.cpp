#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

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
    vector<long long> fairSquare;
    for (long long n = 1; n*n <= 1e14; ++n) {
        if (isPalindrome(n) && isPalindrome(n*n)) {
            fairSquare.push_back(n*n);
        }
    }
    for (int t = 1; t <= T; ++t) {
        int count = 0;
        long long A, B;
        scanf("%lld%lld", &A, &B);
        for (int i = 0; i < fairSquare.size(); ++i) {
            long long n = fairSquare[i];
            count += (A <= n && n <= B);
        }
        printf("Case #%d: %d\n", t, count);
    }
    return 0;
}
