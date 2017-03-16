#include <iostream>
using namespace std;

int main() {
    int n;
    char str[1003];
    int k;
    scanf("%d", &n);
    int t = 1, i, ans;
    while(t<=n) {
        scanf("%d %s", &k, str);
        int num = str[0]-'0';
        ans = 0;
        for (i=1; i<=k; i++) {
            if (num<i) {
                num++;
                ans++;
            }
            num+=str[i]-'0';
        }
        printf("Case #%d: %d\n", t, ans);
        t++;
    }
    return 0;
}
