#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//               abcdefghijklmnopqrstuvwxyz
char mapp[27] = "yhesocvxduiglbkrztnwjpfmaq";

int main()
{
    int aa, nn, i, n;
    char buffer[1000];
    gets(buffer);
    nn = atoi(buffer);
    for (aa = 1; aa <= nn; ++aa) {
        gets(buffer);
        n = strlen(buffer);
        for ( i = 0; i < n; i++ ) {
            if (buffer[i] < 'a' || buffer[i] > 'z' ) continue;
            buffer[i] = mapp[buffer[i]-'a'];
        }
        printf("Case #%d: %s\n",aa,buffer);
    }
    return 0;
}

