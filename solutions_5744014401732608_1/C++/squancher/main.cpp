#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int d[1000];

long long pow2(int p) {
    long long r = 1;
    
    for (int i = 0; i < p; i++)
        r *= 2;
    
    return r;
}

void decomp(long long n) {
    for (int i = 0; n > 0; i++) {
        d[i] = n % 2;
        n /= 2;
    }
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    
    int tn = 0;
    
    scanf("%d\n", &tn);
    
    for (int t = 1; t <= tn; t++) {
        for (int i = 0; i < 100; i++) {
            d[i] = 0;
        }
        
        long long m;
        int b;
        
        scanf("%d%lld", &b, &m);
        
        long long max = pow2(b - 2);
        
        printf("Case #%d: ", t);
        
        if (m > max) {
            puts("IMPOSSIBLE");
            continue;
        }
        
        puts("POSSIBLE");
        
        if (m == max) {
            for (int i = 1; i <= b; i++) {
                for (int j = 1; j <= b; j++) {
                    if (i < j)
                        putchar('1');
                    else
                        putchar('0');
                }
                putchar('\n');
            }
        }
        
        else {
            decomp(m);
            
            putchar('0');
            
            
            for (int j = b - 3; j >= 0; j--) {
                if (d[j] == 1)
                    putchar('1');
                else
                    putchar('0');
            }
            
            putchar('0');
            
            putchar('\n');
            
            for (int i = 2; i <= b; i++) {
                for (int j = 1; j <= b; j++) {
                    if (i < j)
                        putchar('1');
                    else
                        putchar('0');
                }
                putchar('\n');
            }
        }
    }
    
    return 0;
}