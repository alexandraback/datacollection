#include<stdio.h>
#include<cstring>
using namespace std;
int main() {
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);

    int T;
    scanf("%d",&T);
    for (int cas=1; cas<=T; cas++) {
        char s[110];
        scanf("%s",s);
        int len=strlen(s),ans=0;
        for (int i=1; i<len; i++) {
            if (s[i]!=s[i-1]) ans++;
        }
        if (s[len-1]=='-') ans++;
        printf("Case #%d: %d\n",cas,ans);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
