#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(void){
    int t, n, ys = 0, sum[2000];
    char s[2000];
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        scanf("%s", s);
        int ans = 0, sum = s[0]-48;
        for (int i = 1; i<=n; i++){
           int x = s[i]-48;
           if (i>sum){
               ans += i-sum;
               sum = i;
           }
           sum += x;
        }
        printf("Case #%d: %d\n", ++ys, ans);
    }
    return 0;
}
