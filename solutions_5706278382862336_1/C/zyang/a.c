#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long common(long long x, long long y)
{
    if (y == 0)
        return x;
    else
        return common(y, x % y);
}

int impossible(long long x)
{
    while (x != 1)
        if (x % 2 == 1)
            return 1;
        else
            x /= 2;

    return 0;
}

int calc(long long x, long long y)
{
    if (x == y)
        return 1;

    int ans = 0;
    while (x < y)
    {
        x *= 2;
        ans++;
    }

    return ans;
}

void exec(long long x, long long y)
{
    long long factor = common(x, y);
    x /= factor;
    y /= factor;

    if (x > y || impossible(y) == 1)
        printf("impossible\n");
    else
        printf("%i\n", calc(x, y));
}

int main()
{
    int t;
    char buffer[256];
    fgets(buffer, 256, stdin);
    t = atoi(buffer);

    for (int i = 0; i < t; i++)
    {
        fgets(buffer, 256, stdin);
        
        long long p = 0, q = 0, ptr = 0, len = strlen(buffer) - 1;
        while (buffer[ptr] != '/')
        {
            p = p * 10 + (buffer[ptr] - '0');
            ptr++;
        }

        ptr++;
        while (ptr < len)
        {
            q = q * 10 + (buffer[ptr] - '0');
            ptr++;
        }

        printf("Case #%i: ", i+1);
        exec(p, q);
    }
}
