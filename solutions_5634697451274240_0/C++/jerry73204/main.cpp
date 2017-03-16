#include <cstdio>

char pancake[102];

int main(int argc, char **argv)
{
    int T;
    scanf("%d", &T);
    getchar();

    for (int t = 1; t <= T; t++)
    {
        fgets(pancake, sizeof(pancake), stdin);

        char prev_symbol = pancake[0];
        int interval_count = 1;
        char *p;

        for (p = pancake + 1; *p != '\n'; p++)
        {
            if (*p != prev_symbol)
            {
                interval_count++;
                prev_symbol = *p;
            }
        }

        printf("Case #%d: %d\n", t, (*(p - 1) == '-') ? interval_count : interval_count - 1);
    }

    return 0;
}
