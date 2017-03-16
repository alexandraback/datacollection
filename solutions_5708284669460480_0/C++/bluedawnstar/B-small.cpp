#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define IT                  iterator
#define VEC(T)              vector<T >
#define VIT(T)              vector<T >::IT

typedef long long           I64;
typedef unsigned long long  UI64;

using namespace std;

int gKL;
int gLL;
int gS;

char gK[102];
char gL[102];

int gKP[30];
int gLP[30];

char gTmp[300];

int gPN;
int gPP[823543 * 2];

int getRCount()
{
    for (int i = 0; i < gS; i += gLL)
        strcpy(&gTmp[i], gL);
    gTmp[gS] = '\0';

    int res = 0;
    for (int i = 0; i < gS - gLL; i++) {
        if (gTmp[i] == gL[0])
            res += strncmp(gTmp + i, gL, gLL) == 0;
    }

    return res;
}

int count()
{
    int res = 0;
    for (int i = 0; i <= gS - gLL; i++) {
        if (gTmp[i] == gL[0])
            res += strncmp(gTmp + i, gL, gLL) == 0;
    }

    return res;
}

void perm(int n)
{
    if (n >= gS) {
        gPP[gPN++] = count();
        return;
    }

    for (int i = 0; i < gKL; i++) {
        gTmp[n] = gK[i];
        perm(n + 1);
    }
}

double solve(void)
{
    gPN = 0;

    memset(gKP, 0, sizeof(gKP));
    memset(gLP, 0, sizeof(gLP));

    for (int i = 0; i < gKL; i++)
        gKP[gK[i] - 'A']++;

    for (int i = 0; i < gLL; i++) {
        if (gKP[gL[i] - 'A'] == 0)
            return 0.0;
        gLP[gL[i] - 'A']++;
    }

    perm(0);

    int cnt = 0, mx = 0;
    for (int i = 0; i < gPN; i++) {
        mx = max(mx, gPP[i]);
        cnt += gPP[i];
    }

    //if (cnt == gPN)
    //    return 0.0;

    return (double)(gPN * mx - cnt) / (double)gPN;
}

void process(FILE* pfIn, FILE* pfOut)
{
    int tn, T;

    fscanf(pfIn, "%d", &T);
    for (tn = 1; tn <= T; tn++)
    {
        fscanf(pfIn, "%d %d %d", &gKL, &gLL, &gS);
        fscanf(pfIn, "%s %s", gK, gL);

        fprintf(pfOut, "Case #%d: %f\n", tn, solve());
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
