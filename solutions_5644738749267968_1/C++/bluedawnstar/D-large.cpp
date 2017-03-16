#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<double>  DataVectorT;

int getDecWarWins(DataVectorT& vecNaomi, DataVectorT& vecKen)
{
    DataVectorT::iterator itNaomi, itNaomiEnd;
    DataVectorT::iterator itKen, itKenEnd;

    itNaomi = vecNaomi.begin();
    itNaomiEnd = vecNaomi.end();
    itKenEnd = vecKen.end();

    int win = 0;

    for (itKen = vecKen.begin(); itKen != itKenEnd; itKen++)
    {
        itNaomi = upper_bound(itNaomi, itNaomiEnd, *itKen);
        if (itNaomi == itNaomiEnd)
            break;
        ++itNaomi;
        win++;
    }

    return win;
}

int getWarWins(DataVectorT& vecNaomi, DataVectorT& vecKen)
{
    DataVectorT::iterator itNaomi, itNaomiEnd;
    DataVectorT::iterator itKen, itKenEnd;

    itNaomiEnd = vecNaomi.end();
    itKen = vecKen.begin();
    itKenEnd = vecKen.end();

    int lose = 0;

    for (itNaomi = vecNaomi.begin(); itNaomi != itNaomiEnd; itNaomi++)
    {
        itKen = upper_bound(itKen, itKenEnd, *itNaomi);
        if (itKen == itKenEnd)
            break;
        ++itKen;
        lose++;
    }

    return vecNaomi.size() - lose;
}

void process(FILE* pfIn, FILE* pfOut)
{
    int i, j, n, count, decwar, war;
    double dblV;

    DataVectorT vecNaomi;
    DataVectorT vecKen;

    vecNaomi.reserve(2000);
    vecKen.reserve(2000);

    fscanf(pfIn, "%d", &count);
    for (i = 1; i <= count; i++)
    {
        fscanf(pfIn, "%d", &n);
        
        vecNaomi.clear();
        vecKen.clear();

        for (j = 0; j < n; j++)
        {
            fscanf(pfIn, "%lf", &dblV);
            vecNaomi.push_back(dblV);
        }
        for (j = 0; j < n; j++)
        {
            fscanf(pfIn, "%lf", &dblV);
            vecKen.push_back(dblV);
        }

        sort(vecNaomi.begin(), vecNaomi.end());
        sort(vecKen.begin(), vecKen.end());

        decwar = getDecWarWins(vecNaomi, vecKen);
        war = getWarWins(vecNaomi, vecKen);

        fprintf(pfOut, "Case #%d: %d %d\n", i, decwar, war);
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
