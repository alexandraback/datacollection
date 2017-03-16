#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
char map[] = "yhesocvxduiglbkrztnwjpfmaq";
char str[121];
int T;

int main() {
    freopen("test.out","w",stdout);
    scanf("%d\n",&T);
    for (int i = 1; i <= T; i++) {
        memset(str, '\0' ,sizeof(str));
        gets(str);
        int len = strlen(str);
        for (int j = 0; j < len; j++) {
            if (str[j] != ' ') str[j] = map[str[j] - 'a'];
        }
        printf("Case #%d: %s\n",i,str);
    }
}
