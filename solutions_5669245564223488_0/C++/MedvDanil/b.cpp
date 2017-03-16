#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
char a[102][102];
int p[102];
int c[128];
void solve(){
    int n, i;
    int res = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%s", a[i]);
        a[i][std::unique(a[i],strlen(a[i])+a[i])-a[i]] = 0;
    }
    int nfct=1;
    for(i = 0; i < n; i++)
        p[i] = i, nfct*=i+1;
    memset(c, -1, sizeof(c));
    while(nfct--){
        bool valid = 1;
        char lastc = 0;
        for(i = 0; i < n && valid; i++){
            for(int j = 0; a[p[i]][j]; j++){
                if(c[a[p[i]][j]]!=nfct)
                    c[a[p[i]][j]] = nfct;
                else if(a[p[i]][j] != lastc)
                    valid=0;
                lastc = a[p[i]][j];
            }
        }
        res += valid;
        std::next_permutation(p,p+n);
    }
    printf("%d\n", res);
}
int main(void){
//#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
//#endif
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
