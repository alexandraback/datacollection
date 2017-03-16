#include <cstdio>
#include <cstring>

const char *a = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv qz";
const char *b = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up zq";

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int map[26];
    for(int i = 0;i < 26;i ++) map[i] = -1;
    for(int i = 0;i < strlen(a);i ++) map[a[i]-'a'] = b[i]-'a';
    
    int t;
    scanf("%d", &t);
    char buf[1024];
    gets(buf);
    
    for(int i = 0;i < t;i ++) {
        gets(buf);
        for(int j = 0;j < strlen(buf);j ++) buf[j] = map[buf[j]-'a'] + 'a';
        printf("Case #%d: %s\n", i+1, buf);
    }
    return 0;
}
