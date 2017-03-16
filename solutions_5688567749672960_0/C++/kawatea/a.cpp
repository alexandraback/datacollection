#include <cstdio>

using namespace std;

long long get(long long n)
{
    int c = 0, f = 0, i, j;
    long long m = n, x = 1, sum = 0, sum2 = -1, ans = 0;
    int a[20];
    
    if (n < 10) return n;
    
    for (i = 0; n > 0; i++, c++) {
        a[i] = n % 10;
        n /= 10;
    }
    
    for (i = 0; i < c / 2; i++) {
        if (a[i] != 0) break;
    }
    
    if (i == c / 2) f = 1;
    
    for (i = 0; i < c / 2; i++) {
        sum += a[i] * x;
        sum2 += a[c - i - 1] * x;
        x *= 10;
    }
    
    if (c % 2 == 1) sum += a[c / 2] * x;
    
    if (f == 1) {
        if (sum2 > 0) {
            return get(m - 1) + 1;
        } else {
            ans += sum;
        }
    } else {
        if (sum2 == 0) {
            ans += sum;
        } else {
            ans += sum + sum2 + 1;
        }
    }
    
    for (i = 0; i < c - 1; i++) {
        n *= 10;
        n += 9;
    }
    
    ans += get(n) + 1;
    
    return ans;
}

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        long long n;
        
        scanf("%lld", &n);
        
        printf("Case #%d: %lld\n", i + 1, get(n));
    }
    
    return 0;
}
