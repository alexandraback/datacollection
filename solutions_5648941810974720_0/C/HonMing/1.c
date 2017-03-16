#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(char* a, char*b )
{
    return *a - *b;
}

int main()
{
    int i,j,k;
    int ii,jj,kk;
    int now;
    int max;
    int res;
    char line[3000];
    int alpha[30];
    char ans[1000];

    scanf("%d", &kk);

    for(ii = 1; ii <= kk; ii++)
    {
        j=0;
        memset(ans, 0, sizeof(ans));
        memset(alpha, 0, sizeof(alpha));
        scanf("%s", line);

        for(i = 0; i < strlen(line); i++)
        {
            alpha[line[i]-'A']++;
        }

        while(alpha['Z'-'A'] > 0)
        {
            ans[j++] = '0';
            alpha['Z'-'A']--;
            alpha['E'-'A']--;
            alpha['R'-'A']--;
            alpha['O'-'A']--;
        }
        while(alpha['X'-'A'] > 0)
        {
            ans[j++] = '6';
            alpha['S'-'A']--;
            alpha['I'-'A']--;
            alpha['X'-'A']--;
        }
        while(alpha['W'-'A'] > 0)
        {
            ans[j++] = '2';
            alpha['T'-'A']--;
            alpha['W'-'A']--;
            alpha['O'-'A']--;
        }
        while(alpha['G'-'A'] > 0)
        {
            ans[j++] = '8';
            alpha['E'-'A']--;
            alpha['I'-'A']--;
            alpha['G'-'A']--;
            alpha['H'-'A']--;
            alpha['T'-'A']--;
        }
       while(alpha['T'-'A'] > 0)
        {
            ans[j++] = '3';
            alpha['T'-'A']--;
            alpha['H'-'A']--;
            alpha['R'-'A']--;
            alpha['E'-'A']--;
            alpha['E'-'A']--;
        }
       while(alpha['S'-'A'] > 0)
        {
            ans[j++] = '7';
            alpha['S'-'A']--;
            alpha['E'-'A']--;
            alpha['V'-'A']--;
            alpha['E'-'A']--;
            alpha['N'-'A']--;
        }
       while(alpha['V'-'A'] > 0)
        {
            ans[j++] = '5';
            alpha['F'-'A']--;
            alpha['I'-'A']--;
            alpha['V'-'A']--;
            alpha['E'-'A']--;
        }
     while(alpha['F'-'A'] > 0)
        {
            ans[j++] = '4';
            alpha['F'-'A']--;
            alpha['O'-'A']--;
            alpha['U'-'A']--;
            alpha['R'-'A']--;
        }
     while(alpha['I'-'A'] > 0)
        {
            ans[j++] = '9';
            alpha['N'-'A']--;
            alpha['I'-'A']--;
            alpha['N'-'A']--;
            alpha['E'-'A']--;
        }
     while(alpha['O'-'A'] > 0)
        {
            ans[j++] = '1';
            alpha['O'-'A']--;
            alpha['N'-'A']--;
            alpha['E'-'A']--;
        }
        qsort(ans, strlen(ans), sizeof(char), cmp);

        printf("Case #%d: %s\n", ii, ans);
    }
}
