#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int v[2555];
int main() {
    int T, cas = 0;
    int n, x;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        memset(v, 0, sizeof(v));
        for(int i = 0; i < 2 * n - 1; i++) {
            for(int j = 0 ; j < n; j++) {
                scanf("%d", &x);
                v[x] ++;
            }
        }
        printf("Case #%d:", ++cas);
        for(int i = 0; i <= 2500; i++) {
            if(v[i] %2 ==  1) printf(" %d", i); 
        }
        printf("\n");
    }
    return 0;
}
