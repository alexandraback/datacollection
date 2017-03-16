/*
Author: LotK
LANG: C++
*/

#include <cstdio>
#include <cstring>

char *pch;
char str[1010];
char s[105][105];
char s2[105][105];
char a[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
int main() {
    int t, tt, i, j, k;
    scanf("%d ", &tt);
    for(t=0 ; t<tt ; t++) {
        gets(str);

        printf("Case #%d: ", t+1);
        for(i=0 ; i<strlen(str); i++) {
            if(str[i]>96 && str[i]<123) {
                printf("%c", a[str[i]-97]);
            }
            else if(str[i]>64 && str[i]<91) {
                printf("%c", a[str[i]-65]-32);
            }
            else printf(" ");
        }
        printf("\n");


        /*

        i = 0;
        pch = strtok (str," ,.-");
        while (pch != NULL)
        {
            strcpy(s[i], pch);
            i++;
            //printf ("%s\n",pch);
            pch = strtok (NULL, " ,.-");
        }
        for(j=0 ; j<i ; j++) {
            printf("%s\n", s[j]);
        }
        */

        /*
        gets(str);


        i = 0;
        pch = strtok (str," ,.-");
        while (pch != NULL)
        {
            strcpy(s2[i], pch);
            i++;
            //printf ("%s\n",pch);
            pch = strtok (NULL, " ,.-");
        }
        for(j=0 ; j<i ; j++) {
            printf("%s\n", s2[j]);
        }
        for(j=0 ; j<i ; j++) {
            for(k=0 ; k<strlen(s[j]) ; k++) {
                printf("           %d\n", s[j][k]-97);
                a[s[j][k]-97] = s2[j][k];
            }
        }
        for(j=0 ; j<26 ; j++) {
            printf("'%c', ", a[j]);
        }

        */
    }

}
