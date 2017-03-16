#include<iostream>
#include <cstdio>
#include <map>
using namespace std;
map<int, int> sums;
int num[20];
int n,T;

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        sums.clear();
        printf("Case #%d:\n", t);
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &num[i]);
        
        int sum, bitp = -1;
        for (int i = 0; i < (1<<n); i++) {
            sum = 0;
            int mask = i;
            while (mask) {
                int bit = mask & -mask;
                int ind = __builtin_ctz(bit);
                mask -= bit;
                sum += num[ind];
            }
            
            if (sums.find(sum) != sums.end()) {
                bitp = i;
                break;
            }
            sums[sum]=i;
        }
        
        if (bitp == -1) printf("impossible\n");
        else {
            int mask = bitp;
            while (mask) {
                int bit = mask & -mask;
                int ind = __builtin_ctz(bit);
                mask -= bit;
                printf("%d",num[ind]);
                if (mask) printf(" ");
                else printf("\n");
            }
            mask = sums[sum];
            while (mask) {
                int bit = mask & -mask;
                int ind = __builtin_ctz(bit);
                mask -= bit;
                printf("%d",num[ind]);
                if (mask) printf(" ");
                else printf("\n");
            }
        }
    }    
}
