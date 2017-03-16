#include <bits/stdc++.h>

using namespace std;

long long odwroc(int w) {
    long long ret = 0;
    while(w >= 1) {
        ret *= 10;
        ret += w % 10;
        w /= 10;
    }
    return ret;
}
int lengt(long long w) {
    int ret = 0;
    while(w >= 1) {
        ret++;
        w /= 10;
    }
    return ret;
}
long long n; 
int t;
long long pot[20];
int main() {
    pot[0] = 1;
    for(int i = 1; i <= 15; i++) {
        pot[i] = pot[i - 1] * 10;
    }
    scanf("%d", &t);
    for(int test = 1; test <= t; test++) {
        printf("Case #%d: ", test);
        scanf("%lld", &n);
        int l = lengt(n);
        if(n <= 10) {
            printf("%lld\n", n);
            continue;
        }
        long long wynik = 0;
        for(int i = 0; i <= 15; i++) {
            if(i + 1 > l) break;
            if(i + 1 == l) {
                if(pot[i] == n) {
                    break;
                }
                if(n % 10 == 0) {
                    wynik++;
                    n--;
                }
                    if(l % 2 == 0) {
                        wynik += min(n - pot[i], odwroc(n / pot[(i + 1) / 2]) + (n % pot[(i + 1) / 2] - 1) + 1);
                    } else {
                        wynik += min(n - pot[i], min(odwroc(n / pot[(i + 1) / 2]) + (n % pot[(i + 1) / 2] - 1), odwroc(n / pot[(i + 1) / 2 + 1]) + (n % pot[(i + 1) / 2 + 1] - 1)) + 1);
                    }
                
                break;
            }
            if((i + 1) % 2 == 0) {
                wynik += 2 * (pot[(i + 1) / 2] - 1) + 1; 
            } else {
                wynik += (pot[(i + 1) / 2] - 1 + pot[(i + 1) / 2 + 1] -1) + 1;
            }
            
        } 
        printf("%lld\n", wynik);
    }
    return 0;
}