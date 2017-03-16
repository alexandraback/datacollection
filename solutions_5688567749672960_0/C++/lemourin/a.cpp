#include <cstdio>
#include <algorithm>
#define scanf(args...) (scanf(args) ? : 0)
typedef long long int LL;

LL rev(LL a, LL b) {
    return a == 0 ? b : rev(a/10, b*10+a%10);
}

LL reverse(LL a) {
    return rev(a, 0);
}

LL half(LL a) {
    LL p10 = 1, res = 0, n = a;
    while (p10*p10 < a) {
        res += p10*(n%10);
        n /= 10;
        p10 *= 10;
    }
    return res;
}

LL f1(LL n, LL p10) {
    LL value1 = half(n), value2 = reverse(n-half(n));
    LL result = value1+value2-1;
    LL current = p10;
    current += value1;
    if (current == n)
        return result;
    if (current != reverse(current)) {
        result++;
        current = reverse(current);
    }
    current += value2-1;
    if (current != reverse(current))
        result++;
    return result;
}

LL f2(LL n, LL p10) {
    LL revn = reverse(n);
    LL value1 = half(revn), value2 = reverse(revn-half(revn));
    LL result = value1+value2-1;
    LL current = p10;
    current += value1;
    if (current == n)
        return result;
    if (current != reverse(current)) {
        result++;
        current = reverse(current);
    }
    current += value2-1;
    if (current == n)
        return result;
    else
        return result+1;
}

LL solve(LL n) {
    if (n <= 10)
        return n;
    if (n%10 == 0)
        return solve(n-1)+1;

    LL p10 = 1;
    while (10*p10 <= n)
        p10 *= 10;

    LL r = solve(p10-1)+1;
    return r+std::min(f1(n, p10), f2(n, p10));
}

int main() {
    int t;
    scanf("%d", &t);

    for (int test=1; test<=t; test++) {
        LL n;
        scanf("%Ld", &n);
        
        printf("Case #%d: %Ld\n", test, solve(n));
    }
}
