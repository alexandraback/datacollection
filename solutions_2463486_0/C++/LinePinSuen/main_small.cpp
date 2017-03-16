#include <stdio.h>
#include <string.h>
#include <math.h>

bool is_fair(int number)
{
    bool fair = true;
    char string[5];
    sprintf(string, "%d", number);
    int string_length = strlen(string);
    for (int i = 0; i < (string_length >> 1); i++)
    {
        fair = fair && (string[i] == string[string_length - i - 1]);
    }
    return fair;
}

int main(void)
{
    // preparation: sqrt(1000) ~= 31.622...
    bool fair[32];
    char string[5];
    for (int i = 0; i < 32; i++)
    {
        fair[i] = is_fair(i) && is_fair(i * i);
//        printf("%s%d(%c)%s", i == 0 ? "" : " ", i, fair[i] ? 'T' : 'F', i == 31 ? "\n" : "");
    }

    int t = 0;

    // t: # of cases
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int A = 0;
        int B = 0;
        scanf("%d %d", &A, &B);

        // table lookup
        int sqrt_a = (int)ceil(sqrt(A));
        int sqrt_b = (int)floor(sqrt(B));
        int fair_count = 0;
        for (int j = sqrt_a; j <= sqrt_b; j++)
        {
            if (fair[j])
            {
                fair_count++;
            }
        }

        // output
//        printf("%d, %d\n", sqrt_a, sqrt_b);
        printf("Case #%d: %d\n", i + 1, fair_count);
    }

    return 0;
}
