#include <stdio.h>
#include <string.h>

int T, c[26];
char S[2002], num[10][6] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int main()
{
    scanf("%d\n",&T);
    int i,k,j,check, ans[10];
    for(k=1; k<=T; k++){
        gets(S);
        for(i=0;i<10;i++)
            ans[i] = 0;
        for(i=0;i<26;i++){
            c[i] = 0;
        }
        for(i=0;i<strlen(S);i++){
            c[S[i]-'A'] += 1;
        }
        printf("Case #%d: ",k);
        // case 0;
        ans[0] = c[25];
        c['O'-'A'] -= c[25];
        c['R'-'A'] -= c[25];
        c['E'-'A'] -= c[25];
        c[25] = 0;

        //case: 6
        ans[6] = c['X'-'A'];
        c['S'-'A'] -= c['X'-'A'];
        c['I'-'A'] -= c['X'-'A'];
        c['X'-'A'] = 0;

        // case: 2
        ans[2] = c['W'-'A'];
        c['O'-'A'] -= c['W'-'A'];
        c['T'-'A'] -= c['W'-'A'];
        c['W'-'A'] = 0;

        //case: 8
        ans[8] = c['G'-'A'];
        c['E'-'A'] -= c['G'-'A'];
        c['I'-'A'] -= c['G'-'A'];
        c['H'-'A'] -= c['G'-'A'];
        c['T'-'A'] -= c['G'-'A'];
        c['G'-'A'] = 0;

        //case: 7
        ans[7] = c['S'-'A'];
        c['E'-'A'] -= 2*c['S'-'A'];
        c['V'-'A'] -= c['S'-'A'];
        c['N'-'A'] -= c['S'-'A'];
        c['S'-'A'] = 0;

        //case: 5
        ans[5] = c['V'-'A'];
        c['F'-'A'] -= c['V'-'A'];
        c['I'-'A'] -= c['V'-'A'];
        c['E'-'A'] -= c['V'-'A'];
        c['V'-'A'] = 0;

        //case: 4
        ans[4] = c['F'-'A'];
        c['O'-'A'] -= c['F'-'A'];
        c['U'-'A'] -= c['F'-'A'];
        c['R'-'A'] -= c['F'-'A'];
        c['F'-'A'] = 0;

        ans[1] = c['O'-'A'];
        ans[3] = c['H'-'A'];
        ans[9] = c['I'-'A'];

        for(i=0;i<10;i++){
            for(j=0;j<ans[i];j++)
                printf("%d",i);
        }
        printf("\n");
    }

    return 0;
}
