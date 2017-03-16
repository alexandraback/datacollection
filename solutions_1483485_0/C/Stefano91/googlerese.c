#include <stdio.h>
#include <string.h>

#define MAX 256
#define MAXSTRING 120
#define VERBOSE 0

int main() {
    FILE *finput,*foutput,*fexinput,*fexoutput;
    int T,i,j;
    char c,v;
    char f[MAX],invf[MAX];
    char string[MAXSTRING],string2[MAXSTRING];

    for (i=0;i<MAX;i++)
        f[i] = invf[i] = '?';

    fexinput = fopen("exampleinput.txt","r");
    fexoutput = fopen("exampleoutput.txt","r");
    finput = fopen("input.txt","r");
    foutput = fopen("output.txt","w");


    f[(int) ' '] = ' ';
    f[(int) 'z'] = 'q';

    fscanf(fexinput, "%d\n", &T);

    for (i=1;i<=T;i++) {
        fscanf(fexinput, "\n%[^\n]s",&string);
        fscanf(fexoutput, "\nCase #%d: %[^\n]s",&j,&string2);

        for (j=0;j<strlen(string);j++) {

            if (f[(int)string[j]] == '?') {
                f[(int)string[j]] = string2[j];
                invf[(int)string2[j]] = string[j];
            }
        }

    }

    for (c='a';c<='z';c++) {
        if (f[(int)c] == '?') {
            for (v='a';v<='z';v++) {
                if (invf[(int)v] == '?') {
                    f[(int)c] = v;
                    invf[(int)v] = c;
                }
            }
        }
    }

    if (VERBOSE)
        for (c='a';c<='z';c++) {
            printf("\n%c %c",c,f[(int)c]);
        }





    fscanf(finput, "%d\n", &T);

    for (i=1;i<=T;i++) {
        fscanf(finput, "\n%[^\n]s",&string);

        for (j=0;j<strlen(string);j++) {
            string2[j] = f[(int)string[j]];
        }
        string2[j] = '\0';

        if (VERBOSE)
            printf("\n => Case #%d: %s", i, string2);

        fprintf(foutput, "Case #%d: %s", i, string2);

        if (i<T)
            fprintf(foutput, "\n");
    }

    fclose(fexinput);
    fclose(fexoutput);
    fclose(finput);
    fclose(foutput);

    return 0;
}
