#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>

using namespace std;

int T;
long long pangkat[20],i;

long long reverse(long long x) {
    long long res = 0;
    while (x > 0) {
        res = (10LL*res) + (x % 10LL);
        x /= 10LL;
    }
    return res;
}

int digit(long long x) {
    int res = 0;
    if (x == 0) return 1;
    while (x > 0) {
        ++res;
        x /= 10LL;
    }
    return res;
}

int main() {
    pangkat[0] = 1;
    for (int l=1;l<=15;++l) {
        pangkat[l] = 10LL*pangkat[l-1];
    }
    
    scanf("%d",&T);
    for (int l=1;l<=T;++l) {
        scanf("%I64d",&i);
        int cara = 0;
        if (i <= 10) {
            cara = i;
        } else {
            int panjang = digit(i);
            cara = 10;
            long long sasar = i;

            if (i % 10 == 0) {
                --sasar;
                ++cara;
                panjang = digit(sasar);
            }            
            
            for (int j=2;j<panjang;++j) {
                long long z = pangkat[j]-1LL;
                cara += (z % pangkat[j/2]) + (reverse(z) % pangkat[(j+1)/2]) + 1;
            }
            
            if (sasar / pangkat[(panjang+1) / 2] == pangkat[panjang / 2-1]) {
                cara += (sasar % pangkat[(panjang+1)/2]);
            } else {
                cara += (reverse(sasar) % pangkat[panjang/2]);
                cara += 1;
                cara += ((sasar-1) % pangkat[(panjang+1)/2]);
            }
        }
        
        printf("Case #%d: %d\n",l,cara);
    }
    return 0;
}
