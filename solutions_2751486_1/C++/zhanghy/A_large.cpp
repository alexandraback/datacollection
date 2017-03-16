#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
char ch[1000010];
bool a[27];
long long ans;
int main() {
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int T,l,n;
    scanf("%d",&T);
    memset(a,0,sizeof(a));
    a['a'-'a'] = a['e'-'a'] = a['o'-'a'] = a['u'-'a'] = a['i'-'a'] = 1;
    for (int kase = 1;kase <= T; kase++) {
        scanf("%s%d",ch,&n);
        l = strlen(ch);
        int st = 0,len = 0; ans = 0;
        bool flag = false;
        for (int j = 0;j < l; j++ ) {
            if (a[ch[j]-'a']) {
               len = 0;
            }else {
                  len++;
                  if (len >= n){ st = j-n+1; flag = true; }
            }
            if (flag) {
               ans += st+1;
            }
        }
        printf("Case #%d: ",kase);
        cout<<ans<<endl;
    }
    return 0;
}
