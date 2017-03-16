#include <string.h>
#include <stdio.h>

#define Smax 4001

int order[]={0, 6, 4, 7, 5, 2, 1, 3, 8, 9};
int digits_map[10][28] = {{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}} ;

int check (int *array, int *sub_array, int length)
{
    int i;
    for (i = 0; i < length; ++i) {
        if (sub_array[i] > array[i])
            return 0;
    }
    return 1;
}

void solve(char *string)
{
    int len, i;
    int letters[27];
    int digits[10];

    memset (letters, 0, sizeof(int) * 27);
    memset (digits, 0, sizeof(int) * 10);
    len = strlen(string);
    for (i = 0; i < len; ++i)
    {
        letters[string[i] - 'A'] ++;
    }


    for (i = 0; i < 10; ++i) {
        while (check(letters, digits_map[order[i]], 27)) {
            digits[order[i]]++;
            int j;

            for (j = 0; j < 27; ++j) {
                letters[j] -= digits_map[order[i]][j];
            }
        }
    }

    for (i = 0; i < 10; ++i)
    {
        while (digits[i] > 0) {
            printf("%d", i);
            digits[i]--;
        }
    }
}

int main()
{
    int t, i;
    FILE *f;

    f = fopen("digits.in", "r");
    fscanf(f, "%d\n", &t);

    for (i = 0 ; i < t; ++i) {
        char string[Smax];
        fgets (string, Smax, f);
        printf("CASE #%d: ", i + 1);
//        printf("{");
        solve(string);
        printf("\n");
    }

    return 0;
}
