#include <cstdio>

int main(){
    freopen("A-small-attempt5.in","r",stdin);
    freopen("output","w",stdout);
    int t;
    scanf("%d",&t);
    for (int i=1; i<=t; i++) {
        int n;
        char s[1234];
        scanf("%d %s",&n,s);
        int p = 0, r = 0;
        for (int j=0; j<n+1; j++) {
            while(p < j){
                r++;
                p++;
            }
            p += (s[j] - '0');
        }
        printf("Case #%d: %d",i,r);
        if(i != t) puts("");
    }
}