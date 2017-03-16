#include <cstdio>
#include <cstring>
char a[111];
int m;
bool go(char x) {
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
        return false;
    else
        return true;
}
int main() {
    int t;
    scanf("%d",&t);
    for (int tc=1; tc<=t; tc++) {
        int ans = 0;
        char a[111];
        int n;
        scanf("%s %d\n",a,&n);
        int m = strlen(a);
        for (int i=0; i<m; i++) {
            for (int j=i; j<m; j++) {
                if (j-i+1 >= n) {
                    int cur = 0;
                    bool ok = false;
                    for (int k=i; k<=j; k++) {
                        if (go(a[k])) cur ++;
                        else cur = 0;
                        if (cur >= n) ok = true;
                    }
                    if (ok) ans ++;
                }
            }
        }
        printf("Case #%d: %d\n",tc,ans);
    }
    return 0;
}
