#include <stdio.h>
#include <string.h>

int T;
char str[1100];

void calc(int from, int to)
{
    if (from >= to ) {
        return ;
    }
    int max = to - 1;
    for (int i = to-1; i >= from ; i--) {
        if (str[i] > str[max]) {
            max = i;
        }
    }
    putchar(str[max]);
    calc(from, max);
    for (int i = max+1; i < to; i++) {
        putchar(str[i]);
    }
}

int main()
{
    scanf("%d", &T);
    for (int z = 1; z <= T; z++) {
        scanf("%s", str);
        printf("Case #%d: ", z);
        int len = strlen(str);
        calc(0, len);
        putchar('\n');
    }

	return 0;
}

