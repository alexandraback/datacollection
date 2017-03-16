#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;

#define EPSILON 0.0000005


double calcOptimalTime(double dblC, double dblF, double dblX)
{
    int nFarmCount = 0;
    double dblT;
    double dblCt;
    double dblCt2;
    double dblSum;

    dblT = 0.0;
    dblSum = 0.0;
    while (1)
    {
        dblCt = dblC / (nFarmCount * dblF + 2);
        dblCt2 = dblCt * (nFarmCount + 1) + 2.0 * dblCt / dblF;
        dblSum = dblCt2 * (nFarmCount * dblF + 2.0);
        if (dblSum >= dblX)
        {
            return dblT + dblX / (nFarmCount * dblF + 2.0);
        }

        dblT += dblCt;
        nFarmCount++;
    }

    return 0.0;
}

void process(FILE* pfIn, FILE* pfOut)
{
    int i, count;
    double dblC, dblF, dblX, dblResult;

    fscanf(pfIn, "%d", &count);
    for (i = 1; i <= count; i++)
    {
        fscanf(pfIn, "%lf %lf %lf", &dblC, &dblF, &dblX);

        dblResult = calcOptimalTime(dblC, dblF, dblX);

        fprintf(pfOut, "Case #%d: %.7lf\n", i, dblResult);
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
