#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <math.h>

#define BUFSZ 10000

int rot(int num, int letters, int max)
{
    int rem, j, k;
    int stored[6];
    int orig = num;
    int tally = 0;


    for (k = 1; k < letters; k++)
    {
        int powwa = letters - 1;
        rem = num % 10;
        while (powwa--) rem = rem * 10;
        num = (num / 10) + rem;
        if ((orig < num) && (num <= max))
        {
            /* candidate for adding */
            for (j=0; j<tally; j++)
            {
                /* already added */
                if (num == stored[j]) break;
            }
            if (j == tally) stored[tally++] = num;
        }
    }
    return tally;
}

int main(int argc, char *argv[])
{
    FILE *fp;
    char strBuf[BUFSZ+1];
    char *token, *subtoken, *sptr1, *sptr2;
    int T;       // loops
    int A, B;
    int n, m;
    int i, j;

    if (argc != 2)
    {
        exit(-1);
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Usage: file is no good\n");
        exit(-1);
    }


    fgets(strBuf, BUFSZ, fp);
    token = strtok_r(strBuf, "\r\n", &sptr1);
    T = atoi(token);

    for (i=0; i<T; i++)
    {
        fgets(strBuf, BUFSZ, fp);
        token = strtok_r(strBuf, "\r\n", &sptr1);

        subtoken = strtok_r(token, " ", &sptr2);
        A = atoi(subtoken);

        subtoken = strtok_r(NULL, " ", &sptr2);
        B = atoi(subtoken);

        int letters = 0;
        while (*(subtoken++)) letters++;

        /* start with n = A, if rotation of n <= B, increase tally */
        int tally = 0;
        if (letters > 1)
        {
            for (j=A; j<B; j++)
            {
                tally += rot(j, letters, B);
            }
        }

        printf("Case #%d: %d\n", i+1, tally);
    }


    fclose(fp);
    return 0;
}
