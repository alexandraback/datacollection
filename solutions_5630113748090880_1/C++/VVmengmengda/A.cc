#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int num[2505];

int main(){
    freopen("B-large.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int t, n, i, j, cas = 1, a;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        memset(num, 0, sizeof(num));
        for(i=0;i<n*2-1;i++){
            for(j=0;j<n;j++){
                scanf("%d", &a);
                num[a]++;
            }
        }
        printf("Case #%d:", cas++);
        for(i=1;i<=2500;i++){
             if(num[i]%2) printf(" %d", i);
        }
        printf("\n");
    }
    return 0;
}
