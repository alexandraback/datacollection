#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <map>

void
get_cols(char *buf, unsigned long *vals)
{
    char *ptr = buf;
    char *p2;
    int c = 0;
    while ((p2 = strchr(ptr, ' ')) != NULL)
    {
        *p2 = '\0';
        unsigned long val = atol(ptr);
        vals[c] = val;
        c++;
        ptr = p2+1;
    }

    double val = atof(ptr);
    vals[c] = val;
}

int
main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <input.txt>\n", argv[0]);
        return 0;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f)
    {
        printf("Couldn't open file\n");
        return 0;
    }

    char buf[10001];
    fgets(buf, 10001, f);
    int num_tests = atoi(buf);

    //printf("Got %d tests\n", num_tests);

    for (int test_num = 0; test_num < num_tests; test_num++)
    {
        fgets(buf, 10001, f);
        unsigned long vals[3];
        get_cols(buf, vals);

        unsigned long A = vals[0];
        unsigned long B = vals[1];
        
        unsigned long M = A;
        if (B < A)
            M = B;

        unsigned long K = vals[2];

        unsigned long count = 0;
        for (unsigned long i = 0; i < A; i++)
            for (unsigned long j = 0; j < B; j++)
                if ((i & j) < K)
                    count++;

        printf("Case #%d: %lu\n", test_num+1, count);
        
    }

    fclose(f);

    return 0;
}
