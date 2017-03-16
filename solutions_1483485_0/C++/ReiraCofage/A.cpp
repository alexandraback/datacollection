#include <cstdio>
#include <cstring>

using namespace std;

int T, C=1;
char s[1024];
             //abcdefghijklmnopqrstuvwxyz
char mapa[] = "yhesocvxduiglbkrztnwjpfmaq";

int main() {

    for(scanf("%d\n",&T);T--;) {
        fgets(s,1024,stdin);
        printf("Case #%d: ",C++);
        for (int i=0;s[i];i++) if ('a' <= s[i] and s[i] <= 'z')
                printf("%c",mapa[ s[i]-'a' ]);
            else
                printf("%c",s[i]);
    }

    return 0;
}
