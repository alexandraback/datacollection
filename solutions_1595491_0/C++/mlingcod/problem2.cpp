#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <math.h>

#define BUFSZ 10000

int main(int argc, char *argv[])
{
    FILE *fp;
    char strBuf[BUFSZ+1];
    char *token, *subtoken, *sptr1, *sptr2;
    int T;       // loops
    int N, S, p, t;
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
        N = atoi(subtoken);

        subtoken = strtok_r(NULL, " ", &sptr2);
        S = atoi(subtoken);

        subtoken = strtok_r(NULL, " ", &sptr2);
        p = atoi(subtoken);

        /* say p is 5.  scores are
         * 11  5 3 3
         * 12  5 4 3
         * ----------  scores above 13 don't need to be surprising
         * 13  5 4 4
         * 14  5 5 4
         * 15  5 5 5
         * 16  6 5 5
         * 17  6 6 5
         * 18  6 6 6
         * 19  6 6 7
         */
        int tally = 0;
        for (j=0; j<N; j++)
        {
            subtoken = strtok_r(NULL, " ", &sptr2);
            t = atoi(subtoken);
            if (p == 0) tally++;
            else if (t >= (p*3 - 2)) tally++;
            else if ((p >=2 ) && (t >= (p*3 - 4)) && (S >= 1))
            {
                S--;
                tally++;
            }
        }

        printf("Case #%d: %d\n", i+1, tally);
    }


    fclose(fp);
    return 0;
}
