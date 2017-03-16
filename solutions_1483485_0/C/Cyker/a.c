#include <stdio.h>
#include <math.h>
#include <string.h>

int T;
char map[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
char buf[200];
int i, j, k;

char * calculate()
{
    k = 0;
    while (buf[k]) {
        if (buf[k] != ' ')
            buf[k] = map[buf[k] - 'a'];
        k++;
    }
    return buf;
}

int main()
{
    scanf("%d\n", &T);
    for (i = 0; i < T; i++) {
        memset(buf, 0, sizeof(buf));
        gets(buf);
        printf("Case #%d: %s\n", i+1, calculate());
    }
}
