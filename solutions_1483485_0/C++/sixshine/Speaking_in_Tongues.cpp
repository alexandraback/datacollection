#include <stdio.h>
#include <cstring>
#include <ctype.h>

int main() {
    int T;
    char List[27]="yhesocvxduiglbkrztnwjpfmaq";
    scanf("%d\n", &T);
    for (int i = 1; i <= T; ++i) {
        char Str[102] = "";
        gets(Str);
        int Len = strlen(Str);
        for(int j=0;j<Len;++j)
        {
            if (islower(Str[j]))
            {
                Str[j]=List[Str[j]-'a'];
            }
        }
        printf("Case #%d: %s\n", i,Str);
    }
    return 0;
}

