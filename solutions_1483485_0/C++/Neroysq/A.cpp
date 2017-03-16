#include <stdio.h>
#include <string.h>
const int nmax = 100, cmax = 26;

char st[nmax + 18];
int n, trans[cmax + 18], t;

int main()
{
//    freopen("A.in", "r", stdin);
//    freopen("A.out", "w", stdout);
    trans[0] = 'y';
    trans[1] = 'h';
    trans[2] = 'e';
    trans[3] = 's';
    trans[4] = 'o';
    trans[5] = 'c';
    trans[6] = 'v';
    trans[7] = 'x';
    trans[8] = 'd';
    trans[9] = 'u';
    trans[10] = 'i';
    trans[11] = 'g';
    trans[12] = 'l';
    trans[13] = 'b';
    trans[14] = 'k';
    trans[15] = 'r';
    trans[16] = 'z';
    trans[17] = 't';
    trans[18] = 'n';
    trans[19] = 'w';
    trans[20] = 'j';
    trans[21] = 'p';
    trans[22] = 'f';
    trans[23] = 'm';
    trans[24] = 'a';
    trans[25] = 'q';
    scanf("%d\n", &t);
    for (int cases = 1; cases <= t; ++cases) {
	gets(st + 1);
	n = strlen(st + 1);
	printf("Case #%d: ", cases);
	for (int i = 1; i <= n; ++i)
	    printf("%c", st[i] == ' ' ? ' ' : trans[st[i] - 'a']);
	printf("\n");
    }
    return 0;
}

