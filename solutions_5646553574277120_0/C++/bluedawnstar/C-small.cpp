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

int gC;
int gD;
int gV;

int gP[101];

int gT[100];

int solveSmall(void)
{
    memset(gT, 0, sizeof(gT));

    bool loop = true;

    int res = 0;

    do {
        int m = 1 << gD;
        for (int i = 1; i < m; i++) {
            int n = 0;
            for (int j = 0; j < gD; j++) {
                if (i & (1 << j))
                    n += gP[j];
            }
            if (n > 0 && n <= gV)
                gT[n]++;
        }

        loop = false;
        for (int i = 1; i <= gV; i++) {
            if (gT[i] == 0) {
                res++;
                gP[gD++] = i;
                loop = true;
                break;
            }
        }
    } while (loop);

    return res;
}

void process(FILE* pfIn, FILE* pfOut)
{
    int tn, T;

    fscanf(pfIn, "%d", &T);
    for (tn = 1; tn <= T; tn++)
    {
        fscanf(pfIn, "%d %d %d", &gC, &gD, &gV);
        for (int i = 0; i < gD; i++)
            fscanf(pfIn, "%d", &gP[i]);
        sort(gP, gP + gD);
        fprintf(pfOut, "Case #%d: %d\n", tn, solveSmall());
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
