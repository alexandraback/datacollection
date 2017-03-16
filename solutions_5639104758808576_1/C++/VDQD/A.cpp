#include <bits/stdc++.h>
using namespace std;

int n;
char s[1111];

int main(){
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int t, cases = 0; scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        scanf("%s", s);
        int all = 0, res = 0;
        for (int i = 0; i <= n; i++) if (s[i] > '0'){
            if (all < i){
                res += i - all;
                all = i;
            }
            all += s[i] - '0';
        }
        printf("Case #%d: %d\n", ++cases, res);
    }
    return 0;
}
