#include <cstdio>
#include <cstring>
int main(){
    char s[111],ma[256];
    memset(ma,-1,sizeof ma);
    freopen("map.txt","r",stdin);
    for (char c='a';c<='z';c++){
        scanf("%s",s); ma[c]=s[1];
    }
    ma[' ']=' ';
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t; scanf("%d\n",&t);
    for (int i=1;i<=t;i++){
        gets(s);
        int n=strlen(s);
        printf("Case #%d: ",i);
        for (int i=0;i<n;i++) putchar(ma[s[i]]);
        putchar('\n');
    }
    return 0;
}
