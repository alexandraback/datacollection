#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <iostream>
#include <queue>

using namespace std;
long long n, m, a[1010], ti;

bool cmp(long long x, long long y){return x > y;}

int getdeg(long long x)
{
    int tmp = 0;
    while (x) {
        x /= 10ll;
        tmp++;
    }
    return tmp;
}

int main(){
    FILE* FIN;
    FILE* FOUT;
    FIN = fopen("/Users/Djy/Documents/4test/A-small-attempt0.in", "r");
    FOUT = fopen("/Users/Djy/Documents/4test/A-small-attempt0.out", "w");

    int T;
    long long pow[30];
    memset(pow, 0, sizeof(pow));
    long long ca, cb, cc, cd;
    ca = cb = 9ll, cc = cd = 0ll;
    pow[0] = 0ll, pow[1] = 1ll, pow[2] = 10ll;
    
    for (int i = 3; i <= 20; i++) {
        pow[i] = pow[i - 1] + ca + cb + 1ll;
        cc = ca * 10ll + 9ll;
        ca = cb, cb = cc;
    }
    ca = cb = cc = cd = 0ll;
    
    fscanf(FIN, "%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        
        long long n;
        fscanf(FIN, "%lld", &n);
        n--;
        if (n <= 9 && n >= 0) {
            fprintf(FOUT, "Case #%d: %lld\n", cas, n + 1);
            continue;
        }
        
        int deg = getdeg(n);
        ca = (deg + 1ll) >> 1ll;
        
        cb = 0ll, cd = 1ll;
        for (int i = 0; i < ca; i++) {//get half
            cb += (n % 10ll) * cd;
            n /= 10ll;
            cd *= 10ll;
        }
        
        cc = 0ll;
        while (n > 0) {//remain
            cc *= 10ll;
            cc += n % 10ll;
            n /= 10ll;
        }
        
        if (cc != 1ll) fprintf(FOUT, "Case #%d: %lld\n", cas, cb + cc + pow[deg] + 1);//reverse
        else fprintf(FOUT, "Case #%d: %lld\n", cas, cb + cc + pow[deg]);
    }
    return 0;
}