#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <math.h>

#define BUFSZ 10000

int quadrant(float a, float amax, float b, float bmax, float max)
{
    int sum = 0;
    int i, j;
    for (i = 0;; i++)
    {
        for (j = 0;; j++)
        {
            float dist = (a+i*amax)*(a+i*amax) + (b+j*bmax)*(b+j*bmax);
            if (dist <= (max*max/4))
            {
//                printf("%f, %f\n", a+i*amax, b+j*bmax);
                sum++;
            }
            else break;
        }
        if (j==0) break;
    }
    return sum;
}

int main(int argc, char *argv[])
{
    FILE *fp;
    char strBuf[BUFSZ+1];
    char *token, *subtoken, *sptr1, *sptr2;
    int T;       // loops
    int H, W, D;
    int i, j;
    int x, y;
    float left, right, up, down;

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
        int total = 0;
        fgets(strBuf, BUFSZ, fp);
        token = strtok_r(strBuf, "\r\n", &sptr1);

        subtoken = strtok_r(token, " ", &sptr2);
        H = atoi(subtoken);

        subtoken = strtok_r(NULL, " ", &sptr2);
        W = atoi(subtoken);

        subtoken = strtok_r(NULL, " ", &sptr2);
        D = atoi(subtoken);

        y = 0;
        int found = 0;
        for (j=0; j<H; j++)
        {
            x = 0;
            fgets(strBuf, BUFSZ, fp);
            token = strtok_r(strBuf, "\r\n", &sptr1);

            /* find the X */
            while (*token)
            {
                if ((*token++) == 'X')
                {
                    found = 1;
                    break;
                }
                x++;
            }
            if (found)
            {
                while ((j++)<(H-1)) fgets(strBuf, BUFSZ, fp);
                break;
            }
            y++;
        }
        left = (float)x-0.5;
        right = ((float)W-x)-1.5;
        up = (float)y-0.5;
        down = ((float)H-y)-1.5;

        if ((left * 2) <= D) total++;
        if ((right * 2) <= D) total++;
        if ((up * 2) <= D) total++;
        if ((down * 2) <= D) total++;


        W-=2;
        H-=2;
        total += quadrant(right, W, up, H, D);
        total += quadrant(right, W, down, H, D);
        total += quadrant(left, W, up, H, D);
        total += quadrant(left, W, down, H, D);


        printf("Case #%d: %d\n", i+1, total);
    }


    fclose(fp);
    return 0;
}
