#include <cstdio>
#include <algorithm>
#include <vector>

long long gcd(long long a, long long b) {
    if(b == 0) {
        return a;
    }else if(a == 0) {
        return b;
    }else {
        if(a > b) {
            return gcd(a % b, b);
        }else {
            return gcd(b % a, a);
        }
    }
}

std::vector<long long> tab;

long long foo(long long p, long long q) {
    if(p >= q) {
        return 0;
    }
    return 1 + foo(p, q / 2);
}

long long get(long long p, long long q) {
    long long div = gcd(p, q);
    p /= div;
    q /= div;
    int count = -1;
    for(unsigned int i = 0; i < tab.size(); ++i) {
        if(q == tab[i]) {
            count = i;
        }
    }
    if(count != -1) {
        return foo(p, q);
    }
    return count;
}

int main() {
    long long p = 1;

    for(int i = 0; i <= 40; ++i) {
        tab.push_back(p);
        p *= 2;
    }
    int t;
    scanf("%d", &t);
    for(int it = 0; it < t; ++it) {
        long long p, q;
        scanf("%lld/%lld", &p, &q);
        long long res = get(p, q);
        if(res > 40) {
            res = -1;
        }
        printf("Case #%d: ", it + 1);
        if(res != -1) {
            printf("%lld\n", res);
        }else {
            printf("impossible\n");
        }
    }
}
