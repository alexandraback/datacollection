#include <cstdio>
#include <cstring>

int t, T;
char s[1005], ans[1005];

void solve() {
    ans[0] = s[0];
    int i, j, len = strlen(s);
    for ( i = 1 ; i < len ; ++i ) {
        if ( s[i] >= ans[0] ) {
            for ( j = i ; j >= 1 ; --j ) {
                ans[j] = ans[j-1];
            }
            ans[0] = s[i];
        }
        else ans[i] = s[i];
        //printf("%s\n",ans);
    }
    ans[len] = '\0';
}

int main() {
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    scanf("%d",&T);
    for ( t = 1 ; t <= T ; ++t ) {
        scanf("%s",s);
        solve();
        printf("Case #%d: %s\n",t,ans);
    }
    return 0;
}
