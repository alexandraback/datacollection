#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
char ch[101];
int n;
bool a[27];
int main() {
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int T,l,ans;
    scanf("%d",&T);
    memset(a,0,sizeof(a));
    a[0] = a['e'-'a'] = a['i'-'a'] = a['o'-'a'] = a['u'-'a'] = 1;
    for (int kase = 1;kase <= T; kase++ ) {
        scanf("%s%d",ch,&n);
        l = strlen(ch); ans = 0;
        for (int i = 1;i <= l; i++) {
            for (int j = 0;j <= l-i; j++) {
                int tot = 0,big = 0;
                for (int k = j;k <= j+i-1; k++) {
                    if (a[ch[k]-'a']) {
                       tot  = 0;
                    } else tot++;
                    if (tot > big) big = tot;
                }
                if (big >= n) ans++;
            }
        } 
        printf("Case #%d: %d\n",kase,ans);
    }
    return 0;
}
