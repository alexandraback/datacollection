#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <math.h>

#define BUFSZ 10000

char mapping[] = {
    'y',
    'h',
    'e',
    's',
    'o',
    'c',
    'v',
    'x',
    'd',
    'u',
    'i',
    'g',
    'l',
    'b',
    'k',
    'r',
    'z',
    't',
    'n',
    'w',
    'j',
    'p',
    'f',
    'm',
    'a',
    'q',
};

char charmap(char input)
{
    int val = (int) (input - 'a');
    if (input == ' ') return input;
    return mapping[val];
}

int main(int argc, char *argv[])
{
    FILE *fp;
    char strBuf[BUFSZ+1];
    char *token, *subtoken, *sptr1, *sptr2;
    int T;       // loops
    int N;
    int newpos;
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

        char *letter = token;

        subtoken = strtok_r(NULL, " ", &sptr2);
        char *myturn = subtoken;

        printf("Case #%d: ", i+1);

        while (*letter)
        {
            printf("%c", charmap(*letter));
            letter++;
        }
        printf("\n");
    }


    fclose(fp);
    return 0;
}
