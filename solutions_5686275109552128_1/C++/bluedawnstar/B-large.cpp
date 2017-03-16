#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

#define IT                  iterator
#define VEC(T)              vector<T >
#define VIT(T)              vector<T >::IT

typedef long long           I64;
typedef unsigned long long  UI64;

using namespace std;

int gD;
int gP[1001];

int calcTime(int minSize)
{
    int t = 0;
    for (int i = 0; i < gD; i++)
        t += (gP[i] - 1) / minSize;

    return t + minSize;
}

void process(FILE* pfIn, FILE* pfOut)
{
    int i, count;

    fscanf(pfIn, "%d", &count);
    for (i = 1; i <= count; i++)
    {
        fscanf(pfIn, "%d", &gD);

        for (int j = 0; j < gD; j++)
            fscanf(pfIn, "%d", &gP[j]);
        sort(gP, gP + gD);

        int maxT = gP[gD - 1];
        int minT = maxT;
        for (int i = 1; i <= maxT; i++)
        {
            int t = calcTime(i);
            if (minT > t)
                minT = t;
        }

        fprintf(pfOut, "Case #%d: %d\n", i, minT);
    }
}

//-----------------------------------------------------------------------------

void process(const char* pcszInFile, const char* pcszOutFile)
{
    FILE* pfIn = fopen(pcszInFile, "rt");
    if (pfIn == NULL)
    {
        printf("file not found! \"%s\"\n", pcszInFile);
        exit(-2);
    }

    FILE* pfOut = fopen(pcszOutFile, "wt");
    if (pfOut == NULL)
    {
        printf("can't create file! \"%s\"\n", pcszOutFile);
        exit(-3);
    }

    process(pfIn, pfOut);

    fclose(pfIn);
    fclose(pfOut);
}

void main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("Usage : %s <input_file> <output_file>\n", argv[0]);
        exit(-1);
    }

    process(argv[1], argv[2]);
}
