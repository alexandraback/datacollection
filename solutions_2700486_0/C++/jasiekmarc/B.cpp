#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

long long C(int n, int k) {
    int i;
    long long p;
    for(i=1, p=1; i <= k; i ++)
        p *= (n - (long long)i + 1) / (long long)i;
    return p;
}

/* Putting randomly k balls into two cups,
 * what is the probability, that the left will
 * contain at least a balls?

 * In other words. Given a k-digit binary number
 * what is the probability of it having at least
 * a ones? */
long double pascprob(int k, int a) {
    long long up = C(k, a);
    long long p = up;
    for(int i = a + 1; i <= k; i ++) {
        p *= (k - (long long)i + 1) / (long long)i;
        up += p;
    }
    long double down = pow(2.0, k);
    return (long double)up / down;
}

long double testcase() {
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);
    x = abs(x);
    int level = (x + y) / 2;
    n -= level * (2 * level - 1);  // n is number of diamonds on current level
    if(x == 0)
        return (n >= 4 * level + 1) ? 1.0 : 0.0;
    if(n <= 0)
        return 0.0;
    int c = 2 * level;

    int off = max(n - c, 0);
    n -= 2 * off;
    c -= off;
    y -= off;
    if(y < 0)
        return 1.0;
    return pascprob(n, y+1);
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i ++) {
        printf("Case #%d: %Lf\n", i, testcase());
    }
}