#include <stdio.h>
#include <string.h>

bool all_visited(int digit[10]) {
    for (int i=0;i<10;i++) {
        if (!digit[i])
            return false;
    }
    return true;
}
void minus(int *alpha, char a, int val)
{
    alpha[a-'A'] -= val;
}
void count(int *digit, int idx, int *alpha, char c, char *str) {
    digit[idx] = alpha[c-'A'];
    int val = alpha[c-'A'];
    for (int i=0;i<strlen(str);i++)
        minus(alpha, str[i], val);
}
int main()
{
    int T;
    char S[2010];
    scanf("%d", &T);
    for (int Ti=1;Ti<=T;Ti++) {
        printf("Case #%d: ", Ti);
        scanf("%s\n", S);
        int alpha[26];
        for (int i=0;i<26;i++) 
            alpha[i] = 0;
        for (int i=0;i<strlen(S);i++)
            alpha[S[i]-'A']++;

        int digit[10];
        for (int i=0;i<10;i++)
            digit[i]=0;
/*
        for (int i=0;i<26;i++)
            if (alpha[i]>0)
                printf("%c: %d\n", 'A' + i, alpha[i]);
*/
        //"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE
                                                   //              //               // 
        //ZERO
//        digit[0] = alpha['Z'-'A'];
//        minus(alpha, 'Z', 'Z');
//        minus(alpha, 'E', 'Z');
//        minus(alpha, 'R', 'Z');
//        minus(alpha, 'O', 'Z');
        count(digit, 0, alpha, 'Z', "ZERO");
        //TWO
        count(digit, 2, alpha, 'W', "TWO");
        //SIX
        count(digit, 6, alpha, 'X', "SIX");
        //EIGHT
        count(digit, 8, alpha, 'G', "EIGHT");
        //FOUR
        count(digit, 4, alpha, 'U', "FOUR");
        //THREE
        count(digit, 3, alpha, 'R', "THREE");
        //ONE
        count(digit, 1, alpha, 'O', "ONE");
        //FIVE
        count(digit, 5, alpha, 'F', "FIVE");
        //SEVEN
        count(digit, 7, alpha, 'V', "SEVEN");
        //NINE
        count(digit, 9, alpha, 'I', "NINE");
        for(int i=0;i<10;i++)
            for (int j=0;j<digit[i];j++)
                printf("%d", i);
        printf("\n");
    }
    return 0;
}


