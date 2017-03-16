#include <cstdio>
#include <cassert>

#define ASSERT_N 32
#define ASSERT_J 500

int T, N, J;
int j_count = 0;
char buffer[ASSERT_N + 1];

void find_jamcoins(int index)
{
    if (j_count == ASSERT_J)
        return;

    if (index == 0)
        find_jamcoins(2);
    else if (index == ASSERT_N - 2)
    {
        printf("%s", buffer);
        for (int base = 2; base <= 10; base++)
            printf(" %d", base + 1);
        printf("\n");

        j_count++;
    }
    else
    {
        buffer[index] = buffer[index + 1] = '0';
        find_jamcoins(index + 2);

        if (j_count == ASSERT_J)
            return;

        buffer[index] = buffer[index + 1] = '1';
        find_jamcoins(index + 2);
    }
}

int main(int argc, char **argv)
{
    scanf("%d %d %d", &T, &N, &J);
    assert(T == 1 && N == ASSERT_N && J == ASSERT_J);
    printf("Case #1:\n");

    buffer[0] = buffer[1] = buffer[ASSERT_N - 2] = buffer[ASSERT_N - 1] = '1';
    find_jamcoins(0);

    return 0;
}
