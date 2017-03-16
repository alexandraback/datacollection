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

int gR, gC, gW;

int solve()
{
    int add = (gC % gW) == 0 ? -1 : 0;
    return (gR - 1) * (gC / gW) + (gC / gW + gW + add); 
}

void process(FILE* pfIn, FILE* pfOut)
{
    int tn, T;

    fscanf(pfIn, "%d", &T);
    for (tn = 1; tn <= T; tn++)
    {
        fscanf(pfIn, "%d %d %d", &gR, &gC, &gW);
        fprintf(pfOut, "Case #%d: %d\n", tn, solve());
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
