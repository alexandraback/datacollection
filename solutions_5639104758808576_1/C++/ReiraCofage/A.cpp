#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T, C=1, n;
char s[1024];

int main() {

    for(scanf("%d",&T);T--;) {
        printf("Case #%d: ",C++);
        scanf("%d %s",&n,s);
        int empeh = 0;
        int resp = 0;
        for (int i=0;i<=n;i++) {
            int qi = s[i]-'0';
            if (qi==0) continue;
            int novo = max(i-empeh,0);
            empeh += novo;
            resp += novo;
            empeh += qi;
        }
        printf("%d\n",resp);
    }

    return 0;
}
